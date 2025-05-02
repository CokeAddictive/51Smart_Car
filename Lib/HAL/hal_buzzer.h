#ifndef HAL_BUZZER_H
#define HAL_BUZZER_H


void HAL_Buzzer_Init();
void HAL_Buzzer_SetFreq(unsigned int hz_value);  // 使用标准类型
void HAL_Buzzer_Stop();
#endif // HAL_BUZZER_H