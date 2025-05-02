#include "Buzzer_Control.h"
#include "RTX51TNY.H"
#include "battery_feedback.h"
#include "key_control.h"
#include "light_control.h"
#include "uart_control.h"
#include <stdio.h> //为了使用printf函数

// 函数声明
void Key_DownCB();
void Key_UpCB();

void System_Init() _task_ 1 { // 系统初始化任务
    UART_Init();              // 串口
    Light_Init();             // 车灯
    Buzzer_Init();            // 蜂鸣器
    Key_Init();               // 按键
    Battery_Init();           // 电池

    os_delete_task(1); // kill oneself
}

void UART() _task_ 2 { // 串口回显任务
    while (1) {
        UART_Echo();
        os_wait2(K_TMO, 2);
    }
}

void Light() _task_ 3 { // 车灯任务
    while (1) {
        Light_Update();
        os_wait2(K_TMO, 3);
    }
}

void Key() _task_ 4 { // 按键任务
    while (1) {
        Key_Scan(Key_DownCB, Key_UpCB);
        os_wait2(K_TMO, 4);
    }
}

void Launch() _task_ 0 {
    os_create_task(1);
    os_create_task(2);
    os_create_task(3);
    os_create_task(4);

    os_delete_task(0); // kill oneself
}

void Key_DownCB() {
    static char i = 0;
    switch (i) {
    case 0:
        Light_SetMode(LIGHT_MODE_LEFT);
        break;
    case 1:
        Light_SetMode(LIGHT_MODE_RIGHT);
        break;
    case 2:
        Light_SetMode(LIGHT_MODE_HAZARD);
        Buzzer_Alarm();
        break;
    case 3:
        Light_SetMode(LIGHT_MODE_OFF);
        printf("电池电压为:%.2f\n", Battery_GetVoltage());
        break;
    }
    printf("当前进入的是case %d\n",(int)i);
    i++;
    i %= 4;
}
void Key_UpCB() {
    // 当前不需要按键释放处理
}
