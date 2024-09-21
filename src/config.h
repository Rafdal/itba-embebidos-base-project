/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.h)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include <src/gpio/gpio.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

//PIN DE DEBUGGING PARA EL TP
#define SYSTICKTPPIN PORTNUM2PIN(PC,16)
#define GPIOTPPIN PORTNUM2PIN(PC,17)

//LEDS DE LA PLACA
#define STATUS0	PORTNUM2PIN(PA,2)
#define STATUS1	PORTNUM2PIN(PB,23)

//ENCODER DE LA PLACA
#define RCHA_PIN PORTNUM2PIN(PB, 2)
#define RCHB_PIN PORTNUM2PIN(PB, 3)
#define RSW_PIN PORTNUM2PIN(PB, 10)

//DISPLAY DE LA PLACA
#define ENC1_PIN	PORTNUM2PIN(PC,2)
#define ENC2_PIN	PORTNUM2PIN(PC,3)

#define SEG_A_PIN	PORTNUM2PIN(PC,5)
#define SEG_B_PIN	PORTNUM2PIN(PC,7)
#define SEG_C_PIN	PORTNUM2PIN(PC,0)
#define SEG_D_PIN	PORTNUM2PIN(PC,9)
#define SEG_E_PIN	PORTNUM2PIN(PC,8)
#define SEG_F_PIN	PORTNUM2PIN(PC,1)
#define SEG_G_PIN	PORTNUM2PIN(PB,19)
#define SEG_DP_PIN	PORTNUM2PIN(PB,18)


//CARD-READER
#define PIN_LECTOR_DATA PORTNUM2PIN(PB, 11)
#define PIN_LECTOR_CLK PORTNUM2PIN(PC, 11)
#define PIN_LECTOR_EN PORTNUM2PIN(PC, 10)

//DEBUG PIN

#define DEBUG_PIN	PORTNUM2PIN(PA, 1)

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/


/*******************************************************************************
 ******************************************************************************/

#endif // _TEMPLATE_H_

