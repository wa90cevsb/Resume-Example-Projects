#include <proc/pic18f45k40.h>

#include "HD_Power.h"

uint16_t LEDCounter;
uint8_t BlinkCount;
uint8_t MaxBlinkCount;
uint8_t ADCChannelTable[135] = {  ACC4_CURR, IGN, ACC5_CURR, IGN, ACC6_CURR, IGN, ACC7_CURR, IGN, ACC8_CURR, IGN, ACC9_CURR, IGN, ACC10_CURR, IGN, 
                                VOLT, 
                                ACC4_CURR, IGN, ACC5_CURR, IGN, ACC6_CURR, IGN, ACC7_CURR, IGN, ACC8_CURR, IGN, ACC9_CURR, IGN, ACC10_CURR, IGN,                                  
                                SW1_12,
                                ACC4_CURR, IGN, ACC5_CURR, IGN, ACC6_CURR, IGN, ACC7_CURR, IGN, ACC8_CURR, IGN, ACC9_CURR, IGN, ACC10_CURR, IGN,                                  
                                SW1_34,
                                ACC4_CURR, IGN, ACC5_CURR, IGN, ACC6_CURR, IGN, ACC7_CURR, IGN, ACC8_CURR, IGN, ACC9_CURR, IGN, ACC10_CURR, IGN,                                 
                                SW1_5, 
                                ACC4_CURR, IGN, ACC5_CURR, IGN, ACC6_CURR, IGN, ACC7_CURR, IGN, ACC8_CURR, IGN, ACC9_CURR, IGN, ACC10_CURR, IGN,                                  
                                SW2_12, 
                                ACC4_CURR, IGN, ACC5_CURR, IGN, ACC6_CURR, IGN, ACC7_CURR, IGN, ACC8_CURR, IGN, ACC9_CURR, IGN, ACC10_CURR, IGN,                                  
                                SW2_34,
                                ACC4_CURR, IGN, ACC5_CURR, IGN, ACC6_CURR, IGN, ACC7_CURR, IGN, ACC8_CURR, IGN, ACC9_CURR, IGN, ACC10_CURR, IGN,                                  
                                SW2_56, 
                                ACC4_CURR, IGN, ACC5_CURR, IGN, ACC6_CURR, IGN, ACC7_CURR, IGN, ACC8_CURR, IGN, ACC9_CURR, IGN, ACC10_CURR, IGN,                                  
                                SW2_78, 
                                ACC4_CURR, IGN, ACC5_CURR, IGN, ACC6_CURR, IGN, ACC7_CURR, IGN, ACC8_CURR, IGN, ACC9_CURR, IGN, ACC10_CURR, IGN,                               
                                SW2_910  };
volatile uint8_t ADCChannelCount;
volatile uint16_t ignADC;
volatile uint16_t voltADC;
volatile uint16_t sw1p12;
volatile uint16_t sw1p34;
volatile uint16_t sw1p5;
volatile uint16_t sw2p12;
volatile uint16_t sw2p34;
volatile uint16_t sw2p56;
volatile uint16_t sw2p78;
volatile uint16_t sw2p910;
volatile uint16_t current[7];

uint8_t  LED_Active;
uint8_t  LED_Blink_Count;


uint16_t GetSwitches()
{
    uint16_t res;
    res = 0;
    
    if (sw2p12 > 570)      res |= 0x0003;
    else if (sw2p12 > 413) res |= 0x0002;
    else if (sw2p12 > 244) res |= 0x0001;
    
    if (sw2p34 > 570)      res |= 0x000c;
    else if (sw2p34 > 413) res |= 0x0008;
    else if (sw2p34 > 244) res |= 0x0004;
    
    if (sw2p56 > 570)      res |= 0x0030;
    else if (sw2p56 > 413) res |= 0x0020;
    else if (sw2p56 > 244) res |= 0x0010;
    
    if (sw2p78 > 570)      res |= 0x00c0;
    else if (sw2p78 > 413) res |= 0x0080;
    else if (sw2p78 > 244) res |= 0x0040;
    
    if (sw2p910 > 570)      res |= 0x0300;
    else if (sw2p910 > 413) res |= 0x0200;
    else if (sw2p910 > 244) res |= 0x0100;
    
    return res;
}

uint8_t GetVoltage()
{
    uint32_t res;
    res = voltADC;         //3222uV/bit
    res *= 24;
    res /= 100;
    return (uint8_t)res;    //Result in 100s the millivolts
}

uint16_t GetVoltThresh()
{
    if (sw1p5 > 500)
        return 110;      //9V Threshold
    else
        return 90;     //11V Threshold
}

uint8_t GetIgnition()
{
    uint32_t res;
    res = (uint32_t)ignADC;         //3222uV/bit
    res *= 24;
    res /= 100;
    return (uint8_t)res;        //Result in 100s the millivolts
}

