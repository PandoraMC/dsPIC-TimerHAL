/*
 * File:   main.c
 * Author: Xochiquetzal
 *
 * Created on 21 de marzo de 2021, 04:51 PM
 */



#include "Config.h"
#include "RPORx.h"
#include "RPINRx.h"
#include "Timer.h"
#include <xc.h>
#include <libpic30.h>

void GPIOInit(void);
void Timer2Init(void);
void Timer3Init(void);

int main(void) {
    GPIOInit();    
    Timer2Init();
    Timer3Init();
    StartBTimer(&TIMER2_16);
    StartCTimer(&TIMER3_16);
    while(1){}
    return 0;
}

void Timer2Init(void){
    uint16_t TMRConfig;
    TMRConfig = SetBTimerMode(&TIMER2_16, 100e-3);
    if(TMRConfig == 1U){
        LATBbits.LATB3 = 1;
        while(1){}
    }else{
        IPC1bits.T2IP = 4;
        IEC0bits.T2IE = 1;
        IFS0bits.T2IF = 0;
    }
}

void Timer3Init(void){
    SetCCounterMode(&TIMER3_16, 5);
    T3CK.REG = 12;
    IPC2bits.T3IP = 3;
    IEC0bits.T3IE = 1;
    IFS0bits.T3IF = 0;
}

void GPIOInit(void){
    
    TRISBbits.TRISB3 = 0;
    ADPCFGbits.PCFG5 = 1;
    
    TRISBbits.TRISB10 = 0;
    
    TRISBbits.TRISB12 = 1;
    CNPU1bits.CN14PUE = 1;
}

void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void){
    IFS0bits.T2IF = 0;
    LATBbits.LATB3 = !PORTBbits.RB3;
}

void __attribute__((__interrupt__, no_auto_psv)) _T3Interrupt(void){
    IFS0bits.T3IF = 0;
    LATBbits.LATB10 = 1;
    __delay_ms(1000);
    LATBbits.LATB10 = 0;
}