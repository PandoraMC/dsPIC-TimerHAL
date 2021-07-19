#ifndef RPORX_H
#define RPORX_H

#include "RPINRx.h"

/*#define RP11 ((RPnR_t*)0x06CB) -> REG
#define RP5  ((RPnR_t*)0x06C5) -> REG
#define RP6  ((RPnR_t*)0x06C6) -> REG
#define RP9  ((RPnR_t*)0x06C4) -> REG*/

enum{OUTPUT = 0, INPUT = 1};

extern volatile RPnR_t __attribute__ ((sfr(0x06C4))) RP4;
extern volatile RPnR_t __attribute__ ((sfr(0x06C5))) RP5;
extern volatile RPnR_t __attribute__ ((sfr(0x06C6))) RP6;
extern volatile RPnR_t __attribute__ ((sfr(0x06C9))) RP9;
extern volatile RPnR_t __attribute__ ((sfr(0x06CB))) RP11;
extern volatile RPnR_t __attribute__ ((sfr(0x06CF))) RP15;

#define NULL_F    0b00000U     // RPn tied to default port pin
#define C1OUT_F   0b00001U     // RPn tied to Comparator1 Output
#define C2OUT_F   0b00010U     // RPn tied to Comparator2 Output
#define U1TX_F    0b00011U     // RPn tied to UART1 Transmit
#define U1RTS_F   0b00100U     // RPn tied to UART1 Ready To Send
#define U2TX_F    0b00101U     // RPn tied to UART2 Transmit
#define U2RTS_F   0b00110U     // RPn tied to UART2 Ready To Send
#define SDO1_F    0b00111U     // RPn tied to SPI1 Data Output
#define SCK1_F    0b01000U     // RPn tied to SPI1 Clock Output
#define SS1_F     0b01001U     // RPn tied to SPI1 Slave Select Output
#define SDO2_F    0b01010U     // RPn tied to SPI2 Data Output
#define SCK2_F    0b01011U     // RPn tied to SPI2 Clock Output
#define SS2_F     0b01100U     // RPn tied to SPI2 Slave Select Output
#define C1TX_F    0b10000U     // RPn tied to ECAN1 Transmit
#define OC1_F     0b10010U     // RPn tied to Output Compare 1
#define OC2_F     0b10011U     // RPn tied to Output Compare 2
#define OC3_F     0b10100U     // RPn tied to Output Compare 3
#define OC4_F     0b10101U     // RPn tied to Output Compare 4
#define UPDN1_F   0b11010U     // RPn tied to QEI1 direction (UPDN) status
#define UPDN2_F   0b11011U     // RPn tied to QEI2 direction (UPDN) status

#endif