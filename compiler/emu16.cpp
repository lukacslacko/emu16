#include <stdio.h>

#include "emu16.h"

uint16_t mul(uint8_t lhs,uint8_t rhs) {
	uint8_t mul[4096] = {
		0xc0, 0xe0, 0xfc, 0x1c, 0, lhs, 0x1d, 0, rhs, 0x6c, 0, 0x10,
		0xe2, 0xfd, 0x6b, 0xfe,
		0xca, 0xb0, 0x6d, 1, 0x0a, 0xd4, 0x6e, 2, 0x70, 0x89, 0xd1, 
		0x6b, 0xf4
	};
	EMU16 emu16;
	emu16.p = mul;
	emu16.reset();
	while (emu16.gpio==0) {
		emu16.clock();
	}
	return emu16.gpio;
}

uint16_t div(uint16_t lhs, uint16_t rhs) {
	uint8_t div[4096] = {
		0xc0, 0xe0, 0xfc, 0x1c, lhs >> 8, lhs & 0xff, 0x1d, rhs >> 8, rhs & 0xff, 0x6c, 0, 0x10,
		0xe0, 0xfd, 0x6b, 0xfe,
		0xca,             //~ xor c, c	 ca
		0x1f, 0x00, 0x10, //~ mov d, #16  1f 00 10
		0x9f,             //~ clc		  9f
		                  //~ divloop:
		0xd8,             //~ rol a		  d8
		0xda,             //~ rol c		  da
		0x95,             //~ sec		  95
		0xe2,             //~ mov x, c	  e2
		0x99,             //~ sub c, b	  99
		0x6a, 0x01,       //~ bc #1		  6a 01
		0xe6,             //~ mov c, x	  e6
		0x6a, 0x03,       //~ bc #3       6a 03   
		0x17,             //~ dec d		  17
		0x6b, 0x02,       //~ br #2       6b 02
		0x17,             //~ dec d       17
		0x95,             //~ sec         95
		0x6d, 0xef,       //~ bne divloop 6d ef
		0x06,             //~ mov b, c	  06
		0xd8,             //~ rol a		  d8
		0x0a,             //~ ret		  0a
	};
	EMU16 emu16;
	emu16.p = div;
	emu16.reset();
	while (emu16.gpio==0) {
		emu16.clock();
		//~ printf("gpio a    b    c    d    x    pc\n");
		//~ printf("%04X %04X %04X %04X %04X %04X %04X\n", emu16.gpio & 0xFFFF, emu16.a, emu16.b, emu16.c, emu16.d, emu16.x, emu16.pc);
	}
	return emu16.gpio;
}

int main() {
	//~ uint8_t blink[4096] = {
		//~ 0xc0,        // 0000 xor a, a
		//~ 0xe0,        // 0001 mov x, a
		//~ 0xfc,        // 0002 setpindirs x
		//~ 0xfd,        // 0003 setpins x
		//~ 0xa0,        // 0004 not a
		//~ 0xe0,        // 0005 mov x, a
		//~ 0x6b, 0xfb   // 0006 br #-5
	//~ };
	printf("%04X\n", div(100, 5));
	for (uint8_t lhs=1;lhs;++lhs) {
		for (uint8_t rhs=1;rhs;++rhs) {
			if (((uint16_t)lhs*(uint16_t)rhs)!=mul(lhs,rhs)) {
				return 1;
			}
		}
	}
	//~ uint8_t lhs = 100, rhs = 100;
	//~ while (true) {
		//~ emu16.clock();
		//~ emu16.tick();
		//~ printf("gpio a    b    c    d    x    pc\n");
		//~ printf("%04X %04X %04X %04X %04X %04X %04X\n", emu16.gpio & 0xFFFF, emu16.a, emu16.b, emu16.c, emu16.d, emu16.x, emu16.pc);
		//~ getchar();
		//~ if (c == 'x') {
			//~ emu16.gpio |= 1;
			//~ printf("1");
		//~ } else {
			//~ emu16.gpio &= ~((uint32_t)1);
			//~ printf("0");
		//~ }
	//~ }
	return 0;
}
//~ class EMU16 {
	//~ uint32_t gpio;  // pindirs << 16 | pins
	//~ uint8_t*p;  // initial 4kB rom
	//~ void clock();
	//~ void reset();
	//~ void tick();
//~ }
