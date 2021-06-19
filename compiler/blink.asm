.function main {
	bsl !init
	loop:
	mov c, #0
	bsl !emit
	mov c, #$ffff
	bsl !emit
	br loop
}

.function init {
	xor a, a
	mov x, a
	setpindirs x
	ret
}

.function emit {
	mov x, c
	setpins x
	ret
}
