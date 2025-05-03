#ifndef ULTRASONIC_FEEDBACK_H
#define ULTRASONIC_FEEDBACK_H

#include "hal_ultrasonic.h"

void Ultrasonic_Init();

char Ultrasonic_GetDistance(float *distance);

#endif // ULTRASONIC_FEEDBACK_H