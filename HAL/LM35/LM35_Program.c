/*
 * LM35_Program.c
 *
 *  Created on: Mar 25, 2024
 *      Author: Ibrahim
 */


/****************************************************************/
/*                    FILES INCLUSIONS							*/
/****************************************************************/
/************************LIB*************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

/************************MCAL************************************/
#include "../../MCAL/ADC/ADC_Interface.h"

/************************HAL*************************************/
#include "LM35_Interface.h"
#include "LM35_Private.h"
#include "LM35_Config.h"



/***********FUNCTIONS DEFINITIONS*********/

void LM35_voidInit(void)
{
	ADC_voidInit();
}


u16 LM35_u16GetTempReading(u8 u8_LMChannel)
{
	u16 Local_u16TempValueDigital = 0;
	u16 Local_u16TempValueAnalog = 0;

	/*ADC conversion*/
	Local_u16TempValueDigital = ADC_u16GetConversionReading(u8_LMChannel);

#if ADC_REF_SEL == AVCC
	Local_u16TempValueAnalog = (Local_u16TempValueDigital*0.48828125);


#elif ADC_REF_SEL == VOLT_2_56
	Local_u16TempValueAnalog = (Local_u16TempValueDigital*0.25);


#else
#error "ADC_REF_SEL error configuration parameter!"

#endif


	return Local_u16TempValueAnalog;
}


