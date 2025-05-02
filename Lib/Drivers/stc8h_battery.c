#include "hal_battery.h"

#include "STC8G_H_ADC.h"
#include "STC8G_H_GPIO.h"
#include "STC8G_H_NVIC.h"

// p13引脚，CH3通道
#define BATTERY_ADC_CH ADC_CH3
#define BATTERY_GPIO_PORT GPIO_P1
#define BATTERY_GPIO_PIN GPIO_Pin_3

static void GPIO_Config() {                       // 高阻输入模式
    GPIO_InitTypeDef GPIO_InitStructure;          // 结构定义
    GPIO_InitStructure.Mode = GPIO_HighZ;         // 指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_InitStructure.Pin = BATTERY_GPIO_PIN;            // 指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7
    GPIO_Inilize(BATTERY_GPIO_PORT, &GPIO_InitStructure); // 初始化
}

static void ADC_Config() {
    ADC_InitTypeDef ADC_InitStructure;                     // 结构定义
    ADC_InitStructure.ADC_SMPduty = 31;                    // ADC 模拟信号采样时间控制, 0~31（注意： SMPDUTY 一定不能设置小于 10）
    ADC_InitStructure.ADC_CsSetup = 0;                     // ADC 通道选择时间控制 0(默认),1
    ADC_InitStructure.ADC_CsHold = 1;                      // ADC 通道选择保持时间控制 0,1(默认),2,3
    ADC_InitStructure.ADC_Speed = ADC_SPEED_2X1T;          // 设置 ADC 工作时钟频率	ADC_SPEED_2X1T~ADC_SPEED_2X16T
    ADC_InitStructure.ADC_AdjResult = ADC_RIGHT_JUSTIFIED; // ADC结果调整,	ADC_LEFT_JUSTIFIED,ADC_RIGHT_JUSTIFIED
    ADC_Inilize(&ADC_InitStructure);                       // 初始化
    ADC_PowerControl(ENABLE);                              // ADC电源开关, ENABLE或DISABLE
    NVIC_ADC_Init(DISABLE, Priority_0);                    // 中断使能, ENABLE/DISABLE; 优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
}

void HAL_Battery_Init() { // 电池初始化
    GPIO_Config();
    ADC_Config();
}

float HAL_Battery_GetVoltage() { // 获取电池电压
    u16 adc;
	float vol;
	// 采样值
	adc = Get_ADCResult(BATTERY_ADC_CH);
	// 电压转换
	vol = adc * 2.5 / 4095;
	
	return vol * 6.1;
}