uint16_t GetTimeout()
{
    uint8_t minutes;
    minutes = 0;
    if (sw1p12 > 600)
        minutes += 45;
    else if (sw1p12 > 450)
        minutes += 30;
    else if (sw1p12 > 300)
        minutes += 15;
    
    if (sw1p34 > 600)
        minutes += 60;
    else if (sw1p34 > 450)
        Nop();
    else if (sw1p34 > 300)
        minutes += 60;
    
    return (uint16_t)minutes*60;
}

void ConversionComplete()
{
    switch (ADPCH)
    {
        case ACC4_CURR:
            if (ADRES > 7*AMPS)
            {
                ACC4_SetLow();
                tripped |= ACC4_t;
            }
            current[0] = ADRES;
            break;
            
        case ACC5_CURR:
            if (ADRES > 5*AMPS)
            {
                ACC5_SetLow();
                tripped |= ACC5_t;
            }
            current[1] = ADRES;
            break;
            
        case ACC6_CURR:
            if (ADRES > 5*AMPS)
            {
                ACC6_SetLow();
                tripped |= ACC6_t;
            }
            current[2] = ADRES;
            break;
            
        case ACC7_CURR:
            if (ADRES > 8*AMPS)
            {
                ACC7_SetLow();
                tripped |= ACC7_t;
            }
            else if (ADRES > 3*AMPS)
                current[3] += 0x0400;
            else
                current[3] &= 0x03FF;
            current[3] = ADRES + (current[3]&0xFC00);
            break;
            
        case ACC8_CURR:
            if (ADRES > 8*AMPS)
            {
                ACC8_SetLow();
                tripped |= ACC8_t;
            }
            else if (ADRES > 3*AMPS)
                current[4] += 0x0400;
            else
                current[4] &= 0x03FF;
            current[4] = ADRES + (current[4]&0xFC00);
            break;
            
        case ACC9_CURR:
            if (ADRES > 8*AMPS)
            {
                ACC9_SetLow();
                tripped |= ACC9_t;
            }
            else if (ADRES > 2*AMPS)
                current[5] += 0x0400;
            else
                current[5] &= 0x03FF;
            current[5] = ADRES + (current[5]&0xFC00);
            break;
            
        case ACC10_CURR:
            if (ADRES > 8*AMPS)
            {
                ACC10_SetLow();
                tripped |= ACC10_t;
            }
            else if (ADRES > 2*AMPS)
                current[6] += 0x0400;
            else
                current[6] &= 0x03FF;
            current[6] = ADRES + (current[6]&0xFC00);
            break;            
            
        case IGN:
            ignADC = ADRES;
            break;
        case VOLT:
            voltADC = ADRES;
            break;
        case SW1_12:
            sw1p12 = ADRES;
            break;
        case SW1_34:
            sw1p34 = ADRES;
            break;
        case SW1_5:
            sw1p5 = ADRES;
            break;
        case SW2_12:
            sw2p12 = ADRES;
            break;
        case SW2_34:
            sw2p34 = ADRES;
            break;
        case SW2_56:
            sw2p56 = ADRES;
            break;
        case SW2_78:
            sw2p78 = ADRES;
            break;
        case SW2_910:
            sw2p910 = ADRES;
            break;
    }
    
    ADPCH = ADCChannelTable[ADCChannelCount];
    ADCChannelCount++;
    if (ADCChannelCount > 134)
        ADCChannelCount = 0;
}

void ADCINT_Init()
{
    // Turn off timer
    T2CON = 0x00;
    // Auto-trigger on TMR2 overflow
    ADACT = 0x04;
    // Initialize channel
    ADPCH = ACC4_CURR;
    
    // Set ISR
    ADCC_SetADIInterruptHandler(ConversionComplete);
    
    // Start converting
    T2CLKCON = 0x05;  // T2CS MFINTOSC_31.25KHz
    T2PR = 0x0a;       // Period 10   (1/31.25KHz)*11 = 352us
                            // ADC conversion takes ~65 us, so there is about
                            // 285us for code execution between ADC readings
    //T2PR = 0x2a;  // slower rate for debugging
    T2CON = 0x80;   // Start timer
}

