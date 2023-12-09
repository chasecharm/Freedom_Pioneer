/*
* ����ģ��
* TODO: 0, �����ݰ��м����Ӧ�����ֽ�
*       1������ʹ���䷽����ȷ
*       2�����ڶ��ת��
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

//�������׼������
void Motor_Open(void)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,900);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,900);
}

//�رյ��
void Motor_Close(void)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
}

//������ƣ���360
/*
* >1ms���ٷ�ת 1.2ms���ٷ�ת 1.4ms������ת <2.5ms���ϼ�����ת
*/
void Steering_Enging()
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,1400);
}

void Steering_Enging_Close()
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
}

//�ܷ�����ƺ���
void Fire_fun(uint8_t* store)
{
	if (store[0] == 1)//�������Ӧ�����ֽ�
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
