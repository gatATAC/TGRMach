/* ---- This file describes all the pin assignments of the microcontroller --- */

#ifndef _PRJ_PINOUT_H
#define _PRJ_PINOUT_H

/* Inclusion of the basic types of the GTTC osek */
#include "gttc_types.h"

/**** Pin assigment section ****/
#define CFG_POWERGND_PIN 2

#define CFG_JOY_UP_PIN 23
#define CFG_JOY_DOWN_PIN 21
#define CFG_JOY_LEFT_PIN 22
#define CFG_JOY_RIGHT_PIN 20

#define CFG_JOY_GREENBUT_PIN 19
#define CFG_JOY_REDBUT_PIN 18
#define CFG_JOY_BLUEBUT_PIN 17
#define CFG_JOY_YELLOWBUT_PIN 16
#define CFG_JOY_GREYBUT_PIN 15
#define CFG_JOY_BLACKBUT_PIN 14
#define CFG_JOY_WHITELBUT_PIN 12
#define CFG_JOY_WHITERBUT_PIN 11
#define CFG_JOY_MODEBUT_PIN 10
#define CFG_JOY_RESTARTBUT_PIN 9
#define CFG_JOY_PLAYERBUT_PIN 8

/* Prepares the pinout for project use */
void pinoutInit(void);

#endif // _PRJ_PINOUT_H



























