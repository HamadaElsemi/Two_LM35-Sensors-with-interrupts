/*
 * GIE_Program.c
 *
 *  Created on: Mar 24, 2024
 *      Author: Eng Hamada Ahmed
 */

/*************************LIB**************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*************************MCAL*************************/
#include "GIE_Interface.h"
#include "GIE_Config.h"
#include "GIE_Private.h"

void GIE_VidEn(){
	SET_BIT(SREG,SREG_I);
}
void GIE_VidDisable(void){
CLR_BIT(SREG,SREG_I);
}
