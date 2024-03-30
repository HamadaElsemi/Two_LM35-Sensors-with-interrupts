/*
 * ADC_Interface.h
 *
 *  Created on: Mar 25, 2024
 *      Author: Ibrahim
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_



#define CHANNEL0		1
#define CHANNEL1		2
#define CHANNEL2		3
#define CHANNEL3		4
#define CHANNEL4		5
#define CHANNEL5		6
#define CHANNEL6		7
#define CHANNEL7		8

/******************FUNCTIONS PROTOTYPES***************/
void ADC_voidInit(void);

u16 ADC_u16GetConversionReading(u8 copy_u8Channel);

//u8 ADC_u8GetReferenceSelection(void);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
