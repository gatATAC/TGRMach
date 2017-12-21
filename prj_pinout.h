/* ---- This file describes all the pin assignments of the microcontroller --- */

#ifndef _PRJ_PINOUT_H
#define _PRJ_PINOUT_H

/* Inclusion of the basic types of the GTTC osek */
#include "gttc_types.h"

/**** Pin assigment section ****/
#define CFG_POWERGND_PIN 2 // anteriormente 2

#define CFG_JOY_UP_PIN 20 // anteriormente 23
#define CFG_JOY_DOWN_PIN 19 // anteriormente 21   
#define CFG_JOY_LEFT_PIN 22 // anteriormente 22
#define CFG_JOY_RIGHT_PIN 23 // anteriormente 20

#define CFG_JOY_GREENBUT_PIN 14// anteriormente 19
#define CFG_JOY_REDBUT_PIN 18 // anteriormente 18
#define CFG_JOY_BLUEBUT_PIN 21 // anteriormente 17
#define CFG_JOY_YELLOWBUT_PIN 17 // anteriormente 16
#define CFG_JOY_GREYBUT_PIN 16 // anteriormente 15 // anteriormente 14 
#define CFG_JOY_BLACKBUT_PIN 15 // anteriormente 14 // anteriormente 15
#define CFG_JOY_WHITELBUT_PIN 29 // anteriormente 12
#define CFG_JOY_WHITERBUT_PIN 30 // anteriormente 11
#define CFG_JOY_MODEBUT_PIN 31 // anteriormente 10
#define CFG_JOY_RESTARTBUT_PIN 32 // anteriormente 9
#define CFG_JOY_PLAYERBUT_PIN 33 // anteriormente 8

#ifdef CFG_JOYSTICK_USE_SLIDER
#define CFG_JOY_SLIDER_ADC A3
#define CFG_JOY_SLIDER_MAX 1023
#define CFG_JOY_SLIDER_MIN 830
#define CFG_JOY_SLIDER_OUTPUT_MAX 290
#define CFG_JOY_SLIDER_OUTPUT_MIN 0
#endif

/**** ATARI norm output ****/
#define CFG_ATARI_PIN_1 9 // anteriormente 7  // MSX FW // AZUL 1er conector
#define CFG_ATARI_PIN_2 8 // anteriormente 6  // MSX BACK // VERDE 1er conector
#define CFG_ATARI_PIN_3 7 // anteriormente 5  // MSX LEFT // AMARILLO 1er conector
#define CFG_ATARI_PIN_4 6 // anteriormente 4  // MSX RIGHT // BLANCO 1er conector
#define CFG_ATARI_PIN_5 5 // anteriormente NC // MSX +5v // ROJO 1er conector
#define CFG_ATARI_PIN_6 12 // anteriormente 3  // MSX TRG1 // AZUL 2o conector
#define CFG_ATARI_PIN_7 11 // anteriormente 1  // MSX TRG2 // VERDE 2o conector
#define CFG_ATARI_PIN_8 10 // anteriormente 0  // MSX OUT // AMARILLO 2o conector
#define CFG_ATARI_PIN_9 4 // anteriormente NC // MSX GND // NEGRO 1er conector

#define CFG_MODELIGHT_BASE_PIN 4

/* Prepares the pinout for project use */
void pinoutInit(void);

#endif // _PRJ_PINOUT_H


