#include "motor_control.h"

void Motors_Init() {
    HAL_Motors_Init();
}

/**
 * @brief 前进
 * 
 * @param speed 速度 0-100
 * @param mode LEFT_M, MID_M , RIGHT_M
 */
void Motors_ForWard(char speed, MotorsMode mode) {
    if (mode == LEFT_M) {
        HAL_Motor_LeftFront(0);
        HAL_Motor_LeftBack(speed);
        HAL_Motor_RightFront(speed);
        HAL_Motor_RightBack(0);
    } else if (mode == MID_M) {
        HAL_Motor_LeftFront(speed);
        HAL_Motor_LeftBack(speed);
        HAL_Motor_RightFront(speed);
        HAL_Motor_RightBack(speed);
    } else if (mode == RIGHT_M) {
        HAL_Motor_LeftFront(speed);
        HAL_Motor_LeftBack(0);
        HAL_Motor_RightFront(0);
        HAL_Motor_RightBack(speed);
    }
}

/**
 * @brief 后退
 * 
 * @param speed 速度 0-100
 * @param mode LEFT_M, MID_M , RIGHT_M
 */
void Motors_BackWard(char speed, MotorsMode mode) {
    if (mode == LEFT_M) {
        HAL_Motor_LeftFront(-speed);
        HAL_Motor_LeftBack(0);
        HAL_Motor_RightFront(0);
        HAL_Motor_RightBack(-speed);
    } else if (mode == MID_M) {
        HAL_Motor_LeftFront(-speed);
        HAL_Motor_LeftBack(-speed);
        HAL_Motor_RightFront(-speed);
        HAL_Motor_RightBack(-speed);
    } else if (mode == RIGHT_M) {
        HAL_Motor_LeftFront(0);
        HAL_Motor_LeftBack(-speed);
        HAL_Motor_RightFront(-speed);
        HAL_Motor_RightBack(0);
    }
}

/**
 * @brief 平移
 * 
 * @param speed 速度 0-100
 * @param mode LEFT_M, RIGHT_M
 */
void Motors_Translation(char speed, MotorsMode mode) {
    if (mode == LEFT_M) {
        HAL_Motor_LeftFront(-speed);
        HAL_Motor_LeftBack(speed);
        HAL_Motor_RightFront(speed);
        HAL_Motor_RightBack(-speed);
    } else if (mode == RIGHT_M) {
        HAL_Motor_LeftFront(speed);
        HAL_Motor_LeftBack(-speed);
        HAL_Motor_RightFront(-speed);
        HAL_Motor_RightBack(speed);
    }
}
/**
 * @brief 旋转
 * 
 * @param speed 速度 0-100
 * @param mode LEFT_M, RIGHT_M
 */
void Motors_Whirl(char speed, MotorsMode mode) {
    if (mode == LEFT_M) {
        HAL_Motor_LeftFront(-speed);
        HAL_Motor_LeftBack(-speed);
        HAL_Motor_RightFront(speed);
        HAL_Motor_RightBack(speed);
    } else if (mode == RIGHT_M) {
        HAL_Motor_LeftFront(speed);
        HAL_Motor_LeftBack(speed);
        HAL_Motor_RightFront(-speed);
        HAL_Motor_RightBack(-speed);
    }
}
/**
 * @brief 转弯
 * 
 * @param speed 速度 0-100
 * @param mode LEFT_M, RIGHT_M
 */
void Motors_Turn(char speed, MotorsMode mode) {
    if (mode == LEFT_M) {
        HAL_Motor_LeftFront(0);
        HAL_Motor_LeftBack(0);
        HAL_Motor_RightFront(speed);
        HAL_Motor_RightBack(speed);
    } else if (mode == RIGHT_M) {
        HAL_Motor_LeftFront(speed);
        HAL_Motor_LeftBack(speed);
        HAL_Motor_RightFront(0);
        HAL_Motor_RightBack(0);
    }
}







// 停止 
void Motors_Stop() {
    HAL_Motors_Stop();
}




