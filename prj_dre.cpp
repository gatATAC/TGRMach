/* Data Runtime Environment is a pool of global variables that can be shared through all the application.  It acts as a centralized data base for the functionality */

#include "gttc_types.h"
#include "prj_cfg.h"
#include "prj_dre.h"
#include "Arduino.h"
#include "gttc_timer.h"
#include "prj_pinout.h"

t_dre dre;

/* This function initializes the DRE contents to their default values */
void dreInit(void) {

  Serial.println("DRE Initialization");

/**** Atari norm system detection ****/

  dre.atari_system = CFG_ATARI_NORM_NONE;
#ifdef DEBUG_FORCE_MSX
  dre.atari_system=CFG_ATARI_NORM_MSX;
#endif
  
  dre.detection.angle=-1;
  dre.detection.prev_angle=-1;  

/**** Decoding structures for joysticks and buttons */
  dre.detection.joy_pins[CFG_JOY_UP_IDX]=CFG_JOY_UP_PIN;
  dre.detection.joy_pins[CFG_JOY_DOWN_IDX]=CFG_JOY_DOWN_PIN;
  dre.detection.joy_pins[CFG_JOY_LEFT_IDX]=CFG_JOY_LEFT_PIN;
  dre.detection.joy_pins[CFG_JOY_RIGHT_IDX]=CFG_JOY_RIGHT_PIN;

  dre.detection.but_pins[CFG_JOY_GREENBUT_IDX]=CFG_JOY_GREENBUT_PIN;
  dre.detection.but_pins[CFG_JOY_REDBUT_IDX]=CFG_JOY_REDBUT_PIN;
  dre.detection.but_pins[CFG_JOY_BLUEBUT_IDX]=CFG_JOY_BLUEBUT_PIN;
  /*dre.detection.but_pins[CFG_JOY_YELLOWBUT_IDX]=CFG_JOY_YELLOWBUT_PIN;
  dre.detection.but_pins[CFG_JOY_GREYBUT_IDX]=CFG_JOY_GREYBUT_PIN;
  dre.detection.but_pins[CFG_JOY_BLACKBUT_IDX]=CFG_JOY_BLACKBUT_PIN;
  dre.detection.but_pins[CFG_JOY_WHITELBUT_IDX]=CFG_JOY_WHITELBUT_PIN;
  dre.detection.but_pins[CFG_JOY_WHITERBUT_IDX]=CFG_JOY_WHITERBUT_PIN;
  dre.detection.but_pins[CFG_JOY_MODEBUT_IDX]=CFG_JOY_MODEBUT_PIN;
  dre.detection.but_pins[CFG_JOY_RESTARTBUT_IDX]=CFG_JOY_RESTARTBUT_PIN;
  dre.detection.but_pins[CFG_JOY_PLAYERBUT_IDX]=CFG_JOY_PLAYERBUT_PIN;*/

#ifdef CFG_JOYSTICK_USE_SLIDER
  dre.detection.slider = 0;
#endif
}
