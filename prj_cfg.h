#ifndef _PRJ_CFG_H
#define _PRJ_CFG_H

/****** Debug section ******/
//#define DEBUG_BUT_INPUT  
//#define DEBUG_JOY_INPUT  
#define DEBUG_FORCE_MSX

/**** Cycle time section ****/
#define CYCLE_TIME_IN_MICROS (5000L)

/**** Joystick detection section ****/
#define CFG_JOYSTICK_NUMBER_OF_POSITIONS 4
#define CFG_JOYSTICK_NUMBER_OF_BUTTONS 11

#define CFG_JOY_UP_IDX 0
#define CFG_JOY_DOWN_IDX 1
#define CFG_JOY_LEFT_IDX 2
#define CFG_JOY_RIGHT_IDX 3

#define CFG_JOY_GREENBUT_IDX 0
#define CFG_JOY_REDBUT_IDX 1
#define CFG_JOY_BLUEBUT_IDX 2
#define CFG_JOY_YELLOWBUT_IDX 3
#define CFG_JOY_GREYBUT_IDX 4
#define CFG_JOY_BLACKBUT_IDX 5
#define CFG_JOY_WHITELBUT_IDX 6
#define CFG_JOY_WHITERBUT_IDX 7
#define CFG_JOY_MODEBUT_IDX 8
#define CFG_JOY_RESTARTBUT_IDX 9
#define CFG_JOY_PLAYERBUT_IDX 10

/**** USB joystick section ****/
#define CFG_USB_JOYSTICK_REST_POS 512
#define CFG_USB_JOYSTICK_LEFT_POS 0
#define CFG_USB_JOYSTICK_RIGHT_POS 1023
#define CFG_USB_JOYSTICK_UP_POS 0
#define CFG_USB_JOYSTICK_DOWN_POS 1023

/**** Atari norm system ****/
#define CFG_ATARI_NORM_MSX 0
#define CFG_ATARI_NORM_AMIGA 1

/**** Special function configuration ****/
#define CFG_MSX_FIRE1_BUT CFG_JOY_GREENBUT_IDX
#define CFG_MSX_AUTOFIRE_BUT CFG_JOY_BLUEBUT_IDX
#define CFG_AUTOFIRE_ON1_TIME 125
#define CFG_AUTOFIRE_ON2_TIME 115
#define CFG_AUTOFIRE_ON3_TIME 135
#define CFG_AUTOFIRE_OFF1_TIME 122
#define CFG_AUTOFIRE_OFF2_TIME 118
#define CFG_AUTOFIRE_OFF3_TIME 132

#endif /* _PRJ_CFG_H */















