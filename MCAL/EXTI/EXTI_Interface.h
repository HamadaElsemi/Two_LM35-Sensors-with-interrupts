/*
 * EXTI_Interface.h
 *
 *  Created on: Mar 24, 2024
 *      Author: Ibrahim
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/*********************GENERAL MACROS**********************************/
/*Sense control*/
#define FALLING_EDGE	0
#define RISING_EDGE		1
#define LOW_LEVEL		2
#define ON_CHANGE		3

/*State*/
#define ENABLE			0
#define DISABLE			1

/*********************FUNCTIONS PROTOTYPES******************************/
void EXTI_voidInit (void);
u8 EXTI_u8SetInt0SenseControl (u8 Copy_u8SenseControl);
u8 EXTI_u8SetInt1SenseControl (u8 Copy_u8SenseControl);
u8 EXTI_u8SetInt2SenseControl (u8 Copy_u8SenseControl);
u8 EXTI_u8Int0SetCallBack (void (*Copy_pvNotificationFunction) (void));
u8 EXTI_u8Int1SetCallBack (void (*Copy_pvNotificationFunction) (void));
u8 EXTI_u8Int2SetCallBack (void (*Copy_pvNotificationFunction) (void));



#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
