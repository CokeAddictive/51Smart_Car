#include "hal_uart.h"

#include "STC8G_H_GPIO.h"
#include "STC8G_H_NVIC.h"
#include "STC8G_H_Switch.h"
#include "STC8G_H_UART.h"
#include "STRING.H"

static void GPIO_Config() {
    GPIO_InitTypeDef GPIO_InitStructure;              // 结构定义
    GPIO_InitStructure.Mode = GPIO_PullUp;            // 指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_InitStructure.Pin = GPIO_Pin_0 | GPIO_Pin_1; // 指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7
    GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);       // 初始化
}

static void UART_Config() {
    COMx_InitDefine UART_InitStructure;
    UART_InitStructure.UART_Mode = UART_8bit_BRTx;
    UART_InitStructure.UART_BRT_Use = BRT_Timer1;
    UART_InitStructure.UART_BaudRate = 115200; // 通常只有波特率需要改
    UART_InitStructure.UART_RxEnable = ENABLE; // 允许接收
    UART_InitStructure.BaudRateDouble = DISABLE;
    UART_Configuration(UART1, &UART_InitStructure); // ARTX代表你用的那一组串口
    NVIC_UART1_Init(ENABLE, Priority_2);            // 去NVIC.H里面找，用的串口几就选几,打开中断使能
    UART1_SW(UART1_SW_P30_P31);                     // 去Swtich.h里面找定义 ,切换引脚（可选）至P30,P31
}

void HAL_UART_Init() { // 优先级为2的串口1通讯
    GPIO_Config();     // 初始化GPIO
    UART_Config();     // 初始化UART
    EA = 1;
}

void HAL_UART_Echo() {
    char i;
    if (COM1.RX_Cnt > 0 && --COM1.RX_TimeOut == 0) { // 数组里有数据且能把5倒数到0
        for (i = 0; i < COM1.RX_Cnt; i++) {
            TX1_write2buff(RX1_Buffer[i]); // 读取数组里每个字符，并通过串口发送出去
        }
        COM1.RX_Cnt = 0; // 如果不置0程序会一直输出
    }
}