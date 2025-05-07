#include "BLE_Control.h"

void BLE_Control_Init() {
    UART_Init(); // 初始化串口
    UART_GetRX2();
}

void APP(unsigned char *RX2Buffer, unsigned char RX2Len) {
    unsigned char *buf = RX2Buffer;
    char x, y, i;
    x = buf[2];
    y = buf[3];
    if (x != 0 && y != 0) {
        printf("x=%d,y=%d\n", (int)x, (int)y);
    }
    if (buf[4]) {
        printf("light\n");
    }
    if (buf[5]) {
        printf("left\n");
    }
    if (buf[6]) {
        printf("right\n");
    }
    if (buf[7]) {
        printf("stop\n");
    }
}

void PC(unsigned char *RX2Buffer, unsigned char RX2Len) {
}

//
void BEL_Ctrl() {
    UART_APP_Control(APP);
    // void UART_PC_Control(PC);
}
