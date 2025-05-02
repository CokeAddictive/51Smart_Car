#include "hal_key.h"
#include "STC8G_H_GPIO.h"

#define KEY P05  
#define DOWN    0
#define UP      1

static Key_State_t Last_State = KEY_UP; // 按键状态记录

static void GPIO_Config() {
    P0_MODE_IO_PU(GPIO_Pin_5);
}

void HAL_Key_Init() {
    GPIO_Config();
}

Key_State_t HAL_Key_GetLastState(){//获取上一次的按键状态
    return Last_State;
}

Key_State_t HAL_Key_GetNowState(){//获取当前的按键状态
    return (KEY == DOWN) ? KEY_DOWN : KEY_UP;
}


void HAL_Key_UpdataState(Key_State_t state){//更新按键状态
    Last_State = state;
}




