#ifndef BATTERY_FEEDBACK_H
#define BATTERY_FEEDBACK_H

#include "hal_battery.h"


// 初始化
void Battery_Init();

// 获取电压
float Battery_GetVoltage();


#endif // BATTERY_FEEDBACK_H