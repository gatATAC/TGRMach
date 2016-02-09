/* Inclusion of the basic types of the GTTC osek */
#include "gttc_types.h"
/* Configuration of the project */
#include "prj_cfg.h"
/* Inclusion of the DRE of the project */
#include "prj_dre.h"
/* Inclusion of its own header */
#include "prj_pinout.h"

/* Prepares the pinout for project use */
void pinoutInit(void){

  /* Configure the atari norm connector as input, to avoid shortcircuits */
  pinMode(CFG_ATARI_PIN_1,INPUT);
  pinMode(CFG_ATARI_PIN_2,INPUT);
  pinMode(CFG_ATARI_PIN_3,INPUT);
  pinMode(CFG_ATARI_PIN_4,INPUT);
  //pinMode(CFG_ATARI_PIN_5,INPUT);
  pinMode(CFG_ATARI_PIN_6,INPUT);
  pinMode(CFG_ATARI_PIN_7,INPUT);
  pinMode(CFG_ATARI_PIN_8,INPUT);
  //pinMode(CFG_ATARI_PIN_9,INPUT);
  
  /* Configure the power led DO pin */
  pinMode(CFG_POWERGND_PIN,OUTPUT);
  
  /* Configure the joystick DI pins */
  for (uint8_t i=0; i<CFG_JOYSTICK_NUMBER_OF_POSITIONS; i++) {
    pinMode(dre.detection.joy_pins[i], INPUT_PULLUP);
  }
  
  /* Configure the buttons DI pins */
  for (uint8_t i=0; i<CFG_JOYSTICK_NUMBER_OF_BUTTONS; i++) {
    pinMode(dre.detection.but_pins[i], INPUT_PULLUP);
  }
}



























