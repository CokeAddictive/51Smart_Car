#ifndef HAL_LIGHTSENSOR_H
#define HAL_LIGHTSENSOR_H

#define HAL_Sensor_CHANNEL 3 // 在此处定义通道数(3或5)
void HAL_Sensor_Init();

int HAL_Sensor_GetError();


#endif // HAL_LIGHTSENSOR_H