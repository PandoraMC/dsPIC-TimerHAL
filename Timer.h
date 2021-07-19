#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

#define INT_CLK         0
#define EXT_CLK         1
#define TIMER_MODE      0
#define COUNTER_MODE    1

#define BAD_PS         255

#define P1_1    0b00
#define P1_8    0b01
#define P1_64   0b10
#define P1_256  0b11

typedef struct{
    uint16_t        : 1;
    uint16_t TCS    : 1;
    uint16_t        : 1;
    uint16_t T32    : 1;
    uint16_t TCKPS  : 2;
    uint16_t TGATE  : 1;
    uint16_t        : 6;
    uint16_t TSIDL  : 1;
    uint16_t        : 1;
    uint16_t TON    : 1;
}TxCON_t;

typedef struct{
    uint16_t TMR;
    uint16_t        : 16;
    uint16_t        : 16;
    uint16_t PR;
    uint16_t        : 16;
    TxCON_t  TCON;    
}TIMERx_t;

typedef struct{
    uint16_t        : 1;
    uint16_t TCS    : 1;
    uint16_t        : 2;
    uint16_t TCKPS  : 2;
    uint16_t TGATE  : 1;
    uint16_t        : 6;
    uint16_t TSIDL  : 1;
    uint16_t        : 1;
    uint16_t TON    : 1;
}TyCON_t;

typedef struct{
    uint16_t TMR;
    uint16_t        : 16;
    uint16_t PR;
    uint16_t        : 16;
    TxCON_t  TCON;    
}TIMERy_t;

extern volatile TIMERx_t __attribute__ ((sfr(0x0106))) TIMER2_16;
extern volatile TIMERy_t __attribute__ ((sfr(0x010A))) TIMER3_16;

uint16_t SetBTimerMode(TIMERx_t volatile *const pTimer, float T);
void SetBCounterMode(TIMERx_t volatile *const pTimer, uint16_t Limit);
void StopBTimer(TIMERx_t volatile *const pTimer);
void StartBTimer(TIMERx_t volatile *const pTimer);

uint16_t SetCTimerMode(TIMERy_t volatile *const pTimer, float T);
void SetCCounterMode(TIMERy_t volatile *const pTimer, uint16_t Limit);
void StopCTimer(TIMERy_t volatile *const pTimer);
void StartCTimer(TIMERy_t volatile *const pTimer);

#endif