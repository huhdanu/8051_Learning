#include "main.h"

unsigned char cnt=10;

void main()
{
	//cau hinh cho timer0 hoat dong mode 1
	TMOD = (TMOD&0xF0)|0x01;
	//ngat xay ra khi dem duoc 50ms -> 46080 chu ky --> gia tri khoi tao la 65536 - 48080 = 199456 (0x4C00)
	TH0 = 0x4C;
	TL0 = 0x00;
	
	ET0 = 1;		// cho phep ngat bang Timer 0
	EA = 1;			// ngat toan cuc
	TR0 = 1;		// timer0 bat dau hoat dong
	
	P2 = 0;
	while(1)
	{
		//cho VDK o che do ngu de tiet kiem NL khi co interrupt moi hoat dong lai
		PCON |= 0x01;	
	}	
}

void  timer_overflow(void) interrupt 1
{
	//nap lai gia tri bat dau dem cua Timer
	TH0 = 0x4C;
	TL0 = 0x00;
	
	cnt--;
	if(cnt==0)
	{
		cnt = 10;
		P2 = ~P2;
	}
}