import sys

def num(s):
    if s[0] == "-":
        return 0x100-num(s[1:])
    if s[0] == "$":
        return int(s[1:], 16)
    if s[0] == "%":
        return int(s[1:], 2)
    return int(s)
def num2(s):
    if s[0] == "-":
        return 0x10000-num2(s[1:])
    if s[0] == "$":
        return int(s[1:], 16)
    if s[0] == "%":
        return int(s[1:], 2)
    return int(s)

def comp(i, addr, labels=None):
    if i == "":
        return []
    arg = "".join(i.split(",")).split(" ")
    noarg = {
        "reset": 0,
        "syscall": 5,
        "ret": 10,
        "nop": 15,
        "sez": 0x90,
        "sec": 0x95,
        "clz": 0x9a,
        "clc": 0x9f,
        "not a": 0xa0, "not b": 0xa5, "not c": 0xaa, "not d": 0xaf,
        "pop xh": 0x80, "pop xl": 0x85, "push xh": 0x8a, "push xl": 0x8f,
        "push x": 0xfa, "pop x": 0xfb,
        "mov x, th": 0xf8, "mov x, tl": 0xf9,
        "setpindirs x": 0xfc,
        "setpins x": 0xfd,
        "getpindirs x": 0xfe,
        "getpins x": 0xff,
        "swapxlxh": 0x6f,
    }
    if i in noarg:
        return [noarg[i]]
    reg = {"a": 0, "b": 1, "c": 2, "d": 3}
    regl = {"al": 0, "bl": 1, "cl": 2, "dl": 3}
    vreg = {"v10": 0, "v32": 1, "v54": 2, "v76": 3, "v98": 4, "vba": 5, "vdc": 6, "vfe": 7}
    onereg = {
        "inc": 0x10,
        "dec": 0x14,
        "jump": 0x60,
        "call": 0x64,
        "shl": 0xd0,
        "shr": 0xd4,
        "rol": 0xd8,
        "ror": 0xdc
    }
    if arg[0] in onereg and arg[1] in reg:
        return [onereg[arg[0]]+reg[arg[1]]]
    if arg[0] == "mov" and arg[1] == "sp":
        return [0xe8 + reg[arg[1]]]
    if arg[0] == "mov" and arg[2] == "sp":
        return [0xec + reg[arg[1]]]
    if arg[0] == "mov" and arg[1] == "x":
        return [0xe0 + reg[arg[2]]]
    if arg[0] == "mov" and arg[2] == "x":
        return [0xe4 + reg[arg[1]]]
    if arg[0] == "mov" and arg[1] in vreg and arg[2] == "x":
        return [0xf0 + vreg[arg[1]]]
    tworeg = {
        "mov": 0,
        "cmp": 0x70,
        "add": 0x80,
        "sub": 0x90,
        "or": 0xa0,
        "and": 0xb0,
        "xor": 0xc0,
    }
    if arg[0] in tworeg and arg[1] in reg and arg[2] in reg:
        return [tworeg[arg[0]] + 4*reg[arg[1]] + reg[arg[2]]]
    if arg[0] == "mov" and arg[1][0] == "[":
        lhs = arg[1][1]
        if "+" in arg[1] and arg[1][3] == "#":
            offs = num(arg[1][4:-1])
            if lhs in reg and arg[2] in regl:
                return [0x50 + 4*regl[arg[2]] + reg[lhs], offs]
        else:
            return [0x40 + 4*regl[arg[2]] + reg[lhs]]
    if arg[0] == "mov" and arg[2][0] == "[":
        rhs = arg[2][1]
        if "+" in arg[2] and arg[2][3] == "#":
            offs = num(arg[2][4:-1])
            if rhs in reg and arg[1] in regl:
                return [0x30 + 4*regl[arg[1]] + reg[rhs], offs]
        else:
            return [0x20 + 4*regl[arg[1]] + reg[rhs]]
    if arg[0] == "mov" and arg[2][0] == "#":
        if arg[1] in reg:
            offs = num2(arg[2][1:])
            return [0x1c + reg[arg[1]], offs >> 8, offs & 0xff]
        if arg[1] in regl:
            offs = num(arg[2][1:])
            return [0x18 + regl[arg[1]], offs]
    reljump = {"bsl", "brl"}
    ljump = {"jump": 0x68, "call": 0x6c, "bsl": 0x7a, "brl": 0x7f}
    if arg[0] in ljump:
        inst = ljump[arg[0]]
        if labels == None:
            return [inst, 0, 0]
        if arg[1][0] == "#":
            a = num2(arg[1][1:])
            return [inst, a >> 8, a & 0xff]
        if arg[1] in labels:
            targ = labels[arg[1]]
            diff = targ
            if arg[0] in reljump:
                diff = targ-addr-3
            if diff < 0:
                diff += 0x10000
            return [inst, diff >> 8, diff & 0xff]
        else:
            print("Unknown label: " + arg[1])
            return None
    sjump = {"be": 0x69, "beq": 0x69, "bc": 0x6a, "br": 0x6b, "bne": 0x6d, "bnc": 0x6e, "bs": 0x75}
    if arg[0] in sjump:
        inst = sjump[arg[0]]
        if labels == None:
            return [inst, 0]
        if arg[1][0] == "#":
            a = num(arg[1][1:])
            return [inst, a]
        if arg[1] in labels:
            targ = labels[arg[1]]
            diff = targ-addr-2
            if diff < 0:
                diff += 0x100
            return [inst, diff]
        else:
            print("Unknown label: " + arg[1])
            return None
    print("Bad instruction: " + i)
    return None    
    
