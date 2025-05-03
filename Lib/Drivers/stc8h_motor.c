#include "hal_motor.h"

#include "STC8G_H_GPIO.h"
#include "STC8G_H_Switch.h"
#include "STC8H_PWM.h"

#define PERIOD (MAIN_Fosc / 1000)

// 左前轮    left         p
#define LF_P P14
#define LF_N P15

// 左后轮
#define LB_P P20
#define LB_N P21

// 右前轮
#define RF_P P16
#define RF_N P17

// 右后轮
#define RB_P P22
#define RB_N P23

// 引脚重映射
#define MOTOR_GPIO_PORT1 GPIO_P1
#define MOTOR_GPIO_PORT2 GPIO_P2
#define MOTOR_GPIO_PIN0 GPIO_Pin_0
#define MOTOR_GPIO_PIN1 GPIO_Pin_1
#define MOTOR_GPIO_PIN2 GPIO_Pin_2
#define MOTOR_GPIO_PIN3 GPIO_Pin_3
#define MOTOR_GPIO_PIN4 GPIO_Pin_4
#define MOTOR_GPIO_PIN5 GPIO_Pin_5
#define MOTOR_GPIO_PIN6 GPIO_Pin_6
#define MOTOR_GPIO_PIN7 GPIO_Pin_7

// 在文件头部添加函数声明
static char Speed_Convert(char speed);


/**
 * @brief 电机引脚配置,准双向
 */
static void GPIO_Config() {
    GPIO_InitTypeDef GPIO_InitStructure; // 结构定义
    GPIO_InitStructure.Mode = GPIO_PullUp;
    // p14 p15 p16 p17
    GPIO_InitStructure.Pin = MOTOR_GPIO_PIN4 | MOTOR_GPIO_PIN5 | MOTOR_GPIO_PIN6 | MOTOR_GPIO_PIN7;
    GPIO_Inilize(MOTOR_GPIO_PORT1, &GPIO_InitStructure); // 初始化

    // p20 p21 p22 p23
    GPIO_InitStructure.Pin = MOTOR_GPIO_PIN0|MOTOR_GPIO_PIN1 | MOTOR_GPIO_PIN2 | MOTOR_GPIO_PIN3 | MOTOR_GPIO_PIN4;
    GPIO_Inilize(MOTOR_GPIO_PORT2, &GPIO_InitStructure); // 初始化
}

/**
 * @brief PWM基础配置，不涉及模式和通道
 */
static void PWM_Config() {
    PWMx_InitDefine PWM_InitStructure;
    PWM_InitStructure.PWM_Period = PERIOD - 1;    // 周期时间,   0~65535 （通常设置1ms：）
    PWM_InitStructure.PWM_DeadTime = 1;           // 死区发生器设置, 0~255
    PWM_InitStructure.PWM_CEN_Enable = ENABLE;    // 使能计数器, ENABLE,DISABLE
    PWM_InitStructure.PWM_MainOutEnable = ENABLE; // 主输出使能,  ENABLE,DISABLE
    PWM_Configuration(PWMA, &PWM_InitStructure);  // 初始化通道A/B
}

/**
 * @brief 左前轮电机驱动
 * @param speed 带正负号的速度
 */
void HAL_Motor_LeftFront(char speed) {
    char percentage;
    PWMx_InitDefine PWM_InitStructure;
    percentage = Speed_Convert(speed);
    PWM_InitStructure.PWM_Mode = CCMRn_PWM_MODE1; // 模式:
    PWM_InitStructure.PWM_Duty = (percentage / 100.0) * PERIOD;
    PWM_InitStructure.PWM_EnoSelect = percentage != 0 ? (ENO3P | ENO3N) : 0;
    PWM_Configuration(PWM3, &PWM_InitStructure); // 初始化组号
    PWM3_SW(PWM3_SW_P14_P15);
}

/**
 * @brief 左后轮电机驱动
 * @param speed 带正负号的速度
 */
void HAL_Motor_LeftBack(char speed) {
    char percentage;
    PWMx_InitDefine PWM_InitStructure;
    percentage = Speed_Convert(speed);
    PWM_InitStructure.PWM_Mode = CCMRn_PWM_MODE1; // 模式:
    PWM_InitStructure.PWM_Duty = (percentage / 100.0) * PERIOD;
    PWM_InitStructure.PWM_EnoSelect = percentage != 0 ? (ENO1P | ENO1N) : 0;
    PWM_Configuration(PWM1, &PWM_InitStructure); // 初始化组号
    PWM1_SW(PWM1_SW_P20_P21);
}

/**
 * @brief 右前轮电机驱动
 * @param speed 带正负号的速度
 */
void HAL_Motor_RightFront(char speed) {
    char percentage;
    PWMx_InitDefine PWM_InitStructure;
    percentage = Speed_Convert(speed);
    PWM_InitStructure.PWM_Mode = CCMRn_PWM_MODE2; // 模式:
    PWM_InitStructure.PWM_Duty = (percentage / 100.0) * PERIOD;
    PWM_InitStructure.PWM_EnoSelect = percentage != 0 ? (ENO4P | ENO4N) : 0;
    PWM_Configuration(PWM4, &PWM_InitStructure); // 初始化组号
    PWM4_SW(PWM4_SW_P16_P17);
}

/**
 * @brief 右后轮电机驱动
 * @param speed 带正负号的速度
 */
void HAL_Motor_RightBack(char speed) {
    char percentage;
    PWMx_InitDefine PWM_InitStructure;
    percentage = Speed_Convert(speed);
    PWM_InitStructure.PWM_Mode = CCMRn_PWM_MODE2; // 模式:
    PWM_InitStructure.PWM_Duty = (percentage / 100.0) * PERIOD;
    PWM_InitStructure.PWM_EnoSelect = percentage != 0 ? (ENO2P | ENO2N) : 0;
    PWM_Configuration(PWM2, &PWM_InitStructure); // 初始化组号
    PWM2_SW(PWM2_SW_P22_P23);
}

/**
 * @brief 将[-100,100]的速度范围转换为[0,100]的PWM占空比
 *
 * @param speed
 * @return char
 */
static char Speed_Convert(char speed) {
    char value = speed / 2 + 50;
    if (value > 100)
        value = 100;
    else if (value < 0)
        value = 0;
    return value;
}

/**
 * @brief 驱动电机初始化
 */
void HAL_Motors_Init() {
    EAXSFR(); /* 扩展寄存器访问使能 */
    GPIO_Config();//电机引脚配置
    PWM_Config();//PWM基础配置初始化(不含模式、占空比、通道、引脚切换)
}

void HAL_Motors_Stop() {
    HAL_Motor_LeftFront(0);
    HAL_Motor_LeftBack(0);
    HAL_Motor_RightFront(0);
    HAL_Motor_RightBack(0);
}

