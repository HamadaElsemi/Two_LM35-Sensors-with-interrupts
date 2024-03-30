/*
 * LM35_Interface.h
 *
 *  Created on: Mar 25, 2024
 *      Author: Ibrahim
 */

#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_


/***********FUNCTIONS PROTOTYPES*********/
void LM35_voidInit(void);
u16 LM35_u16GetTempReading(u8 u8_LMChannel);


#endif /* HAL_LM35_LM35_INTERFACE_H_ */