def size(i):
    return len(comp(i, 0))


def fns(lines):
    bodies = {}
    name = ""
    body = []
    for line in lines:
        if line.startswith(".function"):
            body = []
            name = line[10:].split("{")[0].strip()
            if name in bodies:
                print(name + " already defined")
        elif line.startswith("}"):
            bodies[name] = body
        else:
            body.append(line.strip())
    return bodies
    
def compile(lines):
    labels = {}
    instr = {}
    fncalls = {}
    pos = 0
    for line in lines:
        line = line.split(";")[0].strip()
        if ":" in line:
            lab = line.split(":")[0].strip()
            line = line.split(":")[1].strip()
            labels[lab] = pos
        instr[pos] = line
        pos += size(line)
    mem = [0] * pos
    for a in instr:
        v = []
        i = instr[a]
        if i.startswith("bsl !"):
            v = [0x7a, 0, 0]
            fncalls[a+1] = i[5:]
        else:
            v = comp(i, a, labels)
        mem[a:a+len(v)] = v
    return mem, fncalls

def app(v, i):
    v.append(i >> 8)
    v.append(i & 0xff)

def strapp(v, s):
    for c in s:
        v.append(ord(c))
    v.append(0)

def fnapp(v, name, fnnames, mem, fncalls):
    app(v, fnnames.index(name))
    app(v, len(mem))
    v += mem
    app(v, len(fncalls))
    for c in fncalls:
        app(v, fnnames.index(fncalls[c]))
        app(v, c)
    return v

def build(lines):
    bodies = fns(lines)
    fnnames = []
    mems = {}
    fncalls = {}
    for b in bodies:
        if not b in fnnames:
            fnnames.append(b)
        mems[b], fncalls[b] = compile(bodies[b])
        for a in fncalls[b]:
            if fncalls[b][a] not in fnnames:
                fnnames.append(fncalls[b][a])
    o = []
    app(o, len(fnnames))
    app(o, len(mems))
    for n in fnnames:
        strapp(o, n)
    for m in mems:
        o = fnapp(o, m, fnnames, mems[m], fncalls[m])
    return o

f = open(sys.argv[1], "r")
lines = f.readlines()
f.close()

f = open(sys.argv[2], "wb")
f.write(bytearray(build(lines)))
f.close()
