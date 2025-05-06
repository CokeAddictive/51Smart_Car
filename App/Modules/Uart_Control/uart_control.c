#include "uart_control.h"
#include "STDIO.H"

void UART_Init() {
    HAL_UART_Init();
}

void UART_Echo() {
    HAL_UART_Echo();
}

void UART_BLUE() {
    HAL_UART_BLUE();
}

void RX2RSV(unsigned char *RX2Buffer, unsigned char RX2Len) { // 串口2接收回调函数，用于接收串口2的数据并处理
    printf("go to up \n");
}
// 串口2数据回调函数的注册，不调用此函数时，回调函数将不进行注册
unsigned char* UART_GetRX2() {
    HAL_Rx2Callback(RX2RSV);
    return NULL;
}
