/*
*模块控制逻辑
*TODO:0, 调试
*     1.5, 搞清楚数据包的构成
*     1，将速度与方向控制结合用一个坐标参数表示
*     2，装陀螺仪
*/

#include "main.h"
#include "control_fun.h"
#include "tim.h"


//相关定时器通道启用
void MOTOR_Enable(void)
{
	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
}

/*-------------------------------参数初始化----------------------------*/
//电机的运动状态与速度
MOTOR motor_1 = {0,0,0,0};
MOTOR motor_2 = {0,0,0,0};
MOTOR motor_3 = {0,0,0,0};
MOTOR motor_4 = {0,0,0,0};
MOTOR motor_fire_1 = {2,990,1,0};
MOTOR motor_fire_2 = {2,990,1,0};

/*---------------------------------END---------------------------------*/






/*---------------------------状态反应小灯模块-----------------------------*/
//void RGB_CONTROL(void)
//{
//	//rgb提示小灯控制
//	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,100);
//	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_3,100);
//	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_4,100);
//}
/*---------------------------------END---------------------------------*/






/*--------------------------------运动电机模块-------------------------------*/

//八个运动反向电机对应的参数
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







//电机参数设置
void MOTOR_SET(void)
{
	//方向参数转换
	dirction_par_trans();
	//速度设置
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,motor_1.Verb);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,motor_2.Verb);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,motor_3.Verb);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,motor_4.Verb);
	//正反转与停止设置
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








/*-----------------------------信息参数转换------------------------------*/

//蓝牙串口接收信息转化
void RECEIVE_DATE_TRANS(uint8_t* rx_buff_1)//
{
	char par_directioin[2];//方向转向控制，占 1 个字节 
	uint16_t par_verb;//速度控制，占 2 个字节

	//根据数据将速度储存
	//par_verb = (rx_buff_1[3]<<8) + (rx_buff_1[4]);
	par_verb = (uint16_t)rx_buff_1[3];
	motor_1.Verb = par_verb*10;
	motor_2.Verb = par_verb*10;
	motor_3.Verb = par_verb*10;
	motor_4.Verb = par_verb*10;
	
	//转向（只能原地）
	if(!(rx_buff_1[0]&&rx_buff_1[1]))//判断是否停止
	{
		if(rx_buff_1[2] == 2) TURN_RIGHT();//右转
		if(rx_buff_1[2] == 1) TURN_LEFT();//左转
	}
	
	//根据数据判定方向
	switch(rx_buff_1[0]){
		case 0x01:switch(rx_buff_1[1]){
			case 0x01: GO_RIGHT_FRONT();break;//（1,1）
			case 0: GO_RIGHT();break;//      （1,0）
			case 0xFF: GO_LEFT_REAR();break;// （1，-1）
			}
			break;
		case 0:switch(rx_buff_1[1]){
			case 0x01: GO_FORWARD();break;//    （0,1）
			case 0: STOP();break;//          （0，0）
			case 0xFF: GO_BACK();break;//      （0，-1）
			}
			break;
		case 0xFF:switch(rx_buff_1[1]){
			case 0x01: GO_RIGHT_FRONT();break;//（-1,1）
			case 0: GO_LEFT();break;//       （0，-1）
			case 0xFF: GO_LEFT_REAR();break;// （-1，-1）
			}


	}
}

//将每个电机中的方向参数转为pin参数
void dirction_par_trans(void)
{
	dirction_par_trans_left(&motor_1);
	dirction_par_trans_right(&motor_2);
	dirction_par_trans_right(&motor_3);
	dirction_par_trans_left(&motor_4);
}
void dirction_par_trans_left(PTRMOTOR mot)//左右电机正反转对应pin值不同因此设置两个
{
	if(mot->Direction_base == GO_FORWARD_PAR){mot->pin_1 = 1;mot->pin_2 = 0;}//填入前进驱动引脚值
	if(mot->Direction_base == STOP_PAR){mot->pin_1 = 0;mot->pin_2 = 0;}//填入停止驱动引脚值
	if(mot->Direction_base == GO_BACK_PAR){mot->pin_1 = 0;mot->pin_2 = 1;}//填入后退引脚值
}
void dirction_par_trans_right(PTRMOTOR mot)
{
	if(mot->Direction_base == GO_FORWARD_PAR){mot->pin_1 = 0;mot->pin_2 = 1;}//填入前进驱动引脚值
	if(mot->Direction_base == STOP_PAR){mot->pin_1 = 0;mot->pin_2 = 0;}//填入停止驱动引脚值
	if(mot->Direction_base == GO_BACK_PAR){mot->pin_1 = 1;mot->pin_2 = 0;}//填入后退引脚值
}


/*---------------------------------END---------------------------------*/













