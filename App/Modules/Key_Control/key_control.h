#ifndef KEY_CONTROL_H
#define KEY_CONTROL_H

#include "hal_key.h"
#include "STDDEF.H"

void Key_Init();

void Key_Scan(void (*Key_DownCB)(), void (*Key_UpCB)());

#endif // KEY_CONTROL_H

