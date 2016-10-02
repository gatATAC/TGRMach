/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "fsm.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */
#include "prj_cfg.h"
#include "prj_dre.h"
#include "prj_pinout.h"

/* ['AutofireOn' begin (DON'T REMOVE THIS LINE!)] */
void AutofireOn(  )
{
    /* set initial state */
    static STATE_T state = ID_AUTOFIREON_INITIAL;

    switch( state )
    {
        /* State ID: ID_AUTOFIREON_INITIAL */
        case ID_AUTOFIREON_INITIAL:
        {
            /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setFire' begin] */
            if (true==true) {
                if (dre.atari_system==CFG_ATARI_NORM_MSX){
                    dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=1;
                }
            } else {
                if (dre.atari_system==CFG_ATARI_NORM_MSX){
                    dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=0;
                }
            }
            /* ['<global>::setFire' end] */
            /* ['<global>::setAutofireTimer' begin] */
            dre.autofireTimer=CFG_AUTOFIRE_ON1_TIME;
            /* ['<global>::setAutofireTimer' end] */
            state = ID_AUTOFIREON_ON1;
            break;
        }
        /* State ID: ID_AUTOFIREON_ON1 */
        case ID_AUTOFIREON_ON1:
        {
            if( (dre.autofireTimer <= 0) )
            {
                /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::setFire' begin] */
                if (false==true) {
                    if (dre.atari_system==CFG_ATARI_NORM_MSX){
                        dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=1;
                    }
                } else {
                    if (dre.atari_system==CFG_ATARI_NORM_MSX){
                        dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=0;
                    }
                }
                /* ['<global>::setFire' end] */
                /* ['<global>::setAutofireTimer' begin] */
                dre.autofireTimer=CFG_AUTOFIRE_OFF1_TIME;
                /* ['<global>::setAutofireTimer' end] */
                state = ID_AUTOFIREON_OFF1;
            }
            else
            {
                /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::decrAutofireTimer' begin] */
                dre.autofireTimer--;
                /* ['<global>::decrAutofireTimer' end] */
            }
            break;
        }
        /* State ID: ID_AUTOFIREON_OFF1 */
        case ID_AUTOFIREON_OFF1:
        {
            if( (dre.autofireTimer <= 0) )
            {
                /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::setFire' begin] */
                if (true==true) {
                    if (dre.atari_system==CFG_ATARI_NORM_MSX){
                        dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=1;
                    }
                } else {
                    if (dre.atari_system==CFG_ATARI_NORM_MSX){
                        dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=0;
                    }
                }
                /* ['<global>::setFire' end] */
                /* ['<global>::setAutofireTimer' begin] */
                dre.autofireTimer=CFG_AUTOFIRE_ON2_TIME;
                /* ['<global>::setAutofireTimer' end] */
                state = ID_AUTOFIREON_ON2;
            }
            else
            {
                /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::decrAutofireTimer' begin] */
                dre.autofireTimer--;
                /* ['<global>::decrAutofireTimer' end] */
            }
            break;
        }
        /* State ID: ID_AUTOFIREON_ON2 */
        case ID_AUTOFIREON_ON2:
        {
            if( (dre.autofireTimer <= 0) )
            {
                /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::setFire' begin] */
                if (false==true) {
                    if (dre.atari_system==CFG_ATARI_NORM_MSX){
                        dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=1;
                    }
                } else {
                    if (dre.atari_system==CFG_ATARI_NORM_MSX){
                        dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=0;
                    }
                }
                /* ['<global>::setFire' end] */
                /* ['<global>::setAutofireTimer' begin] */
                dre.autofireTimer=CFG_AUTOFIRE_OFF2_TIME;
                /* ['<global>::setAutofireTimer' end] */
                state = ID_AUTOFIREON_OFF2;
            }
            else
            {
                /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::decrAutofireTimer' begin] */
                dre.autofireTimer--;
                /* ['<global>::decrAutofireTimer' end] */
            }
            break;
        }
        /* State ID: ID_AUTOFIREON_OFF2 */
        case ID_AUTOFIREON_OFF2:
        {
            if( (dre.autofireTimer <= 0) )
            {
                /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::setFire' begin] */
                if (true==true) {
                    if (dre.atari_system==CFG_ATARI_NORM_MSX){
                        dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=1;
                    }
                } else {
                    if (dre.atari_system==CFG_ATARI_NORM_MSX){
                        dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=0;
                    }
                }
                /* ['<global>::setFire' end] */
                /* ['<global>::setAutofireTimer' begin] */
                dre.autofireTimer=CFG_AUTOFIRE_ON3_TIME;
                /* ['<global>::setAutofireTimer' end] */
                state = ID_AUTOFIREON_ON3;
            }
            else
            {
                /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::decrAutofireTimer' begin] */
                dre.autofireTimer--;
                /* ['<global>::decrAutofireTimer' end] */
            }
            break;
        }
        /* State ID: ID_AUTOFIREON_ON3 */
        case ID_AUTOFIREON_ON3:
        {
            if( (dre.autofireTimer <= 0) )
            {
                /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::setFire' begin] */
                if (false==true) {
                    if (dre.atari_system==CFG_ATARI_NORM_MSX){
                        dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=1;
                    }
                } else {
                    if (dre.atari_system==CFG_ATARI_NORM_MSX){
                        dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=0;
                    }
                }
                /* ['<global>::setFire' end] */
                /* ['<global>::setAutofireTimer' begin] */
                dre.autofireTimer=CFG_AUTOFIRE_OFF3_TIME;
                /* ['<global>::setAutofireTimer' end] */
                state = ID_AUTOFIREON_OFF3;
            }
            else
            {
                /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::decrAutofireTimer' begin] */
                dre.autofireTimer--;
                /* ['<global>::decrAutofireTimer' end] */
            }
            break;
        }
        /* State ID: ID_AUTOFIREON_OFF3 */
        case ID_AUTOFIREON_OFF3:
        {
            if( (dre.autofireTimer <= 0) )
            {
                /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::setFire' begin] */
                if (true==true) {
                    if (dre.atari_system==CFG_ATARI_NORM_MSX){
                        dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=1;
                    }
                } else {
                    if (dre.atari_system==CFG_ATARI_NORM_MSX){
                        dre.detection.allButtons[CFG_MSX_FIRE1_BUT]=0;
                    }
                }
                /* ['<global>::setFire' end] */
                /* ['<global>::setAutofireTimer' begin] */
                dre.autofireTimer=CFG_AUTOFIRE_ON1_TIME;
                /* ['<global>::setAutofireTimer' end] */
                state = ID_AUTOFIREON_ON1;
            }
            else
            {
                /* Transition ID: ID_AUTOFIREON_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::decrAutofireTimer' begin] */
                dre.autofireTimer--;
                /* ['<global>::decrAutofireTimer' end] */
            }
            break;
        }
    }
}
/* ['AutofireOn' end (DON'T REMOVE THIS LINE!)] */

