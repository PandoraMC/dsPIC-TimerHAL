/*
 * File:   Timer.c
 * Author: Xochiquetzal
 *
 * Created on 21 de marzo de 2021, 05:19 PM
 */


#include "xc.h"
#include "Timer.h"

static uint16_t PSConfigs[] = {1, 8, 64, 256};

static int16_t CalcPS16(float T, uint16_t volatile *const pTMR){
    float lCalc;
    int16_t lOption;
    uint16_t lOK = 0;
    for(lOption = 0; lOption < (int16_t)4; lOption++){
        //T = TckPS*(PR + 1)/FCY;
        lCalc = T*(float)FCY/(float)PSConfigs[lOption] - 1;
        if(lCalc < (float)UINT16_MAX){
            lOK = 1;
            *pTMR = (uint16_t)lCalc;
            break;
        }
    }
    return (lOK == 1U)? lOption: BAD_PS;
}

uint16_t SetBTimerMode(TIMERx_t volatile *const pTimer, float T){
    int16_t PS;
    uint16_t lOK = 0;
    PS = CalcPS16(T, &(pTimer -> PR));
    if(PS == BAD_PS){
        lOK = 1U;
    }else{
        pTimer -> TCON.TON = 0;
        pTimer -> TCON.TCS = TIMER_MODE;
        pTimer -> TCON.TGATE = 0;
        pTimer -> TCON.TCKPS = PS;
    }
    return lOK;
}

void SetBCounterMode(TIMERx_t volatile *const pTimer, uint16_t Limit){
    pTimer -> TCON.TON = 0;
    pTimer -> TCON.TCS = COUNTER_MODE;
    pTimer -> PR = Limit - 1U;
}

void StopBTimer(TIMERx_t volatile *const pTimer){
    uint8_t lPS;
    lPS = pTimer -> TCON.TCKPS;
    pTimer -> TCON.TON = 0;
    pTimer -> TMR = 0;
    pTimer -> TCON.TCKPS = lPS;
}

void StartBTimer(TIMERx_t volatile *const pTimer){
    pTimer -> TCON.TON = 1;
}


uint16_t SetCTimerMode(TIMERy_t volatile *const pTimer, float T){
    int16_t PS;
    uint16_t lErr = 0;
    PS = CalcPS16(T, &(pTimer -> PR));
    if(PS == BAD_PS){
        lErr = 1U;
    }else{
        pTimer -> TCON.TON = 0;
        pTimer -> TCON.TCS = TIMER_MODE;
        pTimer -> TCON.TGATE = 0;
        pTimer -> TCON.TCKPS = PS;
    }
    return lErr;
}

void SetCCounterMode(TIMERy_t volatile *const pTimer, uint16_t Limit){
    pTimer -> TCON.TON = 0;
    pTimer -> TCON.TCS = COUNTER_MODE;
    pTimer -> PR = Limit - 1U;
}

void StopCTimer(TIMERy_t volatile *const pTimer){
    uint8_t lPS;
    lPS = pTimer -> TCON.TCKPS;
    pTimer -> TCON.TON = 0;
    pTimer -> TMR = 0;
    pTimer -> TCON.TCKPS = lPS;
}

void StartCTimer(TIMERy_t volatile *const pTimer){
    pTimer -> TCON.TON = 1;
}



