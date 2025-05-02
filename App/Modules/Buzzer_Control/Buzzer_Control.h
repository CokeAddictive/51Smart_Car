#ifndef BUZZER_CONTROL_H
#define BUZZER_CONTROL_H

#include "hal_buzzer.h"
#include "RTX51TNY.H"

void Buzzer_Init();

void Buzzer_SetFreq(unsigned int hz_value);//设置蜂鸣器频率

void Buzzer_Alarm();//蜂鸣器报警

void Buzzer_Stop();//蜂鸣器停止

#endif // BUZZER_CONTROL_H