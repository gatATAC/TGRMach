/* --------- This file is an example of a main file in an Arduino project -----------------------------
 -- Additional files with gttc_ prefix are the gatArduinOSEK files, not to be modified in normal use -- 
 -- Additional files with prj_ prefix are the ones that must be configured for each project, they    -- 
 -- are part of the example.                                                                         -- 
 -- Project Functionality:
*/
/***** Project configuration include (before OSEK includes to allow OSEK configuration) ******/
#include "prj_cfg.h"
 
/***** gatArduinOSEK includes *****/
/*** Types ***/
#include <gttc_types.h>
/*** Timer ***/
#define TIMEBASE_USE_MS 1  // <-- Normally the timer unit is the us (microseconds) but you can use this define to use ms (milliseconds)
#include <gttc_timer.h>

/* ---------------------------------------*/

/***** Project includes *****/
#include "prj_pinout.h" /*!<  The pinout of the project */
#include "prj_dre.h"    /*!<  The DRE of the project (global variables pools to share) */
#include "prj_input.h"  /*!<  The input module reads the microcontroller pinout */
#include "prj_output.h"  /*!<  The output module writes the microcontroller pinout */
#include "fsm.h"        /*!< Finite State Machine implementation */

/* ---------------------------------------*/

/***** Setup & Startup functions *****/
void setup() {
  /* Initialization of the Data Runtime Environment */
  dreInit();
  /* Initialization of the pin out */
  pinoutInit();
  /* Set program cycle time */
  timerSetCycleTime(CYCLE_TIME_IN_MICROS);
  /* Serial monitor active */
  Serial.begin(9600);
  /* Initialization of the output routines */
  prjOutputInit();
  /* Initialization of the input routines */
  prjInputInit();
}

/* ---------------------------------------*/

/***** Main Loop *****/

uint32_t maxElapsedMicros=2L;
bool firstLoop=true;
void loop()
{
  // ----------- Functionality ----------------

  prjInput();

  // -------------- Transfer function ---------------

  //dispatcher();


  // ----------- End of Cycle Synchronization ----------------

  // Now the microcontroller will loose time until the end of cycle sincronization time expires
  boolean timSync=timerSync();
  while(timSync==false){
    // timerSync returns true when the end of cycle syncronization time expired.
    timSync=timerSync();
  }
  if (firstLoop){
    firstLoop=false;
    busyMicros=0L;
  }  
  if (busyMicros>CYCLE_TIME_IN_MICROS){
    Serial.print("Ciclo violado");Serial.println(busyMicros);
  } 
    if (busyMicros>maxElapsedMicros){
      maxElapsedMicros=busyMicros;
      Serial.print("El =");Serial.println(maxElapsedMicros);
    }
  // -------------- Output --------------------
  prjOutput();
}




































