#include "hal_lightsensor.h"

#include "STC8G_H_GPIO.h"

#if HAL_Sensor_CHANNEL == 3
#define LED_L1 P01 // 左1	-32
#define LED0 P02   // 中	0
#define LED_R1 P03 // 右1	32
#define Sensor_GPIO_PORT GPIO_P0
#define Sensor_GPIO_PINL1 GPIO_Pin_1
#define Sensor_GPIO_PIN0 GPIO_Pin_2
#define Sensor_GPIO_PINR1 GPIO_Pin_3
#elif HAL_Sensor_CHANNEL == 5
#define LED_L2 P00 // 左2	-64
#define LED_L1 P01 // 左1	-32
#define LED0 P02   // 中	0
#define LED_R1 P03 // 右1	32
#define LED_R2 P04 // 右2	64
#define Sensor_GPIO_PORT GPIO_P0
#define Sensor_GPIO_PINL2 GPIO_Pin_0
#define Sensor_GPIO_PINL1 GPIO_Pin_1
#define Sensor_GPIO_PIN0 GPIO_Pin_2
#define Sensor_GPIO_PINR1 GPIO_Pin_3
#define Sensor_GPIO_PINR2 GPIO_Pin_4
#endif

static int last_error = 0; // 上一次的状态

static void GPIO_Config() {
    GPIO_InitTypeDef GPIO_InitStructure; // 结构定义
    GPIO_InitStructure.Mode = GPIO_PullUp;
#if HAL_Sensor_CHANNEL == 3
    GPIO_InitStructure.Pin = Sensor_GPIO_PINL1 | Sensor_GPIO_PIN0 | Sensor_GPIO_PINR1;
    GPIO_Inilize(Sensor_GPIO_PORT, &GPIO_InitStructure);
#elif HAL_Sensor_CHANNEL == 5
    GPIO_InitStructure.Pin = Sensor_GPIO_PINL2 | Sensor_GPIO_PINL1 | Sensor_GPIO_PIN0 | Sensor_GPIO_PINR1 | Sensor_GPIO_PINR2;
    GPIO_Inilize(Sensor_GPIO_PORT, &GPIO_InitStructure);
#endif
}

void HAL_Sensor_Init() {
    GPIO_Config();
}

/**
 * @brief 获取偏差值
 * @return int 偏差值
 */
int HAL_Sensor_GetError() {
    int error = 0;
    u8 cnt = 0; // 一共被几个传感器检测到

#if HAL_Sensor_CHANNEL == 3
    if (LED_L1 == 1) { // 左2
        error += -32;
        cnt++;
    }
    if (LED0 == 1) { // 中间
        error += 0;
        cnt++;
    }
    if (LED_R1 == 1) { // 右1
        error += 32;
        cnt++;
    }

#elif HAL_Sensor_CHANNEL == 5
    if (LED_L2 == 1) { // 左1
        error += -64;
        cnt++;
    }
    if (LED_L1 == 1) { // 左2
        error += -32;
        cnt++;
    }
    if (LED0 == 1) { // 中间
        error += 0;
        cnt++;
    }
    if (LED_R1 == 1) { // 右1
        error += 32;
        cnt++;
    }
    if (LED_R2 == 1) { // 右2
        error += 64;
        cnt++;
    }
#endif
    if (cnt == 0) { // 没有压到黑线，返回上一次的状态
        return last_error;
    }
    error = error / cnt; // 当前
    last_error = error;  // 更新状态
    return error;
}
