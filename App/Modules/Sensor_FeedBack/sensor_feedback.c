#include "sensor_feedback.h"

void Sensor_Init() {
    HAL_Sensor_Init();
}

int Sensor_GetError() {
    return HAL_Sensor_GetError();
}
