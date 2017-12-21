/* This file perform the synthesis tasks of the output of the system */

/* Inclusion of the basic types of the GTTC osek */
#include "gttc_types.h"
/* Configuration of the project */
#include "prj_cfg.h"
/* Inclusion of its own header */
#include "prj_output.h"
/* Inclusion of the pinout information */
#include "prj_pinout.h"
/* Inclusion of the DRE */
#include "prj_dre.h"
/* Inclusion of the arduino methods */
#include "Arduino.h"
/* Inclusion for FSM module */
#include "fsm.h"


  int lastValueX = CFG_USB_JOYSTICK_BLANK_POS;
  int lastValueY = CFG_USB_JOYSTICK_BLANK_POS;
  int lastAllButtons[CFG_JOYSTICK_NUMBER_OF_BUTTONS];
  
/* Initialization of the output routines.
WARNING: The pinout initialization is not done here.  
It is done in the prj_pinout.c file */
void prjOutputInit(void) {
  // configure the joystick to manual send mode.  This gives precise
  // control over when the computer receives updates, but it does
  // require you to manually call Joystick.send_now().
  Joystick.useManualSend(true);
  for (uint8_t i=0; i<CFG_JOYSTICK_NUMBER_OF_BUTTONS ; i++) {
    lastAllButtons[i] = 5;
  }
  
}


int selectMode = 0;
int lastLlanderSelect = false;
  
/* Routine to read all the outputs in the system 
EXCEPTION: The inputs coming through an I/O bus can be synthesized in another module.*/
void prjOutput(void) {
  
  /************* BUTTONS SECTION ***************/
  
  // read digital pins and use them for the buttons
  for (uint8_t i=0; i<CFG_JOYSTICK_NUMBER_OF_BUTTONS ; i++) {
    if (dre.detection.allButtons[i] != lastAllButtons[i]) {
      /* Update USB data structure */
      Joystick.button(i + 1, dre.detection.allButtons[i]);
      lastAllButtons[i] = dre.detection.allButtons[i];
    }
  }

  /************ JOYSTICK SECTION ***************/
  
  // 512 is resting position
  // "value" is from 0 to 1023
  int valueX = CFG_USB_JOYSTICK_REST_POS;
  int valueY = CFG_USB_JOYSTICK_REST_POS;


#ifdef CFG_JOYSTICK_USE_SLIDER  
  uint32_t tempslider = 0L;
#endif
  if (dre.detection.detectedJoy[CFG_JOY_LEFT_IDX]){
    valueX=CFG_USB_JOYSTICK_LEFT_POS;
  }

  if (dre.detection.detectedJoy[CFG_JOY_RIGHT_IDX]){
    valueX=CFG_USB_JOYSTICK_RIGHT_POS;
  }

  if (dre.detection.detectedJoy[CFG_JOY_UP_IDX]){
    valueY = CFG_USB_JOYSTICK_UP_POS;
    lastLlanderSelect = true;
  } else {
    if (lastLlanderSelect == true) {
      digitalWrite(CFG_MODELIGHT_BASE_PIN + selectMode, HIGH);
      selectMode = (selectMode + 1) % 4;
      digitalWrite(CFG_MODELIGHT_BASE_PIN  + selectMode, LOW);      
      lastLlanderSelect = false; 
    }
  }
  Serial.println(dre.detection.detectedJoy[CFG_JOY_UP_IDX]);
  if (dre.detection.detectedJoy[CFG_JOY_DOWN_IDX]){
    valueY=CFG_USB_JOYSTICK_DOWN_POS;
  }

  /*********** Send the USB commands */
  
  // Because setup configured the Joystick manual send,
  // the computer does not see any of the changes yet.

#ifdef FORCE_SEND_X_Y
  lastValueX = CFG_USB_JOYSTICK_BLANK_POS;
  lastValueY = CFG_USB_JOYSTICK_BLANK_POS;
#endif

#ifdef CFG_JOYSTICK_USE_SLIDER
  Serial.print(dre.detection.slider);
  Serial.print(" ");
  tempslider = dre.detection.slider - (uint32_t)CFG_JOY_SLIDER_MIN;
  tempslider = (tempslider * (uint32_t)CFG_JOY_SLIDER_OUTPUT_MAX);
  tempslider /= (uint32_t)((uint32_t)CFG_JOY_SLIDER_MAX - (uint32_t)CFG_JOY_SLIDER_MIN);
  tempslider -= (uint32_t)CFG_JOY_SLIDER_OUTPUT_MIN;
  Serial.println(tempslider);
  Joystick.Z((uint16_t)tempslider);
#endif

  /* Update USB data structure */
  if (valueX != lastValueX){
    Joystick.X(valueX);            // "value" is from 0 to 1023
    lastValueX = valueX;
  }
  if (valueY != lastValueY) {
    Joystick.Y(valueY);            //   512 is resting position    
    lastValueY = valueY;   
  }

  // This send_now() transmits everything all at once.
  Joystick.send_now();  
}