void LEDRoutine()
{
    if(tripped)
    {
        if(LED_GetValue() == 1)     //LED is off, so let figure out where we are)
        {
            if(LED_Active == 0)     //Nothing active, so let see who is active
            {
                if((tripped & ACC4_t) ==  ACC4_t)
                    LED_Active = 4;
                else if((tripped & ACC5_t) ==  ACC5_t)
                    LED_Active = 5;
                else if((tripped & ACC6_t) ==  ACC6_t)
                    LED_Active = 6;
                else if((tripped & ACC7_t) ==  ACC7_t)
                    LED_Active = 7;
                else if((tripped & ACC8_t) ==  ACC8_t)
                    LED_Active = 8;
                else if((tripped & ACC9_t) ==  ACC9_t)
                    LED_Active = 9;
                else if((tripped & ACC10_t) ==  ACC10_t)
                    LED_Active = 10;
            }
            
            if(LED_Blink_Count > 250)          //This means we are between cycles, and need to have two cycles being off
            {
                LED_Blink_Count++;
                if(LED_Blink_Count < 255)       //Up this value to increase delay between blinks, don't go above 255
                    return;
                LED_Blink_Count = 0;
            }
            
            LED_SetLow();                       //No matter where we are at in the count, the LED gets turned on
            
            if((LED_Blink_Count+1) < LED_Active)
            {
                LED_Blink_Count++;
                return;
            }
            else
                LED_Blink_Count = 251;          //Done with this LED, set for pause between blinks

            //if we got here it is done with the current blinking for the current LED find the next LED tripped
            switch(LED_Active)      //Not going to use break statements so it goes through them all
            {
                case 4:
                    if((tripped & ACC5_t) == ACC5_t)
                    {
                        LED_Active = 5;
                        return;
                    }
                case 5:
                    if((tripped & ACC6_t) == ACC6_t)
                    {
                        LED_Active = 6;
                        return;
                    }
                case 6:
                    if((tripped & ACC7_t) == ACC7_t)
                    {
                        LED_Active = 7;
                        return;
                    }
                case 7:
                    if((tripped & ACC8_t) == ACC8_t)
                    {
                        LED_Active = 8;
                        return;
                    }
                case 8:
                    if((tripped & ACC9_t) == ACC9_t)
                    {
                        LED_Active = 9;
                        return;
                    }
                case 9:
                    if((tripped & ACC10_t) == ACC10_t)
                    {
                        LED_Active = 10;
                        return;
                    }
                case 10:
                    if((tripped & ACC4_t) == ACC4_t)
                    {
                        LED_Active = 4;
                        return;
                    }
                    if((tripped & ACC5_t) == ACC5_t)
                    {
                        LED_Active = 5;
                        return;
                    }
                    if((tripped & ACC6_t) == ACC6_t)
                    {
                        LED_Active = 6;
                        return;
                    }
                    if((tripped & ACC7_t) == ACC7_t)
                    {
                        LED_Active = 7;
                        return;
                    }
                    if((tripped & ACC8_t) == ACC8_t)
                    {
                        LED_Active = 8;
                        return;
                    }
                    if((tripped & ACC9_t) == ACC9_t)
                    {
                        LED_Active = 9;
                        return;
                    }
                    if((tripped & ACC10_t) == ACC10_t)
                    {
                        LED_Active = 10;
                        return;
                    }
                    LED_Active = 0;     //Nothing tripped
            }
        }
        else                        //LED is on, so turn it off
            LED_SetHigh();
    }
    else
    {
        LED_SetLow();
        LED_Active = 0;
        LED_Blink_Count = 0;
    }
}

void PowerOff()
{
    LED_SetHigh();
    LIGHT_RELAY_SetLow();
    SIREN_RELAY_SetLow();
    RADIO_RELAY_SetLow();
    LOWCURR_RELAY_SetLow();
    ACC4_SetDigitalInput();
    ACC5_SetDigitalInput();
    ACC6_SetDigitalInput();
    ACC7_SetDigitalInput();
    ACC8_SetDigitalInput();
    ACC9_SetDigitalInput();
    ACC10_SetDigitalInput();
    V3_EN_SetDigitalInput();
    
    __delay_ms(10);
    
    T0_ENABLE = 1;
    T1_ENABLE = 0;
    T2_ENABLE = 0;
    
    VREGCON = 0x2;
    ADACT = 0x0;
    ADPCH = IGN;
    CPUDOZEbits.IDLEN = 0;
    PIE1bits.ADIE = 0;
    PIE0bits.TMR0IE = 1;
    INTCONbits.GIE = 0;
    INTCONbits.PEIE = 1;
    T0CON1 = 0x9B;
    uint8_t pr[15];
    
    while (ADCC_GetSingleConversion(IGN) < 250)
    {
        __delay_ms(5);
        ADC_ENABLE = 0;
        __delay_ms(5);
        Sleep();
        ADC_ENABLE = 1;
        __delay_ms(5);
        PIR0bits.TMR0IF = 0;
        __delay_ms(5);
    }
    
    PIE1bits.ADIE = 1;
    INTCONbits.GIE = 1;
    PIE0bits.TMR0IE = 0;
    T0CON1 = 0x98;
    ADC_ENABLE = 1;
    T0_ENABLE = 1;
    T1_ENABLE = 0;
    T2_ENABLE = 1;
    ADACT = 0x4;
    ACC4_SetDigitalOutput();
    ACC5_SetDigitalOutput();
    ACC6_SetDigitalOutput();
    ACC7_SetDigitalOutput();
    ACC8_SetDigitalOutput();
    ACC9_SetDigitalOutput();
    ACC10_SetDigitalOutput();
    V3_EN_SetDigitalOutput();
}

