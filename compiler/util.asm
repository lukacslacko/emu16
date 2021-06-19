.function void setpin(char, bool) {
	xor a, a
	mov al, [d]
	xor b, b
	inc b
	and a, a
	be #4
	shl b
	dec a
	bne #-4

	getpins x
	mov c, x
	mov al, [d+#1]
	be #3
	or c, b
	br #2
	not b
	and c, b
	mov x, c
	setpins x
	ret
}

.function void setpindir(char, bool) {
	xor a, a
	mov al, [d]
	xor b, b
	inc b
	and a, a
	be #4
	shl b
	dec a
	bne #-4

	getpindirs x
	mov c, x
	mov al, [d+#1]
	be #3
	or c, b
	br #2
	not b
	and c, b
	mov x, c
	setpindirs x
	ret
}

.function bool getpin(char) {
	xor b, b
	inc b
	and d, d
	be #4
	shl b
	dec d
	bne #-4

	getpins x
	mov a, x
	xor d, d
	and a, b
	be #1
	inc d
	ret
}

.function bool getpindir(char) {
	xor b, b
	inc b
	and d, d
	be #4
	shl b
	dec d
	bne #-4

	getpindirs x
	mov a, x
	xor d, d
	and a, b
	be #1
	inc d
	ret
}

.function void setpins(unsigned int) {
	mov x, d
	setpins x
	ret
}

.function void setpindirs(unsigned int) {
	mov x, d
	setpindirs x
	ret
}

.function unsigned int getpins(void) {
	getpins x
	mov d, x
	ret
}

.function unsigned int getpindirs(void) {
	getpindirs x
	mov d, x
	ret
}

.function unsigned long* mul(unsigned int, unsigned int) {
	mul:
	mov al, [d]
	mov x, a
	swapxlxh
	mov a, x
	mov al, [d+#1]
	mov bl, [d+#2]
	mov x, b
	swapxlxh
	mov b, x
	mov bl, [d+#3]
	mov dl, #16
	xor c, c
	mov x, c
	mov c, sp
	push x
	push x
	mulloop:
	shl a
	mov x, a
	push x
	mov al, [c+#2]
	mov x, a
	swapxlxh
	mov a, x
	mov al, [c+#3]
	bnc #10
	shl a
	bc #3
	add a, b
	br #3
	clc
	add a, b
	sec
	br #1
	shl a
	mov [c+#3], al
	mov x, a
	swapxlxh
	mov a, x
	mov [c+#2], al
	mov al, [c]
	mov x, a
	swapxlxh
	mov a, x
	mov al, [c+#1]
	rol a
	mov [c+#1], al
	mov x, a
	swapxlxh
	mov a, x
	mov [c], al
	pop x
	mov a, x
	dec d
	bne mulloop
	mov d, c
	pop x
	pop x
	ret
}

.function void div(unsigned int, unsigned int, unsigned int*, unsigned int*) {
	div:
	mov x, d
	push x
	mov al, [d]
	mov x, a
	swapxlxh
	mov a, x
	mov al, [d+#1]
	mov bl, [d+#2]
	mov x, b
	swapxlxh
	mov b, x
	mov bl, [d+#3]
	br divreg
	divret:
	pop x
	mov d, x
	mov bl, [d+#4]
	mov x, b
	swapxlxh
	mov b, x
	mov bl, [d+#5]
	mov x, a
	mov [b+#1], al
	swapxlxh
	mov a, x
	mov [b], al
	mov bl, [d+#6]
	mov x, b
	swapxlxh
	mov b, x
	mov bl, [d+#7]
	mov x, c
	mov [b+#1], cl
	swapxlxh
	mov c, x
	mov [b], cl
	ret
	divreg:
	xor c, c	
	mov d, #10	
	clc			
	divloop:
	rol a		
	rol c		
	sec		
	mov x, c	
	sub c, b	
	bc #3	
	mov c, x       
	dec d		
	br #2       
	dec d       
	sec         
	bne divloop
	rol a		
	br divret
}
