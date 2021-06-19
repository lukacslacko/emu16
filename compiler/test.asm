.function word main(void) {
	mov d, sp
	mov al, #6
	mov x, a
	push xl
	mov al, #1
	mov x, a
	push xl
	bsl !void setpindir(char, bool)
	ret
}
.function main {
	bsl !word main(void)
	br #-2
}
