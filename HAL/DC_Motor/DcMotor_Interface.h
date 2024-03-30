/*
 * DcMotor_Interface.h
 *
 *  Created on: Mar 21, 2024
 *      Author: Eng Hamada Ahmed
 */

#ifndef HAL_DC_MOTOR_DCMOTOR_INTERFACE_H_
#define HAL_DC_MOTOR_DCMOTOR_INTERFACE_H_

void MOTOR_VidInit(void);
void MOTOR_VidCounterClockwise(void);
void MOTOR_VidCounterAntiClockwise(void);
void MOTOR_Stop(void);

#endif /* HAL_DC_MOTOR_DCMOTOR_INTERFACE_H_ */
