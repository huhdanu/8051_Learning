#include "main.h"
#include "..\Lib\delay.h"
#include "..\Lib\uart_mode1.h"


void main()
{
	char i;
	
	Uart_init();
	while(1)
	{
		Uart_Write_Text("Nhap vao ky tu in thuong bat ky: ");
		while(Uart_Data_Ready()==0);
		i = Uart_Read();
		i = i - 32;									//doi sang in hoa
		Uart_Write_Text("->");
		Uart_Write(i);
		Uart_Write_Text("\r\n");
	}
}
