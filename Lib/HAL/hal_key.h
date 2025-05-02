#ifndef HAL_KEY_H
#define HAL_KEY_H

typedef enum {
    KEY_UP,
    KEY_DOWN
} Key_State_t;



void HAL_Key_Init();

// 获取上一次按键状态
Key_State_t HAL_Key_GetLastState();  

//获取当前的按键状态
Key_State_t HAL_Key_GetNowState();


// 更新按键状态
void HAL_Key_UpdataState(Key_State_t state);


#endif // HAL_KEY_H