#include "hal_buzzer.h"
#include "STC8G_H_GPIO.h"
#include "STC8G_H_Switch.h"
#include "STC8G_H_NVIC.h"
#include "STC8H_PWM.h"

#define BUZZER_PIN P34
#define BUZZER_GPIO_PORT GPIO_P3
#define BUZZER_GPIO_PIN GPIO_Pin_4


static void GPIO_Config() {
    GPIO_InitTypeDef GPIO_InitStructure;        // 结构定义
    GPIO_InitStructure.Mode = GPIO_PullUp;        // 指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_InitStructure.Pin = BUZZER_GPIO_PIN;        // 指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7
    GPIO_Inilize(BUZZER_GPIO_PORT, &GPIO_InitStructure); // 初始化
}




static void PWM_Config(u16 hz_value) {
    PWMx_InitDefine PWMx_InitStructure;
    u16 period = 0;
    
    if (hz_value != 0) period = (MAIN_Fosc / hz_value);
    
    PWMx_InitStructure.PWM_Mode = CCMRn_PWM_MODE1;
    PWMx_InitStructure.PWM_Duty = 0.5 * period;
    PWMx_InitStructure.PWM_EnoSelect = hz_value == 0 ? 0 : ENO8P;
    PWM_Configuration(PWM8, &PWMx_InitStructure);
    
    PWMx_InitStructure.PWM_Period = period - 1;
    PWMx_InitStructure.PWM_DeadTime = 0;
    PWMx_InitStructure.PWM_MainOutEnable = ENABLE;
    PWMx_InitStructure.PWM_CEN_Enable = ENABLE;
    PWM_Configuration(PWMB, &PWMx_InitStructure);
    
    PWM8_SW(PWM8_SW_P34);
    NVIC_PWM_Init(PWMB, DISABLE, Priority_0);
}

void HAL_Buzzer_Init() {
    EA = 1;
    EAXSFR();
    GPIO_Config();
    PWM_Config(0);
    BUZZER_PIN=0;//蜂鸣器引脚拉低，防止三极管发烫，配置PWM后引脚会自动输出高电平，但是蜂鸣器需要低电平触发，所以需要拉低
}

void HAL_Buzzer_SetFreq(unsigned int hz_value) {
    // 将标准类型转换为芯片特定类型
    PWM_Config(hz_value);  // 调用硬件相关实现
}

void HAL_Buzzer_Stop() {
    PWM_Config(0);  // 停止
    BUZZER_PIN=0;//蜂鸣器引脚拉低，防止三极管发烫，配置PWM后引脚会自动输出高电平，但是蜂鸣器需要低电平触发，所以需要拉低
}