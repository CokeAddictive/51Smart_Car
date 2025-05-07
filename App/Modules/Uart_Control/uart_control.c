#include "uart_control.h"
#include "STDIO.H"

// 控制方式回调函数
static void (*APP_Control)(unsigned char *, unsigned char) = NULL;
static void (*PC_Control)(unsigned char *, unsigned char) = NULL;

void UART_Init() {
    HAL_UART_Init();
}

void UART_Echo() {
    HAL_UART_Echo();
}

void UART_BLUE() {
    HAL_UART_BLUE();
}

void RX2RSV(unsigned char *RX2Buffer, unsigned char RX2Len){ // 串口2接收回调函数，用于接收串口2的数据并处理
    if (PC_Control != NULL) { // 如果APP_Control不为空，就调用APP_Control函数
        PC_Control(RX2Buffer, RX2Len);
    }
    if (APP_Control != NULL) { // 如果APP_Control不为空，就调用APP_Control函数
        APP_Control(RX2Buffer, RX2Len);
    }
}

// 串口2数据回调函数的注册，不调用此函数时，回调函数将不进行注册
void UART_GetRX2() {
    HAL_Rx2Callback(RX2RSV);
}

void UART_APP_Control(void (*APP)(unsigned char *, unsigned char)) {
    APP_Control=APP;
}

void UART_PC_Control(void (*PC)(unsigned char *, unsigned char)) {
    PC_Control=PC;
}
