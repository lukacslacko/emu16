.static 20 proc
.static 8 registers
.function main {
and a, a
bne #4
mov b, #$2000
mov sp, b
mov x, b
mov b, #4
cmp b, a
bnc #2
mov b, x
ret
shl a
shl a
mov b, #syscalls
add a, b
mov b, sp
push x
mov x, a
mov a, #$1000
mov sp, a
push x
mov x, b
push x
mov a, #!proc
mov bl, [a]
mov x, b
swapxlxh
mov b, x
mov bl, [a+#1]
pop x
mov a, x
swapxlxh
mov [b], al
mov a, x
mov [b+#1], al
swapxlxh
mov a, x
mov bl, [a]
mov x, b
swapxlxh
mov b, x
mov bl, [a+#1]
pop x
mov a, x
mov x, b
mov b, d
mov d, sp
push x
mov x, c
push x
mov x, b
push x
call a
mov d, #!registers
clc
mov a, #8
add d, a
mov sp, d
pop x
mov d, x
pop x
mov c, x
pop x
mov b, x
pop x
mov a, x
push x
mov x, b
push x
mov b, #!proc
mov al, [b]
mov x, a
swapxlxh
mov a, x
mov al, [b+#1]
pop x
mov b, x
pop x
mov sp, a
mov a, x
ret
syscalls:
bsl !void sys$reset(int, int, int)
hlt
bsl !void sys$yield(int, int, int)
ret
bsl !void sys$kill(int, int, int)
ret
bsl !void sys$fork(int, int, int)
ret
bsl !void sys$getpid(int, int, int)
ret
}
