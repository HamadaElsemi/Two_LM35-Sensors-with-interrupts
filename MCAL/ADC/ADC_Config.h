/*
 * ADC_Config.h
 *
 *  Created on: Mar 25, 2024
 *      Author: Ibrahim Refaey
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_


/*
 * Options:
 * 1.AREFF
 * 2.AVCC
 * 3.VOLT_2_56
 */
#define ADC_REF_SELECTION              VOLT_2_56


/*
 * Options:
 * 1.CHANNEL0
 * 2.CHANNEL1
 * 3.CHANNEL2
 * 4.CHANNEL3
 * 5.CHANNEL4
 * 6.CHANNEL5
 * 7.CHANNEL6
 * 8.CHANNEL7
 */
#define ADC_CHANNEL						CHANNEL0















///*
// * Options:
// * 1- CHANNEL0
// * 2- CHANNEL1
// * 3- CHANNEL2
// * 4- CHANNEL3
// * 5- CHANNEL4
// * 6- CHANNEL5
// * 7- CHANNEL6
// * 8- CHANNEL7
// */
//#define ADC_CHANNEL					CHANNEL0
//
///*
// * Options:
// * 1- TEN_BITS
// * 2- EIGHT_BITS
// */
//#define ADC_NUMBER_OF_BITS			TEN_BITS
//
///*
// * Options:
// * 1- AREF
// * 2- AVCC
// * 3- REVERSED
// * 4- INTERNAL
// */
//#define ADC_REF_VOLTAGE				AVCC
//
///*
// * Options:
// * 1- DISABLE
// * 2- ENABLE
// */
//#define ADC_ENABLE					ENABLE
//#define ADC_INTERRUPT_MODE    		ENABLE
//
///*
// * Options:
// * 1- SINGLE_CONVERSATION
// * 2- AUTO_TRIGGER*/
//#define ADC_MODE					AUTO_TRIGGER
//
///*
// * Options:
// * 1- PRESCALER_DIV_BY_2
// * 2- PRESCALER_DIV_BY_4
// * 3- PRESCALER_DIV_BY_8
// * 4- PRESCALER_DIV_BY_16
// * 5- PRESCALER_DIV_BY_32
// * 6- PRESCALER_DIV_BY_64
// * 7- PRESCALER_DIV_BY_128
// */
//#define ADC_PRESCALER				PRESCALER_DIV_BY_64
//
///*
// * Options:
// * 1- FREE_RUNNING_MODE
// * 2- ANALOG_COMPARATOR
// * 3- EXTERNAL_INTERRUPT
// * 4- TIMER_COUNTER0_COMPARE_MATCH
// * 5- TIMER_COUNTER0_OVERFLOW
// * 6- TIMER_COUNTER_COMPARE_MATCH_B
// * 7- TIMER_COUNTER1_OVERFLOW
// * 8- TIMER_COUNTER0_CAPTURE_EVENT
// */
//#define ADC_AUTO_TRIGGER			FREE_RUNNING_MODE
/**************************************************************************************************/
///*
// Options:-
// 	 1-ADC_ENABLE
// 	 2-ADC_DISABLE
//
// */
//
//#define ADC_STATUS   ADC_ENABLE
//
///*
// Options:-
// 	 1-INT_ENABLE
// 	 2-INT_DISABLE
//
// */
//
//#define INT_STATUS   INT_ENABLE
//
//
///*
// Options:-
// 	 1-AREF
// 	 2-AVCC
// 	 3-INTERNAL_2_56
//
// */
//
//#define ADC_VREF  INTERNAL_2_56
//
///*
//  Options :
// 	 1-RIGHT_ADJUSTMENT
// 	 2-LEFT_ADJUSTMENT
//
//  */
//
//#define ADC_ADJUSTMENT RIGHT_ADJUSTMENT
//
///*
// Options:-
// 	 1-ADC_CHANNEL0
// 	 2-ADC_CHANNEL1
// 	 3-ADC_CHANNEL2
// 	 4-ADC_CHANNEL3
// 	 5-ADC_CHANNEL4
// 	 6-ADC_CHANNEL5
// 	 7-ADC_CHANNEL6
// 	 8-ADC_CHANNEL7
//
//
// */
//
//#define ADC_CHANNEL  ADC_CHANNEL0
//
///*
// Options:-
// 	 1-ADC_SINGLE_CONVERSION
// 	 2-ADC_FREE_RUNNING
// 	 3-ADC_ANALOG_COMPARATOR
// 	 4-ADC_EXTI0
// 	 5-ADC_TIM0_CTC
// 	 6-ADC_TIM0_OVF
// 	 7-ADC_TIM1_CTC_CHANNEL_B
// 	 8-ADC_TIM1_OVF
// 	 9-ADC_TIM1_ICU
//
// */
//
//#define ADC_TRIGGERING_SOURCE   ADC_SINGLE_CONVERSION
//
///*
// Options:-
// 	 1-ADC_PRE_2
// 	 2-ADC_PRE_4
// 	 3-ADC_PRE_8
// 	 4-ADC_PRE_16
// 	 5-ADC_PRE_32
// 	 6-ADC_PRE_64
// 	 7-ADC_PRE_128
//
// */
//
//#define  ADC_PRESCALLER   ADC_PRE_8
//
//#define  ADC_TIMEOUT      50000

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
