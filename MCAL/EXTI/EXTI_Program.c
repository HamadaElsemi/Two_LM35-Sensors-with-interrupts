/*
 * EXTI_Program.c
 *
 *  Created on: Mar 24, 2024
 *      Author: Ibrahim
 */


/**********************LIB***************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"


/**********************MCAL**************************/
#include "EXTI_Config.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"


/******************GLOBAL POINTERS TO FUNCTIONS**************************/
static void (*Global_pvInt0NotifcationFunction)(void) = NULL;
static void (*Global_pvInt1NotifcationFunction)(void) = NULL;
static void (*Global_pvInt2NotifcationFunction)(void) = NULL;

/*********************FUNCTIONS DEFINITIONS******************************/
void EXTI_voidInit (void)
{
	#if	EXTI_INT0_ENALBE == ENABLE
		SET_BIT(GICR, GICR_INT0);
		#if	EXTI_INT0_SENSE_CONTROL == LOW_LEVEL
			CLR_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
		#elif EXTI_INT0_SENSE_CONTROL == ON_CHANGE
			CLR_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
		#elif EXTI_INT0_SENSE_CONTROL == FALLING_EDGE
			SET_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
		#elif EXTI_INT0_SENSE_CONTROL == RISING_EDGE
			SET_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
		#else
			#error "EXTI_INT0_CONTROL Error Configuration"
		#endif
	#elif EXTI_INT0_ENALBE == DISABLE
		CLR_BIT(GICR, GICR_INT0);
	#else
		#error "EXTI_INT0_ENALBE Error Configuration"
	#endif


	#if	EXTI_INT1_ENALBE == ENALBE
		SET_BIT(GICR, GICR_INT1);
		#if	EXTI_INT1_SENSE_CONTROL == LOW_LEVEL
			CLR_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);
		#elif EXTI_INT1_SENSE_CONTROL == ON_CHANGE
			CLR_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);
		#elif EXTI_INT1_SENSE_CONTROL == FALLING_EDGE
			SET_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);
		#elif EXTI_INT1_SENSE_CONTROL == RISING_EDGE
			SET_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);
		#else
			#error "EXTI_INT1_CONTROL Error Configuration"
		#endif
	#elif EXTI_INT1_ENALBE == DISABLE
		CLR_BIT(GICR, GICR_INT1);
	#else
		#error "EXTI_INT1_ENALBE Error Configuration"
	#endif


	#if	EXTI_INT2_ENALBE == ENABLE
		SET_BIT(GICR, GICR_INT2);
		#if EXTI_INT2_SENSE_CONTROL == FALLING_EDGE
			CLR_BIT(MCUCSR, MCUCSR_ISC2);
		#elif EXTI_INT2_SENSE_CONTROL == RISING_EDGE
			SET_BIT(MCUCSR, MCUCSR_ISC2);
		#else
			#error "EXTI_INT2_CONTROL Error Configuration"
		#endif
	#elif EXTI_INT2_ENALBE == DISABLE
		CLR_BIT(GICR, GICR_INT2);
	#else
		#error "EXTI_INT2_ENALBE Error Configuration"
	#endif
}


u8 EXTI_u8SetInt0SenseControl (u8 Copy_u8SenseControl)
{
	switch (Copy_u8SenseControl)
	{
		case LOW_LEVEL:
		{
			CLR_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
			break;
		}
		case ON_CHANGE:
		{
			CLR_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
			break;
		}
		case FALLING_EDGE:
		{
			SET_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
			break;
		}
		case RISING_EDGE:
		{
			SET_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
			break;
		}
		default:
		{
			return E_NOK;
		}
	}
	SET_BIT(GICR, GICR_INT0);
	return E_OK;
}

u8 EXTI_u8SetInt1SenseControl(u8 Copy_u8SenseControl)
{
	switch (Copy_u8SenseControl)
	{
	case LOW_LEVEL:
	{
		CLR_BIT(MCUCR, MCUCR_ISC11);
		CLR_BIT(MCUCR, MCUCR_ISC10);
		break;
	}
	case ON_CHANGE:
	{
		CLR_BIT(MCUCR, MCUCR_ISC11);
		SET_BIT(MCUCR, MCUCR_ISC10);
		break;
	}
	case FALLING_EDGE:
	{
		SET_BIT(MCUCR, MCUCR_ISC11);
		CLR_BIT(MCUCR, MCUCR_ISC10);
		break;
	}
	case RISING_EDGE:
	{
		SET_BIT(MCUCR, MCUCR_ISC11);
		SET_BIT(MCUCR, MCUCR_ISC10);
		break;
	}
	default:
	{
		return E_NOK;
	}
	}
	SET_BIT(GICR, GICR_INT1);
	return E_OK;
}

u8 EXTI_u8SetInt2SenseControl(u8 Copy_u8SenseControl)
{
	switch (Copy_u8SenseControl)
	{
	case FALLING_EDGE:
	{
		CLR_BIT(MCUCSR, MCUCSR_ISC2);
		break;
	}
	case RISING_EDGE:
	{
		SET_BIT(MCUCSR, MCUCSR_ISC2);
		break;
	}
	default:
	{
		return E_NOK;
	}
	}
	SET_BIT(GICR, GICR_INT2);
	return E_OK;
}


u8 EXTI_u8Int0SetCallBack (void (*Copy_pvNotificationFunction) (void))
{
	if (Copy_pvNotificationFunction != NULL)
	{
		Global_pvInt0NotifcationFunction = Copy_pvNotificationFunction;
		return E_OK;
	}
	else
	{
		return E_NOK;
	}
}

/*ISR for INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (Global_pvInt0NotifcationFunction != NULL)
	{
		Global_pvInt0NotifcationFunction();
	}
	else
	{
		/*Do nothing*/
	}
}

u8 EXTI_u8Int1SetCallBack (void (*Copy_pvNotificationFunction) (void))
{
	if (Copy_pvNotificationFunction != NULL)
	{
		Global_pvInt1NotifcationFunction = Copy_pvNotificationFunction;
		return E_OK;
	}
	else
	{
		return E_NOK;
	}
}

/*ISR for INT1*/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if (Global_pvInt1NotifcationFunction != NULL)
	{
		Global_pvInt1NotifcationFunction();
	}
	else
	{
		/*Do nothing*/
	}
}

u8 EXTI_u8Int2SetCallBack (void (*Copy_pvNotificationFunction) (void))
{
	if (Copy_pvNotificationFunction != NULL)
	{
		Global_pvInt2NotifcationFunction = Copy_pvNotificationFunction;
		return E_OK;
	}
	else
	{
		return E_NOK;
	}
}

/*ISR for INT2*/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (Global_pvInt2NotifcationFunction != NULL)
	{
		Global_pvInt2NotifcationFunction();
	}
	else
	{
		/*Do nothing*/
	}
}




