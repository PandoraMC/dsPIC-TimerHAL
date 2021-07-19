#ifndef RPINRX_H
#define RPINRX_H

#include <stdint.h>

enum{ANALOG = 0, DIGITAL = 1};
enum{DISABLE = 0, ENABLE = 1};
enum{CLEAR = 0, SET = 1};

typedef struct{
    uint8_t REG : 5;
    uint8_t     : 3;
}RPnR_t;

extern volatile RPnR_t __attribute__ ((sfr(0x06A4))) U1RX;
extern volatile RPnR_t __attribute__ ((sfr(0x0687))) T3CK;

#endif