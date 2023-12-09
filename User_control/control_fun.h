/*
*模块控制函数与相应参数定义
*/

#ifndef _CONTROL_FUN_H
#define _CONTROL_FUN_H
#include "stdint.h"

//电机相关
#define GO_FORWARD_PAR 2
#define STOP_PAR 1
#define GO_BACK_PAR 0
#define bool char
	


//各种参数定义-----------------------------------------------
/*--电机--*/

typedef struct motor{
	uint8_t Direction_base; 
	uint16_t Verb;
	bool pin_1;
	bool pin_2;
	
}MOTOR,*PTRMOTOR;






//函数声明----------------------------------------------------


void MOTOR_Enable(void);
void RGB_CONTROL(void);

/*运动电机相关*/
void dirction_par_trans_left(PTRMOTOR);
void dirction_par_trans_right(PTRMOTOR);
void dirction_par_trans(void);
void MOTOR_SET(void);
void RECEIVE_DATE_TRANS(uint8_t*);
void GO_FORWARD(void);
void GO_RIGHT(void);
void GO_LEFT(void);
void GO_BACK(void);
void GO_RIGHT_FRONT(void);
void GO_LEFT_FRONT(void);
void GO_LEFT_REAR(void);
void GO_RIGHT_REAR(void);
void TURN_RIGHT(void);
void TURN_LEFT(void);
void STOP(void);
/*发射电机相关*/
void FIRE_PREPARE(void);
void FIRE(void);
	



#endif