#include "main.h"


void Delay_ms_Timer0(unsigned int t)
{
//	unsigned int cnt;				//cnt 16bit	
//	do
//	{
//		TL0 = 0;
//		TH0 = 0;
//		TR0 = 1; 								//Timer0 bat dau dem
//		do
//		{
//			cnt = TH0;
//			cnt <<= 8;						//dich sang trai 8 bit
//			cnt |= TL0;						//cnt = TH0 TL0
//		}while(cnt <= 1000);
//		TR0 = 0; 								//Timer0 ngung dem
//		t--;
//	}while(t!=0);
	
	//su dung overflag dem 1000 xung, set ban dau la 64536 chuyen sang hex -> 0xFC18 su dung cho THACH ANH 12M
	//voi THACH ANH 11059200Hz thi qua bo chia 12 la 921600, nen muon dem 1ms thi can 922 xung -> 65536-922=64614 <=> 0xFC66
	do{
		TL0 = 0x66;
		TH0 = 0xFC;
		TR0 = 1;									//timer0 bat dau dem
		while(!TF0);
		TR0 = 0;									//timer0 ngung dem
		TF0 = 0;
		
		t--;
	}while(t!=0);
}
void main()
{
	// chon mode cho T0
	TMOD = (TMOD&0xF0) | 0x01;	//xoa cac bit dk cua T0 roi chon lai mode 1 cho timer0
	while(1)
	{
		P2_0 = !P2_0;
		Delay_ms_Timer0(1000);	//1000ms
	}
}