/*
*ģ������߼�
*TODO:0, ����
*     1.5, ��������ݰ��Ĺ���
*     1�����ٶ��뷽����ƽ����һ�����������ʾ
*     2��װ������
*/

#include "main.h"
#include "control_fun.h"
#include "tim.h"


//��ض�ʱ��ͨ������
void MOTOR_Enable(void)
{
	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
}

/*-------------------------------������ʼ��----------------------------*/
//������˶�״̬���ٶ�
MOTOR motor_1 = {0,0,0,0};
MOTOR motor_2 = {0,0,0,0};
MOTOR motor_3 = {0,0,0,0};
MOTOR motor_4 = {0,0,0,0};
MOTOR motor_fire_1 = {2,990,1,0};
MOTOR motor_fire_2 = {2,990,1,0};

/*---------------------------------END---------------------------------*/






/*---------------------------״̬��ӦС��ģ��-----------------------------*/
//void RGB_CONTROL(void)
//{
//	//rgb��ʾС�ƿ���
//	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,100);
//	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_3,100);
//	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_4,100);
//}
/*---------------------------------END---------------------------------*/






/*--------------------------------�˶����ģ��-------------------------------*/

//�˸��˶���������Ӧ�Ĳ���
void GO_FORWARD(void)
{
	motor_1.Direction_base = 2;
	motor_2.Direction_base = 2;
	motor_3.Direction_base = 2;
	motor_4.Direction_base = 2;
}
void GO_RIGHT(void)
{
	motor_1.Direction_base = 2;
	motor_2.Direction_base = 0;
	motor_3.Direction_base = 2;
	motor_4.Direction_base = 0;
}
void GO_LEFT(void)
{
	motor_1.Direction_base = 0;
	motor_2.Direction_base = 2;
	motor_3.Direction_base = 0;
	motor_4.Direction_base = 2;
}
void GO_BACK(void)
{
	motor_1.Direction_base = 0;
	motor_2.Direction_base = 0;
	motor_3.Direction_base = 0;
	motor_4.Direction_base = 0;
}
void GO_RIGHT_FRONT(void)
{
	motor_1.Direction_base = 2;
	motor_2.Direction_base = 1;
	motor_3.Direction_base = 2;
	motor_4.Direction_base = 1;
}
void GO_LEFT_FRONT(void)
{
	motor_1.Direction_base = 1;
	motor_2.Direction_base = 2;
	motor_3.Direction_base = 1;
	motor_4.Direction_base = 2;
}
void GO_LEFT_REAR(void)
{
	motor_1.Direction_base = 0;
	motor_2.Direction_base = 1;
	motor_3.Direction_base = 0;
	motor_4.Direction_base = 1;
}
void GO_RIGHT_REAR(void)
{
	motor_1.Direction_base = 1;
	motor_2.Direction_base = 0;
	motor_3.Direction_base = 1;
	motor_4.Direction_base = 0;
}
void TURN_RIGHT(void)
{
	motor_1.Direction_base = 2;
	motor_2.Direction_base = 0;
	motor_3.Direction_base = 0;
	motor_4.Direction_base = 2;
}
void TURN_LEFT(void)
{
	motor_1.Direction_base = 0;
	motor_2.Direction_base = 2;
	motor_3.Direction_base = 2;
	motor_4.Direction_base = 0;
}
void STOP(void)
{
	motor_1.Direction_base = 1;
	motor_2.Direction_base = 1;
	motor_3.Direction_base = 1;
	motor_4.Direction_base = 1;
}







