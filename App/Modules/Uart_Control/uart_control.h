#ifndef UART_CONTROL_H
#define UART_CONTROL_H

#include "hal_uart.h"


void UART_Init();

// 串口数据回显
void UART_Echo();
//串口和蓝牙交互
void UART_BLUE();

// 串口2接收回调函数
unsigned char* UART_GetRX2();


#endif // UART_CONTROL_H