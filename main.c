/*
 * main.c
 *
 *  Created on: Mar 24, 2024
 *      Author: Eng Hamada Ahmed
 */


/*************************LIB**************************/
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

/*************************MCAL*************************/
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Config.h"
#include "MCAL/DIO/DIO_Private.h"


#include "MCAL/ADC/ADC_Private.h"
#include "MCAL/ADC/ADC_Config.h"
#include "MCAL/ADC/ADC_Interface.h"

#include "MCAL/EXTI/EXTI_Private.h"
#include "MCAL/GIE/GIE_Interface.h"

/*************************HAL**************************/
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KPD/KPD_Interface.h"
#include "HAL/LM35/LM35_Interface.h"
#include "HAL/LM35/LM35_Config.h"
#include "HAL/LM35/LM35_Private.h"

#include "HAL/DC_Motor/DcMotor_Interface.h"

/*************************Delay*************************/
#include <util/delay.h>


void Room1_INT0_Handle(){

	GIE_VidEn();
	LCD_vid_DisplayClear();
	LCD_vid_GoTo(0,1);
	LCD_vid_SendString("Welcome:ROOM 1");
    u8 Local_u8TempValue=0;
    LCD_vid_GoTo(1,0);
    LCD_vid_SendString("Temperature: ");
    LCD_vid_GoTo(1,12);
   Local_u8TempValue =LM35_u16GetTempReading(CHANNEL0);
if(Local_u8TempValue<10)
{        LCD_vid_GoTo(1,12);
         LCD_vid_SendString("");
         LCD_vid_SendInt(Local_u8TempValue);

}

else
{

	 LCD_vid_GoTo(1,12);
	 LCD_vid_SendInt(Local_u8TempValue);
}

_delay_ms(1000);

}

void Room2_INT1_Handle(){
GIE_VidEn();
SET_BIT(GIFR,GIFR_INTF1);
	LCD_vid_DisplayClear();
	LCD_vid_GoTo(0,1);
	LCD_vid_SendString("Welcome:ROOM 2");
    u8 Local_u8TempValue=0;
    LCD_vid_GoTo(1,0);
    LCD_vid_SendString("Temperature: ");
    LCD_vid_GoTo(1,12);
   Local_u8TempValue =LM35_u16GetTempReading(CHANNEL1);
if(Local_u8TempValue<10)
{        LCD_vid_GoTo(1,12);
         LCD_vid_SendString("");
         LCD_vid_SendInt(Local_u8TempValue);

}

else
{

	 LCD_vid_GoTo(1,12);
	 LCD_vid_SendInt(Local_u8TempValue);
}
_delay_ms(1000);

}



int main(){

						/*LCD Initializations*/
DIO_Vid_SetPortDirection(Port_B,output);
DIO_Vid_SetPinDirection(Port_A,pin5,output);
DIO_Vid_SetPinDirection(Port_A,pin6,output);
DIO_Vid_SetPinDirection(Port_A,pin7,output);

LCD_Vid_Init();

						/*MOTOR INITIALIZATION*/
MOTOR_VidInit();

                       /*ADC INITIALIZATION PINS*/

DIO_Vid_SetPinDirection(Port_A,pin0,input);
DIO_Vid_SetPinDirection(Port_A,pin1,input);


                       /*INTERRUPTS INITIALIZATION*/


DIO_Vid_SetPinDirection(Port_D,pin2,input);  //INT0
DIO_Vid_SetPinDirection(Port_D,pin3,input);  //INT1
GIE_VidEn();
EXTI_voidInit();

                        /*LM35 INITIALIZATION*/
	LM35_voidInit();


//LCD_vid_DisplayClear();
LCD_vid_SendString("Welcome to MP5");
LCD_vid_GoTo(1,2);
LCD_vid_SendString("Wazeefa_Tech!");
_delay_ms(2000);
LCD_vid_DisplayClear();

EXTI_u8Int0SetCallBack(Room1_INT0_Handle);
EXTI_u8Int1SetCallBack(Room2_INT1_Handle);
	while(1)
	{
		MOTOR_VidCounterAntiClockwise();
		LCD_vid_DisplayClear();
		LCD_vid_SendString("Motor: CCW");
		_delay_ms(3000);
		MOTOR_VidCounterClockwise();
		LCD_vid_DisplayClear();
		LCD_vid_SendString("Motor: CW");
		_delay_ms(3000);
	}
	return 0;
}
