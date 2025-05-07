#ifndef UART_CONTROL_H
#define UART_CONTROL_H

#include "hal_uart.h"


void UART_Init();

// 串口数据回显
void UART_Echo();
//串口和蓝牙交互
void UART_BLUE();

// 串口2接收回调函数
void UART_GetRX2();

void UART_APP_Control(void (*APP)(unsigned char *, unsigned char)); // 
void UART_PC_Control(void (*PC)(unsigned char *, unsigned char));  // 

#endif // UART_CONTROL_H