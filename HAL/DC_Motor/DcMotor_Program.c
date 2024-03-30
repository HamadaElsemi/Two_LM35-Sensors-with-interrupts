/*
 * DcMotor_Program.c
 *
 *  Created on: Mar 21, 2024
 *      Author: Eng Hamada Ahmed
 */
/***********************************LIB*************************/
#include "../../LIB/BIT_MATH.h"""
#include "../../LIB/STD_TYPES.h"

/************************************Hal**************************/
#include "DcMotor_Config.h"
#include "DcMotor_Interface.h"
#include "DcMotor_Private.h"

/***********************************MCAL************************/
#include"../../MCAL/DIO/DIO_Interface.h"

/**********************************Functions********************/
void MOTOR_VidInit(void){
	DIO_Vid_SetPinDirection(MOTOR_PORT,MOTOR_ACW_PIN,output);
	DIO_Vid_SetPinDirection(MOTOR_PORT,MOTOR_CW_PIN,output);

}
void MOTOR_VidCounterClockwise(void){
	DIO_Vid_SetPinValue(MOTOR_PORT,MOTOR_CW_PIN,PinHigh);
	DIO_Vid_SetPinValue(MOTOR_PORT,MOTOR_ACW_PIN,PinLow);
}
void MOTOR_VidCounterAntiClockwise(void){
	DIO_Vid_SetPinValue(MOTOR_PORT,MOTOR_ACW_PIN,PinHigh);
		DIO_Vid_SetPinValue(MOTOR_PORT,MOTOR_CW_PIN,PinLow);
}
void MOTOR_Stop(void){
	DIO_Vid_SetPinValue(MOTOR_PORT,MOTOR_CW_PIN,PinHigh);
	DIO_Vid_SetPinValue(MOTOR_PORT,MOTOR_CW_PIN,PinHigh);
}
