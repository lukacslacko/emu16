#include <cstdint>
#include <string>
class microemu {
public:
	virtual ~microemu(){}
	void tick();
	bool clock();
	microemu(std::string e0, std::string e1, std::string bus, std::string sel);
	uint8_t ram[1048576];
	virtual uint8_t getlowpins()=0; 
	virtual uint8_t getlowpindirs()=0;
	virtual uint8_t gethighpins()=0;
	virtual uint8_t gethighpindirs()=0;
	virtual void setlowpins(uint8_t)=0;
	virtual void setlowpindirs(uint8_t)=0;
	virtual void sethighpins(uint8_t)=0;
	virtual void sethighpindirs(uint8_t)=0;
	uint8_t t, u, v, i, m;
	bool c, z;
	uint8_t vm[16];
	uint8_t regs[16];
	uint8_t eeprom[1048576];
	uint16_t micro[262144];
	uint32_t time;
	void reset();
};
void microemu::tick() {
	time++;
}
bool microemu::clock() {
	uint16_t mi=micro[(z<<17)|(c<<16)|(((uint16_t)i)<<8)|m];
	uint8_t data;
	m++;
	if(mi&0x0004) {
		switch (mi&0x0070) {
			case 0x0000:
				data=regs[mi>>12];
				break;
			case 0x0010:
				data=t;
				break;
			case 0x0020:
				data=ram[(((uint32_t)vm[u>>4])<<12)|(((uint16_t)(u&0xf))<<8)|v];
				break;
			case 0x0030:
				data=eeprom[(((uint32_t)(mi&0xf000))<<4)|(((uint16_t)u)<<8)|v];
				break;
			default:
				data=0;
				break;
		}
		if(mi&0x0008) {
			if((mi&0x0ff0)==0x0000){return false;}
			if((mi&0x0ff0)==0x0410){return false;}
			if((mi&0x0ff0)==0x0720){return false;}
			if((mi&0x00f0)==0x00a0){return false;}
		} else {
			switch (mi&3) {
				case 0:
					setlowpindirs(data);
					break;
				case 1:
					sethighpindirs(data);
					break;
				case 2:
					setlowpins(data);
					break;
				case 3:
					sethighpins(data);
					break;
			}
			return true;
		}
	} else {
		if(mi&0x0008) {
			switch (mi&3) {
				case 0:
					data=getlowpindirs();
					break;
				case 1:
					data=gethighpindirs();
					break;
				case 2:
					data=getlowpins();
					break;
				case 3:
					data=gethighpins();
					break;
			}
		} else {
			data=((0xff<<(mi&3))&time)>>(mi&3);
		}
	}
	if(mi&0x0080) {
		vm[(mi&0x0f00)>>8]=data;
	} else {
		switch(mi&0x0700) {
			case 0x0000:
				regs[mi>>12]=data;
				break;
			case 0x0100:
				i=data;
				m=0;
				break;
			case 0x0200:
				z=data;
				break;
			case 0x0300:
				c=data&1;
				break;
			case 0x0400:
				t=data
				break;
			case 0x0500:
				u=data;
				break;
			case 0x0600:
				v=data;
				break;
			case 0x0700:
				ram[(((uint32_t)vm[u>>4])<<12)|(((uint16_t)(u&0xf))<<8)|v]=data;
				break;
		}
	}
	return true;
}
void microemu::microemu(std::string e0, std::string e1, std::string bus, std::string sel) {
	
}
void microemu::reset() {
	time=0;
	i=0;
	m=0;
}
