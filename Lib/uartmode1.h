#ifndef _UARTMODE1_H_
#define _UARTMODE1_H_


//Khoi tao ham Uart o Mode 1
void Uart_Init();

//Ham gui ky tu
void Uart_Write(char c);

//Ham gui chuoi 
void Uart_Write_Text(char *str);

//Kiem tra du lieu co nhan duoc byte du lieu chua
//Return 1: da nhan duoc
//			 0: chua nhan duoc	
char Uart_Data_Ready();

//doc byte nhan duoc tu UART
char Uart_Read();

#endif