mov x, d
push x
mov x, c
push x
mov b, d
mov d, sp

mov al, [b+#14]
mov x, a
push xl
mov al, [b+#8]
mov x, a
push xl

bs |min

mov b, d
pop x
mov c, x
pop x
mov d, x

mov al, [b+#0]
mov x, a
push xl






mov c, sp

push xl



mov sp, c
mov d, c
ret