//�����������
void MOTOR_SET(void)
{
	//�������ת��
	dirction_par_trans();
	//�ٶ�����
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,motor_1.Verb);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,motor_2.Verb);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,motor_3.Verb);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,motor_4.Verb);
	//����ת��ֹͣ����
	HAL_GPIO_WritePin(motor1_pin1_GPIO_Port,motor1_pin1_Pin,motor_1.pin_1);
	HAL_GPIO_WritePin(motor1_pin2_GPIO_Port,motor1_pin2_Pin,motor_1.pin_2);
	HAL_GPIO_WritePin(motor2_pin1_GPIO_Port,motor2_pin1_Pin,motor_2.pin_1);
	HAL_GPIO_WritePin(motor2_pin2_GPIO_Port,motor2_pin2_Pin,motor_2.pin_2);
	HAL_GPIO_WritePin(motor3_pin1_GPIO_Port,motor3_pin1_Pin,motor_3.pin_1);
	HAL_GPIO_WritePin(motor3_pin2_GPIO_Port,motor3_pin2_Pin,motor_3.pin_2);
	HAL_GPIO_WritePin(motor4_pin1_GPIO_Port,motor4_pin1_Pin,motor_4.pin_1);
	HAL_GPIO_WritePin(motor4_pin2_GPIO_Port,motor4_pin2_Pin,motor_4.pin_2);
}

/*---------------------------------END---------------------------------*/








/*-----------------------------��Ϣ����ת��------------------------------*/

//�������ڽ�����Ϣת��
void RECEIVE_DATE_TRANS(uint8_t* rx_buff_1)//
{
	char par_directioin[2];//����ת����ƣ�ռ 1 ���ֽ� 
	uint16_t par_verb;//�ٶȿ��ƣ�ռ 2 ���ֽ�

	//�������ݽ��ٶȴ���
	//par_verb = (rx_buff_1[3]<<8) + (rx_buff_1[4]);
	par_verb = (uint16_t)rx_buff_1[3];
	motor_1.Verb = par_verb*10;
	motor_2.Verb = par_verb*10;
	motor_3.Verb = par_verb*10;
	motor_4.Verb = par_verb*10;
	
	//ת��ֻ��ԭ�أ�
	if(!(rx_buff_1[0]&&rx_buff_1[1]))//�ж��Ƿ�ֹͣ
	{
		if(rx_buff_1[2] == 2) TURN_RIGHT();//��ת
		if(rx_buff_1[2] == 1) TURN_LEFT();//��ת
	}
	
	//���������ж�����
	switch(rx_buff_1[0]){
		case 0x01:switch(rx_buff_1[1]){
			case 0x01: GO_RIGHT_FRONT();break;//��1,1��
			case 0: GO_RIGHT();break;//      ��1,0��
			case 0xFF: GO_LEFT_REAR();break;// ��1��-1��
			}
			break;
		case 0:switch(rx_buff_1[1]){
			case 0x01: GO_FORWARD();break;//    ��0,1��
			case 0: STOP();break;//          ��0��0��
			case 0xFF: GO_BACK();break;//      ��0��-1��
			}
			break;
		case 0xFF:switch(rx_buff_1[1]){
			case 0x01: GO_RIGHT_FRONT();break;//��-1,1��
			case 0: GO_LEFT();break;//       ��0��-1��
			case 0xFF: GO_LEFT_REAR();break;// ��-1��-1��
			}


	}
}

//��ÿ������еķ������תΪpin����
void dirction_par_trans(void)
{
	dirction_par_trans_left(&motor_1);
	dirction_par_trans_right(&motor_2);
	dirction_par_trans_right(&motor_3);
	dirction_par_trans_left(&motor_4);
}
void dirction_par_trans_left(PTRMOTOR mot)//���ҵ������ת��Ӧpinֵ��ͬ�����������
{
	if(mot->Direction_base == GO_FORWARD_PAR){mot->pin_1 = 1;mot->pin_2 = 0;}//����ǰ����������ֵ
	if(mot->Direction_base == STOP_PAR){mot->pin_1 = 0;mot->pin_2 = 0;}//����ֹͣ��������ֵ
	if(mot->Direction_base == GO_BACK_PAR){mot->pin_1 = 0;mot->pin_2 = 1;}//�����������ֵ
}
void dirction_par_trans_right(PTRMOTOR mot)
{
	if(mot->Direction_base == GO_FORWARD_PAR){mot->pin_1 = 0;mot->pin_2 = 1;}//����ǰ����������ֵ
	if(mot->Direction_base == STOP_PAR){mot->pin_1 = 0;mot->pin_2 = 0;}//����ֹͣ��������ֵ
	if(mot->Direction_base == GO_BACK_PAR){mot->pin_1 = 1;mot->pin_2 = 0;}//�����������ֵ
}


/*---------------------------------END---------------------------------*/













