/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F45K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ACC10 aliases
#define ACC10_TRIS                 TRISAbits.TRISA0
#define ACC10_LAT                  LATAbits.LATA0
#define ACC10_PORT                 PORTAbits.RA0
#define ACC10_WPU                  WPUAbits.WPUA0
#define ACC10_OD                   ODCONAbits.ODCA0
#define ACC10_ANS                  ANSELAbits.ANSELA0
#define ACC10_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define ACC10_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define ACC10_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define ACC10_GetValue()           PORTAbits.RA0
#define ACC10_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define ACC10_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define ACC10_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define ACC10_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define ACC10_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define ACC10_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define ACC10_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define ACC10_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set ACC10_CURR aliases
#define ACC10_CURR_TRIS                 TRISAbits.TRISA1
#define ACC10_CURR_LAT                  LATAbits.LATA1
#define ACC10_CURR_PORT                 PORTAbits.RA1
#define ACC10_CURR_WPU                  WPUAbits.WPUA1
#define ACC10_CURR_OD                   ODCONAbits.ODCA1
#define ACC10_CURR_ANS                  ANSELAbits.ANSELA1
#define ACC10_CURR_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define ACC10_CURR_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define ACC10_CURR_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define ACC10_CURR_GetValue()           PORTAbits.RA1
#define ACC10_CURR_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define ACC10_CURR_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define ACC10_CURR_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define ACC10_CURR_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define ACC10_CURR_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define ACC10_CURR_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define ACC10_CURR_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define ACC10_CURR_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set ACC9 aliases
#define ACC9_TRIS                 TRISAbits.TRISA2
#define ACC9_LAT                  LATAbits.LATA2
#define ACC9_PORT                 PORTAbits.RA2
#define ACC9_WPU                  WPUAbits.WPUA2
#define ACC9_OD                   ODCONAbits.ODCA2
#define ACC9_ANS                  ANSELAbits.ANSELA2
#define ACC9_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define ACC9_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define ACC9_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define ACC9_GetValue()           PORTAbits.RA2
#define ACC9_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define ACC9_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define ACC9_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define ACC9_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define ACC9_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define ACC9_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define ACC9_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define ACC9_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA3
#define LED_LAT                  LATAbits.LATA3
#define LED_PORT                 PORTAbits.RA3
#define LED_WPU                  WPUAbits.WPUA3
#define LED_OD                   ODCONAbits.ODCA3
#define LED_ANS                  ANSELAbits.ANSELA3
#define LED_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LED_GetValue()           PORTAbits.RA3
#define LED_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set VOLT aliases
#define VOLT_TRIS                 TRISAbits.TRISA4
#define VOLT_LAT                  LATAbits.LATA4
#define VOLT_PORT                 PORTAbits.RA4
#define VOLT_WPU                  WPUAbits.WPUA4
#define VOLT_OD                   ODCONAbits.ODCA4
#define VOLT_ANS                  ANSELAbits.ANSELA4
#define VOLT_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define VOLT_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define VOLT_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define VOLT_GetValue()           PORTAbits.RA4
#define VOLT_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define VOLT_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define VOLT_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define VOLT_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define VOLT_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define VOLT_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define VOLT_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define VOLT_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set IGN aliases
#define IGN_TRIS                 TRISAbits.TRISA5
#define IGN_LAT                  LATAbits.LATA5
#define IGN_PORT                 PORTAbits.RA5
#define IGN_WPU                  WPUAbits.WPUA5
#define IGN_OD                   ODCONAbits.ODCA5
#define IGN_ANS                  ANSELAbits.ANSELA5
#define IGN_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IGN_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IGN_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IGN_GetValue()           PORTAbits.RA5
#define IGN_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IGN_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IGN_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define IGN_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define IGN_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define IGN_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define IGN_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define IGN_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set ACC4_CURR aliases
#define ACC4_CURR_TRIS                 TRISAbits.TRISA6
#define ACC4_CURR_LAT                  LATAbits.LATA6
#define ACC4_CURR_PORT                 PORTAbits.RA6
#define ACC4_CURR_WPU                  WPUAbits.WPUA6
#define ACC4_CURR_OD                   ODCONAbits.ODCA6
#define ACC4_CURR_ANS                  ANSELAbits.ANSELA6
#define ACC4_CURR_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define ACC4_CURR_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define ACC4_CURR_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define ACC4_CURR_GetValue()           PORTAbits.RA6
#define ACC4_CURR_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define ACC4_CURR_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define ACC4_CURR_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define ACC4_CURR_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define ACC4_CURR_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define ACC4_CURR_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define ACC4_CURR_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define ACC4_CURR_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set LIGHT_RELAY aliases
#define LIGHT_RELAY_TRIS                 TRISAbits.TRISA7
#define LIGHT_RELAY_LAT                  LATAbits.LATA7
#define LIGHT_RELAY_PORT                 PORTAbits.RA7
#define LIGHT_RELAY_WPU                  WPUAbits.WPUA7
#define LIGHT_RELAY_OD                   ODCONAbits.ODCA7
#define LIGHT_RELAY_ANS                  ANSELAbits.ANSELA7
#define LIGHT_RELAY_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LIGHT_RELAY_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LIGHT_RELAY_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LIGHT_RELAY_GetValue()           PORTAbits.RA7
#define LIGHT_RELAY_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LIGHT_RELAY_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define LIGHT_RELAY_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define LIGHT_RELAY_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define LIGHT_RELAY_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define LIGHT_RELAY_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define LIGHT_RELAY_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define LIGHT_RELAY_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set ACC7 aliases
#define ACC7_TRIS                 TRISBbits.TRISB0
#define ACC7_LAT                  LATBbits.LATB0
#define ACC7_PORT                 PORTBbits.RB0
#define ACC7_WPU                  WPUBbits.WPUB0
#define ACC7_OD                   ODCONBbits.ODCB0
#define ACC7_ANS                  ANSELBbits.ANSELB0
#define ACC7_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define ACC7_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define ACC7_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define ACC7_GetValue()           PORTBbits.RB0
#define ACC7_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define ACC7_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define ACC7_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define ACC7_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define ACC7_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define ACC7_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define ACC7_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define ACC7_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set V3_EN aliases
#define V3_EN_TRIS                 TRISBbits.TRISB1
#define V3_EN_LAT                  LATBbits.LATB1
#define V3_EN_PORT                 PORTBbits.RB1
#define V3_EN_WPU                  WPUBbits.WPUB1
#define V3_EN_OD                   ODCONBbits.ODCB1
#define V3_EN_ANS                  ANSELBbits.ANSELB1
#define V3_EN_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define V3_EN_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define V3_EN_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define V3_EN_GetValue()           PORTBbits.RB1
#define V3_EN_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define V3_EN_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define V3_EN_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define V3_EN_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define V3_EN_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define V3_EN_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define V3_EN_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define V3_EN_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set ACC9_CURR aliases
#define ACC9_CURR_TRIS                 TRISBbits.TRISB2
#define ACC9_CURR_LAT                  LATBbits.LATB2
#define ACC9_CURR_PORT                 PORTBbits.RB2
#define ACC9_CURR_WPU                  WPUBbits.WPUB2
#define ACC9_CURR_OD                   ODCONBbits.ODCB2
#define ACC9_CURR_ANS                  ANSELBbits.ANSELB2
#define ACC9_CURR_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define ACC9_CURR_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define ACC9_CURR_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define ACC9_CURR_GetValue()           PORTBbits.RB2
#define ACC9_CURR_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define ACC9_CURR_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define ACC9_CURR_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define ACC9_CURR_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define ACC9_CURR_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define ACC9_CURR_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define ACC9_CURR_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define ACC9_CURR_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSELB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set ACC6_CURR aliases
#define ACC6_CURR_TRIS                 TRISCbits.TRISC0
#define ACC6_CURR_LAT                  LATCbits.LATC0
#define ACC6_CURR_PORT                 PORTCbits.RC0
#define ACC6_CURR_WPU                  WPUCbits.WPUC0
#define ACC6_CURR_OD                   ODCONCbits.ODCC0
#define ACC6_CURR_ANS                  ANSELCbits.ANSELC0
#define ACC6_CURR_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define ACC6_CURR_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define ACC6_CURR_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define ACC6_CURR_GetValue()           PORTCbits.RC0
#define ACC6_CURR_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define ACC6_CURR_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define ACC6_CURR_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define ACC6_CURR_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define ACC6_CURR_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define ACC6_CURR_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define ACC6_CURR_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define ACC6_CURR_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set SW1_12 aliases
#define SW1_12_TRIS                 TRISCbits.TRISC1
#define SW1_12_LAT                  LATCbits.LATC1
#define SW1_12_PORT                 PORTCbits.RC1
#define SW1_12_WPU                  WPUCbits.WPUC1
#define SW1_12_OD                   ODCONCbits.ODCC1
#define SW1_12_ANS                  ANSELCbits.ANSELC1
#define SW1_12_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SW1_12_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SW1_12_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SW1_12_GetValue()           PORTCbits.RC1
#define SW1_12_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SW1_12_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SW1_12_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SW1_12_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SW1_12_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SW1_12_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SW1_12_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define SW1_12_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set SW1_5 aliases
#define SW1_5_TRIS                 TRISCbits.TRISC2
#define SW1_5_LAT                  LATCbits.LATC2
#define SW1_5_PORT                 PORTCbits.RC2
#define SW1_5_WPU                  WPUCbits.WPUC2
#define SW1_5_OD                   ODCONCbits.ODCC2
#define SW1_5_ANS                  ANSELCbits.ANSELC2
#define SW1_5_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SW1_5_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SW1_5_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SW1_5_GetValue()           PORTCbits.RC2
#define SW1_5_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SW1_5_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SW1_5_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SW1_5_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SW1_5_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SW1_5_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SW1_5_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define SW1_5_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set SW1_34 aliases
#define SW1_34_TRIS                 TRISCbits.TRISC3
#define SW1_34_LAT                  LATCbits.LATC3
#define SW1_34_PORT                 PORTCbits.RC3
#define SW1_34_WPU                  WPUCbits.WPUC3
#define SW1_34_OD                   ODCONCbits.ODCC3
#define SW1_34_ANS                  ANSELCbits.ANSELC3
#define SW1_34_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SW1_34_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SW1_34_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SW1_34_GetValue()           PORTCbits.RC3
#define SW1_34_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SW1_34_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SW1_34_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SW1_34_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SW1_34_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SW1_34_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SW1_34_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define SW1_34_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set SW2_56 aliases
#define SW2_56_TRIS                 TRISCbits.TRISC4
#define SW2_56_LAT                  LATCbits.LATC4
#define SW2_56_PORT                 PORTCbits.RC4
#define SW2_56_WPU                  WPUCbits.WPUC4
#define SW2_56_OD                   ODCONCbits.ODCC4
#define SW2_56_ANS                  ANSELCbits.ANSELC4
#define SW2_56_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SW2_56_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SW2_56_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SW2_56_GetValue()           PORTCbits.RC4
#define SW2_56_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SW2_56_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SW2_56_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SW2_56_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SW2_56_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SW2_56_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SW2_56_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define SW2_56_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set ACC8_CURR aliases
#define ACC8_CURR_TRIS                 TRISCbits.TRISC5
#define ACC8_CURR_LAT                  LATCbits.LATC5
#define ACC8_CURR_PORT                 PORTCbits.RC5
#define ACC8_CURR_WPU                  WPUCbits.WPUC5
#define ACC8_CURR_OD                   ODCONCbits.ODCC5
#define ACC8_CURR_ANS                  ANSELCbits.ANSELC5
#define ACC8_CURR_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define ACC8_CURR_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define ACC8_CURR_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define ACC8_CURR_GetValue()           PORTCbits.RC5
#define ACC8_CURR_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define ACC8_CURR_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define ACC8_CURR_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define ACC8_CURR_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define ACC8_CURR_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define ACC8_CURR_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define ACC8_CURR_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define ACC8_CURR_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set ACC6 aliases
#define ACC6_TRIS                 TRISCbits.TRISC6
#define ACC6_LAT                  LATCbits.LATC6
#define ACC6_PORT                 PORTCbits.RC6
#define ACC6_WPU                  WPUCbits.WPUC6
#define ACC6_OD                   ODCONCbits.ODCC6
#define ACC6_ANS                  ANSELCbits.ANSELC6
#define ACC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define ACC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define ACC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define ACC6_GetValue()           PORTCbits.RC6
#define ACC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define ACC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define ACC6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define ACC6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define ACC6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define ACC6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define ACC6_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define ACC6_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set ACC8 aliases
#define ACC8_TRIS                 TRISCbits.TRISC7
#define ACC8_LAT                  LATCbits.LATC7
#define ACC8_PORT                 PORTCbits.RC7
#define ACC8_WPU                  WPUCbits.WPUC7
#define ACC8_OD                   ODCONCbits.ODCC7
#define ACC8_ANS                  ANSELCbits.ANSELC7
#define ACC8_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define ACC8_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define ACC8_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define ACC8_GetValue()           PORTCbits.RC7
#define ACC8_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define ACC8_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define ACC8_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define ACC8_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define ACC8_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define ACC8_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define ACC8_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define ACC8_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set SW2_910 aliases
#define SW2_910_TRIS                 TRISDbits.TRISD0
#define SW2_910_LAT                  LATDbits.LATD0
#define SW2_910_PORT                 PORTDbits.RD0
#define SW2_910_WPU                  WPUDbits.WPUD0
#define SW2_910_OD                   ODCONDbits.ODCD0
#define SW2_910_ANS                  ANSELDbits.ANSELD0
#define SW2_910_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define SW2_910_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define SW2_910_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define SW2_910_GetValue()           PORTDbits.RD0
#define SW2_910_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define SW2_910_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define SW2_910_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define SW2_910_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define SW2_910_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define SW2_910_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define SW2_910_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define SW2_910_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set SW2_78 aliases
#define SW2_78_TRIS                 TRISDbits.TRISD1
#define SW2_78_LAT                  LATDbits.LATD1
#define SW2_78_PORT                 PORTDbits.RD1
#define SW2_78_WPU                  WPUDbits.WPUD1
#define SW2_78_OD                   ODCONDbits.ODCD1
#define SW2_78_ANS                  ANSELDbits.ANSELD1
#define SW2_78_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define SW2_78_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define SW2_78_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define SW2_78_GetValue()           PORTDbits.RD1
#define SW2_78_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define SW2_78_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define SW2_78_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define SW2_78_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define SW2_78_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define SW2_78_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define SW2_78_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define SW2_78_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set SW2_12 aliases
#define SW2_12_TRIS                 TRISDbits.TRISD2
#define SW2_12_LAT                  LATDbits.LATD2
#define SW2_12_PORT                 PORTDbits.RD2
#define SW2_12_WPU                  WPUDbits.WPUD2
#define SW2_12_OD                   ODCONDbits.ODCD2
#define SW2_12_ANS                  ANSELDbits.ANSELD2
#define SW2_12_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define SW2_12_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define SW2_12_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define SW2_12_GetValue()           PORTDbits.RD2
#define SW2_12_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define SW2_12_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define SW2_12_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define SW2_12_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define SW2_12_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define SW2_12_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define SW2_12_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define SW2_12_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set SW2_34 aliases
#define SW2_34_TRIS                 TRISDbits.TRISD3
#define SW2_34_LAT                  LATDbits.LATD3
#define SW2_34_PORT                 PORTDbits.RD3
#define SW2_34_WPU                  WPUDbits.WPUD3
#define SW2_34_OD                   ODCONDbits.ODCD3
#define SW2_34_ANS                  ANSELDbits.ANSELD3
#define SW2_34_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define SW2_34_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define SW2_34_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define SW2_34_GetValue()           PORTDbits.RD3
#define SW2_34_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define SW2_34_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define SW2_34_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define SW2_34_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define SW2_34_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define SW2_34_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define SW2_34_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define SW2_34_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set ACC4 aliases
#define ACC4_TRIS                 TRISDbits.TRISD4
#define ACC4_LAT                  LATDbits.LATD4
#define ACC4_PORT                 PORTDbits.RD4
#define ACC4_WPU                  WPUDbits.WPUD4
#define ACC4_OD                   ODCONDbits.ODCD4
#define ACC4_ANS                  ANSELDbits.ANSELD4
#define ACC4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define ACC4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define ACC4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define ACC4_GetValue()           PORTDbits.RD4
#define ACC4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define ACC4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define ACC4_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define ACC4_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define ACC4_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define ACC4_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define ACC4_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define ACC4_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set ACC5 aliases
#define ACC5_TRIS                 TRISDbits.TRISD5
#define ACC5_LAT                  LATDbits.LATD5
#define ACC5_PORT                 PORTDbits.RD5
#define ACC5_WPU                  WPUDbits.WPUD5
#define ACC5_OD                   ODCONDbits.ODCD5
#define ACC5_ANS                  ANSELDbits.ANSELD5
#define ACC5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define ACC5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define ACC5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define ACC5_GetValue()           PORTDbits.RD5
#define ACC5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define ACC5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define ACC5_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define ACC5_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define ACC5_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define ACC5_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define ACC5_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define ACC5_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set ACC5_CURR aliases
#define ACC5_CURR_TRIS                 TRISDbits.TRISD6
#define ACC5_CURR_LAT                  LATDbits.LATD6
#define ACC5_CURR_PORT                 PORTDbits.RD6
#define ACC5_CURR_WPU                  WPUDbits.WPUD6
#define ACC5_CURR_OD                   ODCONDbits.ODCD6
#define ACC5_CURR_ANS                  ANSELDbits.ANSELD6
#define ACC5_CURR_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define ACC5_CURR_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define ACC5_CURR_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define ACC5_CURR_GetValue()           PORTDbits.RD6
#define ACC5_CURR_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define ACC5_CURR_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define ACC5_CURR_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define ACC5_CURR_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define ACC5_CURR_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define ACC5_CURR_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define ACC5_CURR_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define ACC5_CURR_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set ACC7_CURR aliases
#define ACC7_CURR_TRIS                 TRISDbits.TRISD7
#define ACC7_CURR_LAT                  LATDbits.LATD7
#define ACC7_CURR_PORT                 PORTDbits.RD7
#define ACC7_CURR_WPU                  WPUDbits.WPUD7
#define ACC7_CURR_OD                   ODCONDbits.ODCD7
#define ACC7_CURR_ANS                  ANSELDbits.ANSELD7
#define ACC7_CURR_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define ACC7_CURR_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define ACC7_CURR_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define ACC7_CURR_GetValue()           PORTDbits.RD7
#define ACC7_CURR_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define ACC7_CURR_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define ACC7_CURR_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define ACC7_CURR_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define ACC7_CURR_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define ACC7_CURR_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define ACC7_CURR_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define ACC7_CURR_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set LOWCURR_RELAY aliases
#define LOWCURR_RELAY_TRIS                 TRISEbits.TRISE0
#define LOWCURR_RELAY_LAT                  LATEbits.LATE0
#define LOWCURR_RELAY_PORT                 PORTEbits.RE0
#define LOWCURR_RELAY_WPU                  WPUEbits.WPUE0
#define LOWCURR_RELAY_OD                   ODCONEbits.ODCE0
#define LOWCURR_RELAY_ANS                  ANSELEbits.ANSELE0
#define LOWCURR_RELAY_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LOWCURR_RELAY_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LOWCURR_RELAY_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LOWCURR_RELAY_GetValue()           PORTEbits.RE0
#define LOWCURR_RELAY_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LOWCURR_RELAY_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LOWCURR_RELAY_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define LOWCURR_RELAY_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define LOWCURR_RELAY_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define LOWCURR_RELAY_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define LOWCURR_RELAY_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define LOWCURR_RELAY_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set SIREN_RELAY aliases
#define SIREN_RELAY_TRIS                 TRISEbits.TRISE1
#define SIREN_RELAY_LAT                  LATEbits.LATE1
#define SIREN_RELAY_PORT                 PORTEbits.RE1
#define SIREN_RELAY_WPU                  WPUEbits.WPUE1
#define SIREN_RELAY_OD                   ODCONEbits.ODCE1
#define SIREN_RELAY_ANS                  ANSELEbits.ANSELE1
#define SIREN_RELAY_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define SIREN_RELAY_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define SIREN_RELAY_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define SIREN_RELAY_GetValue()           PORTEbits.RE1
#define SIREN_RELAY_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define SIREN_RELAY_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define SIREN_RELAY_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define SIREN_RELAY_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define SIREN_RELAY_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define SIREN_RELAY_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define SIREN_RELAY_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define SIREN_RELAY_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set RADIO_RELAY aliases
#define RADIO_RELAY_TRIS                 TRISEbits.TRISE2
#define RADIO_RELAY_LAT                  LATEbits.LATE2
#define RADIO_RELAY_PORT                 PORTEbits.RE2
#define RADIO_RELAY_WPU                  WPUEbits.WPUE2
#define RADIO_RELAY_OD                   ODCONEbits.ODCE2
#define RADIO_RELAY_ANS                  ANSELEbits.ANSELE2
#define RADIO_RELAY_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define RADIO_RELAY_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define RADIO_RELAY_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define RADIO_RELAY_GetValue()           PORTEbits.RE2
#define RADIO_RELAY_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define RADIO_RELAY_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define RADIO_RELAY_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define RADIO_RELAY_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define RADIO_RELAY_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define RADIO_RELAY_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define RADIO_RELAY_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define RADIO_RELAY_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/