.static 20 proc
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
call a
mov x, b
push x
mov x, a
push x
mov a, #!proc
mov bl, [a]
mov x, b
swapxlxh
mov b, x
mov bl, [a+#1]
pop x
mov a, x
pop x
mov sp, b
mov b, x
ret
syscalls:
bsl !void sys$reset()
hlt
bsl !void sys$yield()
ret
bsl !void sys$kill()
ret
bsl !void sys$fork()
ret
bsl !void sys$getpid()
ret
}
