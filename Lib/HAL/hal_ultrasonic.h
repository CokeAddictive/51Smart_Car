#ifndef HAL_ULTRASONIC_H
#define HAL_ULTRASONIC_H

void HAL_Ultrasonic_Init();

/**
 * @brief 获取超声波距离
 *
 * @param distance 通过指针返回距离，单位：cm
 * @return 返回状态char ----0:成功。 -1:超声波模块无信号 -2:超出测量范围
 */
char HAL_Ultrasonic_GetDistance(float * distance);





#endif // HAL_ULTRASONIC_H