#include "hal_ultrasonic.h"

#include "STC8G_H_Delay.h"
#include "STC8G_H_GPIO.h"
#include "STDIO.H"


#define ULTRASONIC_TRIG P47
#define ULTRASONIC_ECHO P33
#define ULTRASONIC_LIGHT P27 // 超声波指示灯，本质上不属于超声波模块

// P47引脚重映射
#define ULTRASONIC_GPIO_TRIG_PORT GPIO_P4
#define ULTRASONIC_GPIO_TRIG_PIN GPIO_Pin_7
// P33引脚重映射
#define ULTRASONIC_GPIO_ECHO_PORT GPIO_P3
#define ULTRASONIC_GPIO_ECHO_PIN GPIO_Pin_3
// P27引脚重映射
#define ULTRASONIC_GPIO_LIGHT_PORT GPIO_P2
#define ULTRASONIC_GPIO_LIGHT_PIN GPIO_Pin_7

#define ULTRASONIC_MAX_DISTANCE 400 // 超声波最大测量距离，单位：cm
#define ULTRASONIC_MIN_DISTANCE 2   // 超声波最小测量距离，单位：cm

static void GPIO_Config() {
    // 配置超声波ECHO
    GPIO_InitTypeDef GPIO_InitStructure;                          // 结构定义
    GPIO_InitStructure.Mode = GPIO_HighZ;                        // 指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_InitStructure.Pin = ULTRASONIC_GPIO_ECHO_PIN;            // 指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7
    GPIO_Inilize(ULTRASONIC_GPIO_ECHO_PORT, &GPIO_InitStructure); // 初始化
    // 配置超声波TRIG
    GPIO_InitStructure.Mode = GPIO_OUT_PP;                         // 指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_InitStructure.Pin = ULTRASONIC_GPIO_TRIG_PIN;            // 指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7
    GPIO_Inilize(ULTRASONIC_GPIO_TRIG_PORT, &GPIO_InitStructure); // 初始化
    //配置超声波指示灯
    GPIO_InitStructure.Mode = GPIO_PullUp;                         // 指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_InitStructure.Pin = ULTRASONIC_GPIO_LIGHT_PIN;            // 指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7
    GPIO_Inilize(ULTRASONIC_GPIO_LIGHT_PORT, &GPIO_InitStructure); // 初始化
}

static void Delay10us() { //@24.000MHz
    unsigned char data i;
    i = 78;
    while (--i);
}

void HAL_Ultrasonic_Init() { // 超声波初始化
    GPIO_Config();
    ULTRASONIC_TRIG = 0; // 初始trig拉低，防止第一次测距失效
    ULTRASONIC_LIGHT = 0; // 关闭超声波指示灯
}

/**
 * @brief 获取超声波距离
 *
 * @param distance 通过指针返回距离，单位：cm
 * @return 返回状态char ----0:成功。 -1:超声波模块无信号 -2:超出测量范围
 */
char HAL_Ultrasonic_GetDistance(float *distance) {
    u16 count;            // 计数器;
    ULTRASONIC_LIGHT = 0; // 关闭超声波指示灯

    // 1. 至少给trig 10us高电平时间，再拉低(我们给20)
    ULTRASONIC_TRIG = 1;
    Delay10us();
    Delay10us();
    ULTRASONIC_TRIG = 0;

    // 2. 等待2ms超声波硬件返回数据
    delay_ms(2);

    // 3. 计算echo低电平持续时间，超时返回错误码（echo高电平时退出循环)
    count = 0;
    do {
        Delay10us();
        count++;
    } while (ULTRASONIC_ECHO == 0 && count < 30);
    if (count >= 30)
        return -1; // 超时

    // 4. 计算echo高电平持续时间，超时返回错误码（echo低电平时退出循环)
    count = 0;
    do {
        Delay10us();
        count++;
    } while (ULTRASONIC_ECHO == 1);
    // 5. 计算距离 (高电平时间us * 声速343m/s) / 2
    /*转换为cm单位：34300cm/s = 0.0343cm/us
    单程距离(cm) = (时间(us) × 0.0343cm/us) / 2
             = 时间 × (0.0343/2)
             = 时间 × 0.01715
    */
   *distance = ((count * 0.01) * 34) / 2;

    printf("原始距离:%.2f\n", *distance);


    // 6. 距离范围判断，有效值时2cm-400cm
    if( *distance > ULTRASONIC_MAX_DISTANCE || *distance < ULTRASONIC_MIN_DISTANCE ){
        return -2; // 超出范围
    }

    // 7. 正常返回,并打开超声波指示灯
    ULTRASONIC_LIGHT = 1;
    return 0;
}