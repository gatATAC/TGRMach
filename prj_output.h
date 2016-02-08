#ifndef _PRJ_OUTPUT_H
#define _PRJ_OUTPUT_H

/* Inclusion of the basic types of the GTTC osek */
#include "gttc_types.h"

/* Initialization of the output routines.
WARNING: The pinout initialization is not done here.  
It is done in the prj_pinout.c file */
void prjOutputInit(void);

/* Routine to read all the outputs in the system 
EXCEPTION: The inputs coming through an I/O bus can be synthesized in another module.*/
void prjOutput(void);

#endif /* _PRJ_OUTPUT_H */




























