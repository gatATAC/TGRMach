/* This file perform the acquisition tasks of the inputs of the system */

/* Inclusion of the basic types of the GTTC osek */
#include "gttc_types.h"
/* Configuration of the project */
#include "prj_cfg.h"
/* Inclusion of its own header */
#include "prj_input.h"
/* Inclusion of the pinout information */
#include "prj_pinout.h"
/* Inclusion of the DRE */
#include "prj_dre.h"
/* Inclusion of the arduino methods */
#include "Arduino.h"


/* Initialization of the input routines.
WARNING: The pinout initialization is not done here.  
It is done in the prj_pinout.c file */
void prjInputInit(void) {

}

/* Routine to read all the inputs in the system 
EXCEPTION: The inputs coming through an I/O bus can be acquired in another module.*/
void prjInput(void) {

/*************** BUTTON SECTION ********************/
  
  // read digital pins and use them for the buttons
  for (uint8_t i=0; i<CFG_JOYSTICK_NUMBER_OF_BUTTONS ; i++) {
    if (digitalRead(dre.detection.but_pins[i])==CFG_BUT_NOT_DETECTED_LEVEL) {
      // when a pin reads high, the button is not pressed
      // the pullup resistor creates the "on" signal      
      dre.detection.allButtons[i] = 0;
    } else {
      // when a pin reads low, the button is connecting to ground.
      dre.detection.allButtons[i] = 1;
#ifdef DEBUG_BUT_INPUT      
      Serial.print("Detectado botón ");
      Serial.println(i);
#endif
    }
  }

/************ JOYSTICK SECTION ****************/

  for (uint8_t i=0; i<CFG_JOYSTICK_NUMBER_OF_POSITIONS ; i++) {
    if (digitalRead(dre.detection.joy_pins[i]) == CFG_JOY_NOT_DETECTED_LEVEL) {
      dre.detection.detectedJoy[i]=false;      
    } else {
      dre.detection.detectedJoy[i]=true;
#ifdef DEBUG_JOY_INPUT      
      Serial.print("Detectado joy ");
      Serial.println(i);
#endif      
    }
  }

#ifdef CFG_JOYSTICK_USE_SLIDER
  dre.detection.slider = analogRead(CFG_JOY_SLIDER_ADC);
#endif
/*
    LEGACY CODE THAT DEMONSTRATES HOW TO READ THE DIGITAL INPUTS OF A JOYSTICK AND ENCODE THEM AS THE HEAD PAD BUTTON 
prjInputReadHat();
*/
}
