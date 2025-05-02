#include "key_control.h"


void Key_Init(){
    HAL_Key_Init();
}




/**
 * @brief 按键扫描函数
 * 形参CB的意思时call back的缩写，即回调函数。
 * @param Key_Down 按键按下回调函数指针
 * @param Key_Up 按键松开回调函数指针
 */
void Key_Scan(void (*Key_DownCB)(),void (*Key_UpCB)()) { // 按键扫描函数
    if(HAL_Key_GetNowState()==KEY_DOWN&&HAL_Key_GetLastState()==KEY_UP){// 按键按下
        HAL_Key_UpdataState(KEY_DOWN); // 更新按键状态
        if(Key_DownCB!=NULL)
            Key_DownCB(); // 按键按下回调函数
    }
    if(HAL_Key_GetNowState()==KEY_UP&&HAL_Key_GetLastState()==KEY_DOWN){// 按键松开
        HAL_Key_UpdataState(KEY_UP); // 更新按键状态
        if(Key_UpCB!=NULL)
            Key_UpCB(); // 按键松开回调函数
    }
}