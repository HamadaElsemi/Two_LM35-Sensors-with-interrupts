/*
 * GIE_Private.h
 *
 *  Created on: Mar 24, 2024
 *      Author: Eng Hamada Ahmed
 */

#ifndef MCAL_GIE_GIE_PRIVATE_H_
#define MCAL_GIE_GIE_PRIVATE_H_

#define SREG  (*(volatile u8*)0x5F)       //Statues Register:Bit 7 is  setting to enable Global iterrrupt flag

#define SREG_I         7


#endif /* MCAL_GIE_GIE_PRIVATE_H_ */
