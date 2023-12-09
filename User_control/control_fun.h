/*
*ģ����ƺ�������Ӧ��������
*/

#ifndef _CONTROL_FUN_H
#define _CONTROL_FUN_H
#include "stdint.h"

//������
#define GO_FORWARD_PAR 2
#define STOP_PAR 1
#define GO_BACK_PAR 0
#define bool char
	


//���ֲ�������-----------------------------------------------
/*--���--*/

typedef struct motor{
	uint8_t Direction_base; 
	uint16_t Verb;
	bool pin_1;
	bool pin_2;
	
}MOTOR,*PTRMOTOR;






//��������----------------------------------------------------


void MOTOR_Enable(void);
void RGB_CONTROL(void);

/*�˶�������*/
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
/*���������*/
void FIRE_PREPARE(void);
void FIRE(void);
	



#endif