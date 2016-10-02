/* Data Runtime Environment is a pool of global variables that can be shared through all the application.  It acts as a centralized data base for the functionality */

#ifndef _PRJ_DRE_H
#define _PRJ_DRE_H


/* Inclusion of the basic types of the GTTC osek */
#include "gttc_types.h"
/* Configuration of the project */
#include "prj_cfg.h"

typedef struct {
  uint8_t joy_pins[CFG_JOYSTICK_NUMBER_OF_POSITIONS];
  uint8_t but_pins[CFG_JOYSTICK_NUMBER_OF_BUTTONS];
  byte allButtons[CFG_JOYSTICK_NUMBER_OF_BUTTONS];
  byte prevButtons[CFG_JOYSTICK_NUMBER_OF_BUTTONS];
  bool detectedJoy[CFG_JOYSTICK_NUMBER_OF_POSITIONS];
  int angle;
  int prev_angle;
} t_detection;

/* This structure type contains the DRE global variables */
typedef struct {
  t_detection detection;
  uint8_t atari_system;
  uint32_t autofireTimer;
} t_dre;

/* This declaration make the dre visible to all the project modules */
extern t_dre dre;

/* This function initializes the DRE contents to their default values */
void dreInit(void);

#endif // _PRJ_DRE_H






















