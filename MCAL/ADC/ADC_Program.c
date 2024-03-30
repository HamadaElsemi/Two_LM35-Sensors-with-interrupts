/*
 * ADC_Program.c
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
#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "ADC_Private.h"


/******************FUNCTIONS DEFINITIONS*****************/
void ADC_voidInit(void)
{
#if ADC_REF_SELECTION == AREFF
	CLR_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);
#elif ADC_REF_SELECTION == AVCC
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);

#elif ADC_REF_SELECTION == VOLT_2_56
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);

#else
#error "ADC_REF_SELECTION error configuration parameter!"

#endif

	/***************Challenge: Make configurations***************/
	/*clear ADLAR bit, so the first 8-bits will return in ADCL, and last 2-bits in ADCH*/
	CLR_BIT(ADMUX, ADLAR);
	/*clear AUTO trigger ADC, so the ADC conversion will start only when you call:  ADC_convert_read() */
	CLR_BIT(ADCSRA, ADATE);
	/*disable ADC interrupt: */
	CLR_BIT(ADCSRA, ADIE);
	/*set pre-scaler to be: (F_CPU/64) = (8000000/64) = 125 KHz */
	CLR_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);

	/*enable ADC peripheral in MCU*/
	SET_BIT(ADCSRA, ADEN);
}



u16 ADC_u16GetConversionReading(u8 copy_u8Channel)
{
	u16 ADC_data = 0;

	if(copy_u8Channel == CHANNEL0)
	{
		/*select input channel to pin PA0*/
		CLR_BIT(ADMUX, MUX0);
		CLR_BIT(ADMUX, MUX1);
		CLR_BIT(ADMUX, MUX2);
		CLR_BIT(ADMUX, MUX3);
		CLR_BIT(ADMUX, MUX4);

		/*start conversion:*/
		SET_BIT(ADCSRA, ADSC);
		/*wait until conversion ended*/
		while(Get_BIT(ADCSRA, ADSC) == 1)
		{
			//wait until ADSC bit becomes zero
		}
		/*after conversion is finished, read data from ADCL then ADCH*/
		ADC_data = ADCL;
		ADC_data |= (ADCH << 8);
	}

	else if(copy_u8Channel == CHANNEL1)
	{
		/*select input channel to pin PA1*/
		SET_BIT(ADMUX, MUX0);
		CLR_BIT(ADMUX, MUX1);
		CLR_BIT(ADMUX, MUX2);
		CLR_BIT(ADMUX, MUX3);
		CLR_BIT(ADMUX, MUX4);

		/*start conversion:*/
		SET_BIT(ADCSRA, ADSC);
		/*wait until conversion ended*/
		while(Get_BIT(ADCSRA, ADSC) == 1)
		{
			//wait until ADSC bit becomes zero
		}
		/*after conversion is finished, read data from ADCL then ADCH*/
		ADC_data = ADCL;
		ADC_data |= (ADCH << 8);
	}

	else if(copy_u8Channel == CHANNEL2)
	{
		/*select input channel to pin PA2*/
		CLR_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX1);
		CLR_BIT(ADMUX, MUX2);
		CLR_BIT(ADMUX, MUX3);
		CLR_BIT(ADMUX, MUX4);

		/*start conversion:*/
		SET_BIT(ADCSRA, ADSC);
		/*wait until conversion ended*/
		while(Get_BIT(ADCSRA, ADSC) == 1)
		{
			//wait until ADSC bit becomes zero
		}
		/*after conversion is finished, read data from ADCL then ADCH*/
		ADC_data = ADCL;
		ADC_data |= (ADCH << 8);
	}

	else if(copy_u8Channel == CHANNEL3)
	{

		/*select input channel to pin PA3*/
		SET_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX1);
		CLR_BIT(ADMUX, MUX2);
		CLR_BIT(ADMUX, MUX3);
		CLR_BIT(ADMUX, MUX4);

		/*start conversion:*/
		SET_BIT(ADCSRA, ADSC);
		/*wait until conversion ended*/
		while(Get_BIT(ADCSRA, ADSC) == 1)
		{
			//wait until ADSC bit becomes zero
		}
		/*after conversion is finished, read data from ADCL then ADCH*/
		ADC_data = ADCL;
		ADC_data |= (ADCH << 8);

	}

	else if(copy_u8Channel == CHANNEL4)
	{
		/*select input channel to pin PA4*/
		CLR_BIT(ADMUX, MUX0);
		CLR_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX2);
		CLR_BIT(ADMUX, MUX3);
		CLR_BIT(ADMUX, MUX4);

		/*start conversion:*/
		SET_BIT(ADCSRA, ADSC);
		/*wait until conversion ended*/
		while(Get_BIT(ADCSRA, ADSC) == 1)
		{
			//wait until ADSC bit becomes zero
		}
		/*after conversion is finished, read data from ADCL then ADCH*/
		ADC_data = ADCL;
		ADC_data |= (ADCH << 8);
	}

	else if(copy_u8Channel == CHANNEL5)
	{

		/*select input channel to pin PA5*/
		SET_BIT(ADMUX, MUX0);
		CLR_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX2);
		CLR_BIT(ADMUX, MUX3);
		CLR_BIT(ADMUX, MUX4);

		/*start conversion:*/
		SET_BIT(ADCSRA, ADSC);
		/*wait until conversion ended*/
		while(Get_BIT(ADCSRA, ADSC) == 1)
		{
			//wait until ADSC bit becomes zero
		}
		/*after conversion is finished, read data from ADCL then ADCH*/
		ADC_data = ADCL;
		ADC_data |= (ADCH << 8);
	}

	else if(copy_u8Channel == CHANNEL6)
	{

		/*select input channel to pin PA6*/
		CLR_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX2);
		CLR_BIT(ADMUX, MUX3);
		CLR_BIT(ADMUX, MUX4);

		/*start conversion:*/
		SET_BIT(ADCSRA, ADSC);
		/*wait until conversion ended*/
		while(Get_BIT(ADCSRA, ADSC) == 1)
		{
			//wait until ADSC bit becomes zero
		}
		/*after conversion is finished, read data from ADCL then ADCH*/
		ADC_data = ADCL;
		ADC_data |= (ADCH << 8);

	}
	else if(copy_u8Channel == CHANNEL7)
	{

		/*select input channel to pin PA7*/
		SET_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX2);
		CLR_BIT(ADMUX, MUX3);
		CLR_BIT(ADMUX, MUX4);

		/*start conversion:*/
		SET_BIT(ADCSRA, ADSC);
		/*wait until conversion ended*/
		while(Get_BIT(ADCSRA, ADSC) == 1)
		{
			//wait until ADSC bit becomes zero
		}
		/*after conversion is finished, read data from ADCL then ADCH*/
		ADC_data = ADCL;
		ADC_data |= (ADCH << 8);
	}
	/*return ADC data*/
	return ADC_data;
}




