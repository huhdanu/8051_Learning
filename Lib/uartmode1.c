#include "main.h"
#include "..\Lib\uartmode1.h"

//xu ly loi dung thach anh khac tan so
#if (FREQ_OSC != 11059200)
	#error "Thu vien UART_MODE1 chi ho tro tan so hoat dong 11059200"
#endif

void Uart_Init()
{
	//Khoi tao UART o mode 1, baud rate 9600
	
	SM0 = 0; SM1 = 1;						//chon UART mode 1
	// chon TMOD cho mode 1 nhung van giu cac trang thai truoc do cua thanh ghi
	TMOD = (TMOD&0x0F) | 0x20;	//0010 xxxx - Timer1 hoat dong o che do 8bit tu dong nap lai
	
	#if (BAUD_RATE == 1200)
	TH1 = 0xE8; 								//toc do baud 1200
	#elif (BAUD_RATE == 2400)
	TH1 = 0xF4;									//toc do baud 2400
	#elif (BAUD_RATE == 9600)
	TH1 = 0xFD;									//toc do baud 9600
	#elif (BAUD_RATE == 19200)
	TH1 = 0xFD;									//toc do baud 19600
	PCON |= 0x80;								//use SMOD 1
	#else
		#error "Toc do baud chi co the la 1200, 2400, 9600, 19200"
	#endif
	
	TR1 = 1;										//Timer 1 bat dau chay
	TI = 1;											//San sang gui du lieu
	REN = 1;										//Cho phep nhan du lieu
}

void Uart_Write(char c)
{
	while(TI == 0);
	TI = 0;
	SBUF = c;
}

void Uart_Write_Text(char *str)
{
	unsigned char i;
	while(str[i]!=0)				//ky tu cuoi la NULL
	{
		Uart_Write(str[i]);
		i++;
	}
}

char Uart_Data_Ready()
{
	return RI;
}

char Uart_Read()
{
	RI = 0;
	return SBUF;
}
