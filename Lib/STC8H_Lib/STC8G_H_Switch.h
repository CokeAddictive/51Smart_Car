/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCAI.com ---------------------------------------------*/
/* --- BBS: www.STCAIMCU.com  -----------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序            */
/*---------------------------------------------------------------------*/

#ifndef	__STC8G_H_SWITCH_H
#define	__STC8G_H_SWITCH_H

#include "config.h"

//========================================================================
//                            功能脚切换设置
//========================================================================

#define  UART1_SW(Pin)				P_SW1 = (P_SW1 & 0x3F) | (Pin << 6)
#define  PCA_SW(Pin)				P_SW1 = (P_SW1 & 0xCF) | (Pin << 4)
#define  SPI_SW(Pin)				P_SW1 = (P_SW1 & 0xF3) | (Pin << 2)
#define  I2C_SW(Pin)				P_SW2 = (P_SW2 & 0xCF) | (Pin << 4)
#define  COMP_SW(Pin)				P_SW2 = (P_SW2 & 0xF7) | (Pin << 3)
#define  UART4_SW(Pin)				P_SW2 = (P_SW2 & 0xFB) | (Pin << 2)
#define  UART3_SW(Pin)				P_SW2 = (P_SW2 & 0xFD) | (Pin << 1)
#define  UART2_SW(Pin)				P_SW2 = (P_SW2 & 0xFE) | (Pin)

#define  MCLKO_SW(Pin)				MCLKOCR = (MCLKOCR & 0x7F) | (Pin << 7)
#define  T3T4SEL_SW(Pin)			T3T4PIN = (T3T4PIN & 0xFE) | (Pin)

#define  PWM1_SW(Pin)				PWMA_PS = (PWMA_PS & 0xFC) | (Pin)
#define  PWM2_SW(Pin)				PWMA_PS = (PWMA_PS & 0xF3) | (Pin << 2)
#define  PWM3_SW(Pin)				PWMA_PS = (PWMA_PS & 0xCF) | (Pin << 4)
#define  PWM4_SW(Pin)				PWMA_PS = (PWMA_PS & 0x3F) | (Pin << 6)

#define  PWM5_SW(Pin)				PWMB_PS = (PWMB_PS & 0xFC) | (Pin)
#define  PWM6_SW(Pin)				PWMB_PS = (PWMB_PS & 0xF3) | (Pin << 2)
#define  PWM7_SW(Pin)				PWMB_PS = (PWMB_PS & 0xCF) | (Pin << 4)
#define  PWM8_SW(Pin)				PWMB_PS = (PWMB_PS & 0x3F) | (Pin << 6)

#define  PWMA_ETR_SW(Pin)			PWMA_ETRPS = (PWMA_ETRPS & 0xFC) | (Pin)
#define  PWMB_ETR_SW(Pin)			PWMB_ETRPS = (PWMB_ETRPS & 0xFC) | (Pin)

#define  PWMA_BRK_SW(Pin)			PWMA_ETRPS = (PWMA_ETRPS & 0xFB) | (Pin << 2)
#define  PWMB_BRK_SW(Pin)			PWMB_ETRPS = (PWMB_ETRPS & 0xFB) | (Pin << 2)

//========================================================================
//                              定义声明
//========================================================================

#define	UART1_SW_P30_P31	0
#define	UART1_SW_P36_P37	1
#define	UART1_SW_P16_P17	2
#define	UART1_SW_P43_P44	3

#define	UART2_SW_P10_P11	0
#define	UART2_SW_P46_P47	1
#define	UART3_SW_P00_P01	0
#define	UART3_SW_P50_P51	1
#define	UART4_SW_P02_P03	0
#define	UART4_SW_P52_P53	1

#define	I2C_P14_P15				0
#define	I2C_P24_P25				1
#define	I2C_P76_P77				2
#define	I2C_P33_P32				3

#define	CMP_OUT_P34				0
#define	CMP_OUT_P41				1

#define	PCA_P12_P11_P10_P37		0
#define	PCA_P34_P35_P36_P37		1
#define	PCA_P24_P25_P26_P27		2

#define	SPI_P12_P13_P14_P15		0
#define	SPI_P22_P23_P24_P25		1
#define	SPI_P54_P40_P41_P43		2
#define	SPI_P35_P34_P33_P32		3

#define	T3T4_P04_P05_P06_P07	0
#define	T3T4_P00_P01_P02_P03	1

#define	MCLKO_SW_P54			0
#define	MCLKO_SW_P16			1

#define	PWM1_SW_P10_P11		0
#define	PWM1_SW_P20_P21		1
#define	PWM1_SW_P60_P61		2

#define	PWM2_SW_P12_P13		0
#define	PWM2_SW_P22_P23		1
#define	PWM2_SW_P62_P63		2

#define	PWM3_SW_P14_P15		0
#define	PWM3_SW_P24_P25		1
#define	PWM3_SW_P64_P65		2

#define	PWM4_SW_P16_P17		0
#define	PWM4_SW_P26_P27		1
#define	PWM4_SW_P66_P67		2
#define	PWM4_SW_P34_P33		3

#define	PWM5_SW_P20				0
#define	PWM5_SW_P17				1
#define	PWM5_SW_P00				2
#define	PWM5_SW_P74				3

#define	PWM6_SW_P21				0
#define	PWM6_SW_P54				1
#define	PWM6_SW_P01				2
#define	PWM6_SW_P75				3

#define	PWM7_SW_P22				0
#define	PWM7_SW_P33				1
#define	PWM7_SW_P02				2
#define	PWM7_SW_P76				3

#define	PWM8_SW_P23				0
#define	PWM8_SW_P34				1
#define	PWM8_SW_P03				2
#define	PWM8_SW_P77				3

#define	PWMA_ETR_P32			0
#define	PWMA_ETR_P41			1
#define	PWMA_ETR_P73			2

#define	PWMB_ETR_P32			0
#define	PWMB_ETR_P06			1

#define	PWMA_BRK_P35			0
#define	PWMA_BRK_CMP			1

#define	PWMB_BRK_P35			0
#define	PWMB_BRK_CMP			1

#endif
