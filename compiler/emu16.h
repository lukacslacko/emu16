#pragma once
#include <cstdint>
#include <cstring>
class EMU16 {
	private:
		inline uint8_t* ma(uint16_t a) {
			return &(m[(a&0x0fff)|(v[(a&0xf000)>>12]<<12)]);
		}
		inline void push8(uint8_t d) {
			*ma(sp++)=d;
		}
		inline uint8_t pop8() {
			return *ma(--sp);
		}
		inline void push16(uint16_t d) {
			push8(d>>8);
			push8(d);
		}
		inline uint16_t pop16() {
			uint16_t t;
			t=pop8();
			t|=((uint16_t)pop8())<<8;
			return t;
		}
		uint8_t m[1048576];
	public:
		uint8_t v[16];
		uint16_t tl;
		uint16_t pc, a, b, c, d, x, sp;
		bool bz, bc;
		uint32_t time;
	public:
		uint32_t gpio;
		uint8_t*p=nullptr;
		EMU16() {}
		virtual ~EMU16() {}
		inline void reset();
		void clock();
		void tick() {time++;}
};
inline void EMU16::reset() {
	memcpy(m,p,4096);
	v[0x0]=0x0;
	v[0x1]=0x1;
	v[0x2]=0x2;
	v[0x3]=0x3;
	v[0x4]=0x4;
	v[0x5]=0x5;
	v[0x6]=0x6;
	v[0x7]=0x7;
	v[0x8]=0x8;
	v[0x9]=0x9;
	v[0xa]=0xa;
	v[0xb]=0xb;
	v[0xc]=0xc;
	v[0xd]=0xd;
	v[0xe]=0xe;
	v[0xf]=0xf;
	memset(&pc,0,24);
	sp=0x1000;
}
void EMU16::clock() {
	uint8_t i;
	i=*ma(pc++);
	if (!i) {
		reset();
		return;
	}
	if (i==5) {
		push16(pc);
		pc=0;
		v[0]=0;
		return;
	}
	if (i==10) {
		pc=pop16();
		return;
	}
	if (i==0x7f) {
		uint16_t o;
		o=*ma(pc++)<<8;
		o|=*ma(pc++);
		pc+=o;
		return;
	}
	if (i==0x7a) {
		uint16_t o;
		o=*ma(pc++)<<8;
		o|=*ma(pc++);
		push16(pc);
		pc+=o;
		return;
	}
	if (i==0x75) {
		uint8_t o;
		o=*ma(pc++);
		push16(pc);
		if (o&0x80) {
			pc-=((uint8_t)(~o)+1);
		} else {
			pc+=o;
		}
		return;
	}
	switch (i&0xf0) {
		case 0x00:
			((uint16_t*)((uint16_t*)&a))[(i&0xc)>>2]=((uint16_t*)&a)[i&3];
			return;
		case 0x10:
			switch (i&0xc) {
				uint32_t r;
				case 0x0:
					//~ push8(((uint16_t*)&a)[i&3]);
					r=((uint16_t*)&a)[i&3];
					r++;
					bc=r>>16;
					bz=!(r&0xffff);
					((uint16_t*)&a)[i&3]=r;
					return;
				case 0x4:
					//~ ((uint16_t*)&a)[i&3]&=0xff00;
					//~ ((uint16_t*)&a)[i&3]|=pop8();
					r=((uint16_t*)&a)[i&3];
					r--;
					bc=r>>16;
					bz=!(r&0xffff);
					((uint16_t*)&a)[i&3]=r;
					return;
				case 0x8:
					((uint16_t*)&a)[i&3]&=0xff00;
					((uint16_t*)&a)[i&3]|=*ma(pc++);
					return;
				case 0xc:
					((uint16_t*)&a)[i&3]=(((uint16_t)*ma(pc++))<<8);
					((uint16_t*)&a)[i&3]|=*ma(pc++);
					return;
				default:
					return;
			}
		case 0x20:
			((uint16_t*)&a)[(i&0xc)>>2]=*ma(((uint16_t*)&a)[i&3]);
			return;
		case 0x30:
			((uint16_t*)&a)[(i&0xc)>>2]=*ma((((uint16_t*)&a)[i&3])+*ma(pc++));
			return;
		case 0x40:
			*ma(((uint16_t*)&a)[i&3])=((uint16_t*)&a)[(i&0xc)>>2];
			return;
		case 0x50:
			*ma((((uint16_t*)&a)[i&3])+*ma(pc++))=((uint16_t*)&a)[(i&0xc)>>2];
		case 0x60:
			if (i&0x8) {
				switch (i) {
					uint8_t o;
					uint16_t t;
					case 0x68:
						t=(((uint16_t)*ma(pc++))<<8);
						t|=*ma(pc++);
						pc=t;
						return;
					case 0x69:
						o=*ma(pc++);
						if (bz) {
							if (o&0x80) {
								pc-=((uint8_t)(~o)+1);
							} else {
								pc+=o;
							}
						}
						return;
					case 0x6a:
						o=*ma(pc++);
						if (bc) {
							if (o&0x80) {
								pc-=((uint8_t)(~o)+1);
							} else {
								pc+=o;
							}
						}
						return;
					case 0x6b:
						o=*ma(pc++);
						if (o&0x80) {
							pc-=((uint8_t)(~o)+1);
						} else {
							pc+=o;
						}
						return;
					case 0x6c:
						push16(pc+2);
						t=(((uint16_t)*ma(pc++))<<8);
						t|=*ma(pc++);
						pc=t;
						return;
					case 0x6d:
						o=*ma(pc++);
						if (!bz) {
							if (o&0x80) {
								pc-=((uint8_t)(~o)+1);
							} else {
								pc+=o;
							}
						}
						return;
					case 0x6e:
						o=*ma(pc++);
						if (!bc) {
							if (o&0x80) {
								pc-=((uint8_t)(~o)+1);
							} else {
								pc+=o;
							}
						}
						return;
					case 0x6f:
						t=0;
						t|=x<<8;
						t|=x>>8;
						x=t;
						return;
					default:
						return;
				}
			} else {
				if (i&0x40) {
					push16(pc+2);
					pc=((uint16_t*)&a)[i&3];
					return;
				} else {
					pc=((uint16_t*)&a)[i&3];
					return;
				}
			}
		uint16_t l,r;
		case 0x70:
			l=((uint16_t*)&a)[(i&0xc)>>2];
			r=((uint16_t*)&a)[i&3];
			bz=l==r;
			bc=l<r;
			return;
		uint32_t res;
		case 0x80:
			if (i==0x80) {
				x&=0x00ff;
				x|=pop8()<<8;
				return;
			}
			if (i==0x85) {
				x&=0xff00;
				x|=pop8();
				return;
			}
			if (i==0x8a) {
				push8(x>>8);
				return;
			}
			if (i==0x8f) {
				push8(x);
				return;
			}
			l=((uint16_t*)&a)[(i&0xc)>>2];
			r=((uint16_t*)&a)[i&3];
			res=(uint32_t)l+(uint32_t)r;
			res+=bc;
			bz=!(res&0xffff);
			bc=res&0x10000;
			((uint16_t*)&a)[(i&0xc)>>2]=res;
			return;
		case 0x90:
			if (i==0x90) {
				bz=true;
				return;
			}
			if (i==0x95) {
				bc=true;
				return;
			}
			if (i==0x9a) {
				bz=false;
				return;
			}
			if (i==0x9f) {
				bc=false;
				return;
			}
			l=((uint16_t*)&a)[(i&0xc)>>2];
			r=((uint16_t*)&a)[i&3];
			res=(uint32_t)l+((uint32_t)(uint16_t)~r);
			res+=bc;
			bz=!(res&0xffff);
			bc=res&0x10000;
			((uint16_t*)&a)[(i&0xc)>>2]=res;
			return;
		case 0xa0:
			if ((i==0xa0)||(i==0xa5)||(i==0xaa)||(i==0xaf)) {
				((uint16_t*)&a)[i&3]=~((uint16_t*)&a)[i&3];
				return;
			}
			l=((uint16_t*)&a)[(i&0xc)>>2];
			r=((uint16_t*)&a)[i&3];
			res=l|r;
			bz=!res;
			((uint16_t*)&a)[(i&0xc)>>2]=res;
			return;
		case 0xb0:
			l=((uint16_t*)&a)[(i&0xc)>>2];
			r=((uint16_t*)&a)[i&3];
			res=l&r;
			bz=!res;
			((uint16_t*)&a)[(i&0xc)>>2]=res;
			return;
		case 0xc0:
			l=((uint16_t*)&a)[(i&0xc)>>2];
			r=((uint16_t*)&a)[i&3];
			res=l^r;
			bz=!res;
			((uint16_t*)&a)[(i&0xc)>>2]=res;
			return;
		case 0xd0:
			switch (i&0xc) {
				case 0x0:
					res=((uint16_t*)&a)[i&3]<<1;
					bz=!(res&0xffff);
					bc=res&0x10000;
					((uint16_t*)&a)[i&3]=res;
					return;
				case 0x4:
					res=((uint16_t*)&a)[i&3]>>1;
					bz=!(res&0xffff);
					bc=((uint16_t*)&a)[i&3]&1;
					((uint16_t*)&a)[i&3]=res;
					return;
				case 0x8:
					res=((uint16_t*)&a)[i&3]<<1;
					res+=bc;
					bz=!(res&0xffff);
					bc=res&0x10000;
					((uint16_t*)&a)[i&3]=res;
					return;
				case 0xc:
					res=((uint16_t*)&a)[i&3]>>1;
					res+=bc<<15;
					bc=((uint16_t*)&a)[i&3]&1;
					bz=!(res&0xffff);
					((uint16_t*)&a)[i&3]=res;
					return;
				default:
					return;
			}
		case 0xe0:
			switch (i&0xc) {
				case 0x0:
					x=((uint16_t*)&a)[i&3];
					return;
				case 0x4:
					((uint16_t*)&a)[i&3]=x;
					return;
				case 0x8:
					sp=((uint16_t*)&a)[i&3];
					return;
				case 0xc:
					((uint16_t*)&a)[i&3]=sp;
					return;
				default:
					return;
			}
		case 0xf0:
			if (i&8) {
				switch (i) {
					case 0xf8:
						x=time>>16;
						tl=time;
						return;
					case 0xf9:
						x=tl;
						return;
					case 0xfa:
						push16(x);
						return;
					case 0xfb:
						x=pop16();
						return;
					case 0xfc:
						gpio&=0xffff;
						gpio|=x<<16;
						return;
					case 0xfd:
						gpio&=0xffff0000;
						gpio|=x;
						return;
					case 0xfe:
						x=gpio>>16;
						return;
					case 0xff:
						x=gpio;
						return;
				}
			} else {
				v[(i&7)<<1]=x;
				v[((i&7)<<1)+1]=x>>8;
			}
		default:
			return;
	}
}
