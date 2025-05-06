#include "Buzzer_Control.h"
#include "RTX51TNY.H"
#include "battery_feedback.h"
#include "key_control.h"
#include "light_control.h"
#include "motor_control.h"
#include "sensor_feedback.h"
#include "uart_control.h"
#include "ultrasonic_feedback.h"
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
    Ultrasonic_Init();        // 超声波
    Motors_Init();            // 电机
    Sensor_Init();            // 传感器

    UART_GetRX2();//串口2 接收测试//注意这个调用一次 给回调函数注册了就可以了

    os_delete_task(1); // kill oneself
}

void UART() _task_ 2 { // 串口任务
    while (1) {
        UART_BLUE();
        
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
    float distance = 0;
    char key = 0;
    switch (i) {
    case 0:
        Light_SetMode(LIGHT_MODE_LEFT);
        break;
    case 1:
        Light_SetMode(LIGHT_MODE_RIGHT);
        break;
    case 2:
        Light_SetMode(LIGHT_MODE_HAZARD);
        break;
    case 3:
        Light_SetMode(LIGHT_MODE_OFF);
        break;
    }
    i++;
    i %= 4;
}
void Key_UpCB() {
    // 当前不需要按键释放处理
}
