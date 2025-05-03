#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "hal_motor.h"

/* 
当前枚举定义在hal层
typedef enum {
    LEFT_M,   // 左侧电机模式
    MID_M,    // 中间/双侧模式 
    RIGHT_M   // 右侧电机模式
} MotorsMode;
*/

void Motors_Init();

void Motors_Stop();

void Motors_ForWard(char speed, MotorsMode mode);

void Motors_BackWard(char speed, MotorsMode mode);

void Motors_Translation(char speed, MotorsMode mode);

void Motors_Whirl(char speed, MotorsMode mode);


void Motors_GradualStop();    // 渐进式刹车



#endif // MOTOR_CONTROL_H