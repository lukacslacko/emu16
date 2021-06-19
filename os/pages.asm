.function void load_pages(pages_t*) {
mov al, [d]
mov x, a
swapxlxh
mov a, x
mov al, [d+#1]
mov bl, [a+#1]
mov x, b
swapxlxh
mov b, x
mov bl, [a]
mov x, b
mov v10, x
mov bl, [a+#3]
mov x, b
swapxlxh
mov b, x
mov bl, [a+#2]
mov x, b
mov v32, x
mov bl, [a+#5]
mov x, b
swapxlxh
mov b, x
mov bl, [a+#4]
mov x, b
mov v54, x
mov bl, [a+#7]
mov x, b
swapxlxh
mov b, x
mov bl, [a+#6]
mov x, b
mov v76, x
mov bl, [a+#9]
mov x, b
swapxlxh
mov b, x
mov bl, [a+#8]
mov x, b
mov v98, x
mov bl, [a+#11]
mov x, b
swapxlxh
mov b, x
mov bl, [a+#10]
mov x, b
mov vba, x
mov bl, [a+#13]
mov x, b
swapxlxh
mov b, x
mov bl, [a+#12]
mov x, b
mov vdc, x
mov bl, [a+#15]
mov x, b
swapxlxh
mov b, x
mov bl, [a+#14]
mov x, b
mov vfe, x
ret
}
