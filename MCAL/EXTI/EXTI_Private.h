/*
 * EXTI_Private.h
 *
 *  Created on: Mar 24, 2024
 *      Author: Ibrahim
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_


/******************EXTI REGISTERS************************/
/*MCUR*/
#define MCUCR			(*((volatile u8*)0x55))
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3

/*MCUCSR*/
#define MCUCSR			(*((volatile u8*)0x54))
#define MCUCSR_ISC2		6

/*GICR*/
#define GICR			(*((volatile u8*)0x5B))
#define GICR_INT0		6
#define GICR_INT1		7
#define GICR_INT2		5

/*GIFR*/
#define GIFR			(*((volatile u8*)0x5A))
#define GIFR_INTF0		6
#define GIFR_INTF1		7
#define GIFR_INTF2		5

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
