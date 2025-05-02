#include "battery_feedback.h"

void Battery_Init(){
    HAL_Battery_Init();
}


float Battery_GetVoltage(){
    return HAL_Battery_GetVoltage();
}