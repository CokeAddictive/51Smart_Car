#ifndef SENSOR_FEEDBACK_H
#define SENSOR_FEEDBACK_H

#include "hal_lightsensor.h"
//已经在hal层中定义通道数，在sensor_feedback.c中使用

void Sensor_Init();

int Sensor_GetError();







#endif // SENSOR_FEEDBACK_H

