#include "Buzzer_Control.h"

code unsigned int FREQS[] = {523, 587, 659, 698, 784, 880, 988};

void Buzzer_Init() {
    HAL_Buzzer_Init();
}

void Buzzer_SetFreq(unsigned int hz_value) {
    HAL_Buzzer_SetFreq(hz_value);
}

void Buzzer_Alarm() {
    char j = 0;
    Buzzer_SetFreq(FREQS[6]);
    os_wait2(K_IVL, 20);

    Buzzer_Stop();
    os_wait2(K_IVL, 20);

    Buzzer_SetFreq(FREQS[5]);
    os_wait2(K_IVL, 20);

    Buzzer_Stop();
    os_wait2(K_IVL, 20);
}

void Buzzer_Stop() {
    HAL_Buzzer_Stop();
}
