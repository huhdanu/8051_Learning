#include "main.h"
#include <stdio.h>
#include "..\Lib\uartmode1.h"
#include "..\Lib\delay.h"

//use putchar, _getkkey(), printf()

void main()
{
	char c;
	//khoi tao UART mode 1, baudrate 9600, 8bit data	
	Uart_Init();
	//putchar('a');			//gui ky tu ve Uart <=> Uart_Write('a')
	
	while(1)
	{
		// function: _getkey() <=> Uart_Ready,Uart_Read()
		// function: printf()  <=> Uart_Write_Text()
		//c = _getkey();				//doi 1 ky tu truyen toi UART, doc va tra ve ky tu nhan duoc
		printf("toi ba dao vai cut thiet chu, dung khong anhem?");
		printf("\n\r");
		delay_ms(500);
	}
}