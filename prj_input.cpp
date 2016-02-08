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

  /*
    LEGACY CODE THAT DEMONSTRATES HOW TO READ THE DIGITAL INPUTS OF A JOYSTICK AND ENCODE THEM AS THE HEAD PAD BUTTON
void prjInputReadHat(void){
  // Read the "hat" controller
  for (uint8_t i=0; i<sizeof(joy_pins) ; i++) {
    if (digitalRead(joy_pins[i])) {
      detectedJoy[i]=false;      
    } else {
      detectedJoy[i]=true;      
      digitalWrite(CFG_POWERGND_PIN,HIGH);
    }
  }
  if (detectedJoy[CFG_JOY_UP_IDX]){
    if (detectedJoy[CFG_JOY_LEFT_IDX]){
      angle=315;
    } else {
      if (detectedJoy[CFG_JOY_RIGHT_IDX]){
        angle=45;
      } else {
        angle=0;
      }   
    }      
  } else {
    if (detectedJoy[CFG_JOY_DOWN_IDX]){
      if (detectedJoy[CFG_JOY_LEFT_IDX]){
        angle=225;
      } else {
        if (detectedJoy[CFG_JOY_RIGHT_IDX]){
          angle=135;
        } else {
          angle=180;
        }   
      }      
    } else {
      if (detectedJoy[CFG_JOY_LEFT_IDX]){
        angle=270;
      } else {
        if (detectedJoy[CFG_JOY_RIGHT_IDX]){
          angle=90;
        } else {
          angle=-1;
        }   
      }      
    }     
  }
  if (angle!=prev_angle){
    Serial.print("Hat: ");
    Serial.println(angle);
    prev_angle=angle;
  }
  Joystick.hat(angle);
}
*/

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
    if (digitalRead(dre.detection.but_pins[i])==HIGH) {
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

/* LEGACY CODE: SEND THROUGH SERIAL PORT WHEN A BUTTON HAS CHANGED 
  // check to see if any button changed since last time
  boolean anyChange = false;
  for (uint8_t i=0; i<sizeof(but_pins); i++) {
    if (allButtons[i] != prevButtons[i]) {
      anyChange = true;
    }
    prevButtons[i] = allButtons[i];
  }
  
  // if any button changed, print them to the serial monitor  
  if (anyChange) {
    Serial.print("Buttons: ");
    for (uint8_t i=0; i<sizeof(but_pins); i++) {
      Serial.print(allButtons[i], DEC);
    }
    Serial.println();
  }
*/

/************ JOYSTICK SECTION ****************/

  for (uint8_t i=0; i<CFG_JOYSTICK_NUMBER_OF_POSITIONS ; i++) {
    if (digitalRead(dre.detection.joy_pins[i])==HIGH) {
      dre.detection.detectedJoy[i]=false;      
    } else {
      dre.detection.detectedJoy[i]=true;
#ifdef DEBUG_JOY_INPUT      
      Serial.print("Detectado joy ");
      Serial.println(i);
#endif      
    }
  }

/*
    LEGACY CODE THAT DEMONSTRATES HOW TO READ THE DIGITAL INPUTS OF A JOYSTICK AND ENCODE THEM AS THE HEAD PAD BUTTON 
prjInputReadHat();
*/



  
}





























