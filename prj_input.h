#ifndef _PRJ_INPUT_H
#define _PRJ_INPUT_H

/* Inclusion of the basic types of the GTTC osek */
#include "gttc_types.h"

/* Initialization of the input routines.
WARNING: The pinout initialization is not done here.  
It is done in the prj_pinout.c file */
void prjInputInit(void);

/* Routine to read all the inputs in the system 
EXCEPTION: The inputs coming through an I/O bus can be acquired in another module.*/
void prjInput(void);

#endif /* _PRJ_INPUT_H */



























