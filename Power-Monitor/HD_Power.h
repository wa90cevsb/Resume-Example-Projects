/* 
 * File:   HD_Power.h
 * Author: maste
 *
 * Created on November 29, 2022, 1:26 PM
 */

#ifndef HD_POWER_H
#define	HD_POWER_H
#include "Serial.h"
#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdio.h>


#ifdef	__cplusplus
extern "C" {
#endif
    
uint16_t GetSwitches();
uint8_t GetVoltage();
uint16_t GetVoltThresh();
uint8_t GetIgnition();
uint16_t GetTimeout();
void ADCINT_Init();
void TMR_Overflowed(void);
#define AMPS 108
volatile uint8_t tripped;
#define ACC4_t  0x01
#define ACC5_t  0x02
#define ACC6_t  0x04
#define ACC7_t  0x08
#define ACC8_t  0x10
#define ACC9_t  0x20
#define ACC10_t 0x40
void LEDRoutine();
void PowerOff();
volatile uint16_t current[7];
void TMR0_IH_Runtime();


#define ADC_ENABLE ADCON0bits.ADON
#define T0_ENABLE T0CON0bits.T0EN
#define T1_ENABLE T1CONbits.TMR1ON
#define T2_ENABLE T2CONbits.T2ON

#ifdef	__cplusplus
}
#endif

#endif	/* HD_POWER_H */

