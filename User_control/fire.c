/*
* 发射模块
* TODO: 0, 在数据包中加入对应数据字节
*       1，调参使发射方向正确
*       2，调节舵机转速
*/

#include "main.h"
#include "fire.h"
#include "tim.h"


void Fire_Enable(void)
{
	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_Base_Start(&htim3);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
}

//启动电机准备发射
void Motor_Open(void)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,900);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,900);
}

//关闭电机
void Motor_Close(void)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
}

//舵机控制（但360
/*
* >1ms加速反转 1.2ms慢速反转 1.4ms慢速正转 <2.5ms不断加速正转
*/
void Steering_Enging()
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,1400);
}

void Steering_Enging_Close()
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
}

//总发射控制函数
void Fire_fun(uint8_t* store)
{
	if (store[0] == 1)//需给出对应数据字节
	{
		Motor_Open();
		if(store[0] == 1)
		{
			Steering_Enging();
		}
		else Steering_Enging_Close();
	}
	else Motor_Close();
}
