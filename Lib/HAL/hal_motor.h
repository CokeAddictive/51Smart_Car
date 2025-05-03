#ifndef HAL_MOTOR_H
#define HAL_MOTOR_H



typedef struct{
	char LF_Speed;	// 左前轮速度
	char LB_Speed;	// 左后轮速度
	char RF_Speed;	// 右前轮速度
	char RB_Speed;	// 右后轮速度
}MotorSpeed;

// 移动模式左中右
typedef enum{
	LEFT_M, MID_M , RIGHT_M
}MotorsMode;

void HAL_Motors_Init();

void HAL_Motors_Stop();

void HAL_Motor_LeftFront(char speed);

void HAL_Motor_LeftBack(char speed);

void HAL_Motor_RightFront(char speed);

void HAL_Motor_RightBack(char speed);

#endif // HAL_MOTOR_H