/* ['autofire' begin (DON'T REMOVE THIS LINE!)] */
void autofire(  )
{
    /* set initial state */
    static STATE_T state = ID_AUTOFIRE_INITIAL;

    switch( state )
    {
        /* State ID: ID_AUTOFIRE_INITIAL */
        case ID_AUTOFIRE_INITIAL:
        {
            /* Transition ID: ID_AUTOFIRE_TRANSITION_CONNECTION */
            state = ID_AUTOFIRE_NOAUTOFIRE;
            break;
        }
        /* State ID: ID_AUTOFIRE_NOAUTOFIRE */
        case ID_AUTOFIRE_NOAUTOFIRE:
        {
            if( ((dre.atari_system==CFG_ATARI_NORM_MSX) && (dre.detection.allButtons[CFG_MSX_AUTOFIRE_BUT]==1))==(true) )
            {
                /* Transition ID: ID_AUTOFIRE_TRANSITION_CONNECTION */
                state = ID_AUTOFIRE_AUTOFIREON;
            }
            break;
        }
        /* State ID: ID_AUTOFIRE_AUTOFIREON */
        case ID_AUTOFIRE_AUTOFIREON:
        {
            /* call substate function */
            AutofireOn(  );
            if( ((dre.atari_system==CFG_ATARI_NORM_MSX) && (dre.detection.allButtons[CFG_MSX_AUTOFIRE_BUT]==1))==(true) )
            {
                /* Transition ID: ID_AUTOFIRE_TRANSITION_CONNECTION */
                state = ID_AUTOFIRE_NOAUTOFIRE;
            }
            break;
        }
    }
}
/* ['autofire' end (DON'T REMOVE THIS LINE!)] */

