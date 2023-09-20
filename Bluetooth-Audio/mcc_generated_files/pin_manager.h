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
        Device            :  PIC16F15345
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

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA2
#define LED_LAT                  LATAbits.LATA2
#define LED_PORT                 PORTAbits.RA2
#define LED_WPU                  WPUAbits.WPUA2
#define LED_OD                   ODCONAbits.ODCA2
#define LED_ANS                  ANSELAbits.ANSA2
#define LED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_GetValue()           PORTAbits.RA2
#define LED_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set AMP_MUTE_R aliases
#define AMP_MUTE_R_TRIS                 TRISBbits.TRISB4
#define AMP_MUTE_R_LAT                  LATBbits.LATB4
#define AMP_MUTE_R_PORT                 PORTBbits.RB4
#define AMP_MUTE_R_WPU                  WPUBbits.WPUB4
#define AMP_MUTE_R_OD                   ODCONBbits.ODCB4
#define AMP_MUTE_R_ANS                  ANSELBbits.ANSB4
#define AMP_MUTE_R_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define AMP_MUTE_R_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define AMP_MUTE_R_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define AMP_MUTE_R_GetValue()           PORTBbits.RB4
#define AMP_MUTE_R_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define AMP_MUTE_R_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define AMP_MUTE_R_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define AMP_MUTE_R_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define AMP_MUTE_R_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define AMP_MUTE_R_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define AMP_MUTE_R_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define AMP_MUTE_R_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set AMP_MUTE_L aliases
#define AMP_MUTE_L_TRIS                 TRISBbits.TRISB5
#define AMP_MUTE_L_LAT                  LATBbits.LATB5
#define AMP_MUTE_L_PORT                 PORTBbits.RB5
#define AMP_MUTE_L_WPU                  WPUBbits.WPUB5
#define AMP_MUTE_L_OD                   ODCONBbits.ODCB5
#define AMP_MUTE_L_ANS                  ANSELBbits.ANSB5
#define AMP_MUTE_L_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define AMP_MUTE_L_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define AMP_MUTE_L_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define AMP_MUTE_L_GetValue()           PORTBbits.RB5
#define AMP_MUTE_L_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define AMP_MUTE_L_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define AMP_MUTE_L_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define AMP_MUTE_L_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define AMP_MUTE_L_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define AMP_MUTE_L_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define AMP_MUTE_L_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define AMP_MUTE_L_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set BT_NEXT aliases
#define BT_NEXT_TRIS                 TRISBbits.TRISB6
#define BT_NEXT_LAT                  LATBbits.LATB6
#define BT_NEXT_PORT                 PORTBbits.RB6
#define BT_NEXT_WPU                  WPUBbits.WPUB6
#define BT_NEXT_OD                   ODCONBbits.ODCB6
#define BT_NEXT_ANS                  ANSELBbits.ANSB6
#define BT_NEXT_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define BT_NEXT_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define BT_NEXT_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define BT_NEXT_GetValue()           PORTBbits.RB6
#define BT_NEXT_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define BT_NEXT_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define BT_NEXT_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define BT_NEXT_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define BT_NEXT_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define BT_NEXT_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define BT_NEXT_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define BT_NEXT_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set VOL_CLK aliases
#define VOL_CLK_TRIS                 TRISBbits.TRISB7
#define VOL_CLK_LAT                  LATBbits.LATB7
#define VOL_CLK_PORT                 PORTBbits.RB7
#define VOL_CLK_WPU                  WPUBbits.WPUB7
#define VOL_CLK_OD                   ODCONBbits.ODCB7
#define VOL_CLK_ANS                  ANSELBbits.ANSB7
#define VOL_CLK_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define VOL_CLK_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define VOL_CLK_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define VOL_CLK_GetValue()           PORTBbits.RB7
#define VOL_CLK_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define VOL_CLK_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define VOL_CLK_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define VOL_CLK_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define VOL_CLK_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define VOL_CLK_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define VOL_CLK_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define VOL_CLK_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set R_BUT aliases
#define R_BUT_TRIS                 TRISCbits.TRISC0
#define R_BUT_LAT                  LATCbits.LATC0
#define R_BUT_PORT                 PORTCbits.RC0
#define R_BUT_WPU                  WPUCbits.WPUC0
#define R_BUT_OD                   ODCONCbits.ODCC0
#define R_BUT_ANS                  ANSELCbits.ANSC0
#define R_BUT_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define R_BUT_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define R_BUT_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define R_BUT_GetValue()           PORTCbits.RC0
#define R_BUT_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define R_BUT_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define R_BUT_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define R_BUT_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define R_BUT_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define R_BUT_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define R_BUT_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define R_BUT_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set L_BUT aliases
#define L_BUT_TRIS                 TRISCbits.TRISC1
#define L_BUT_LAT                  LATCbits.LATC1
#define L_BUT_PORT                 PORTCbits.RC1
#define L_BUT_WPU                  WPUCbits.WPUC1
#define L_BUT_OD                   ODCONCbits.ODCC1
#define L_BUT_ANS                  ANSELCbits.ANSC1
#define L_BUT_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define L_BUT_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define L_BUT_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define L_BUT_GetValue()           PORTCbits.RC1
#define L_BUT_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define L_BUT_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define L_BUT_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define L_BUT_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define L_BUT_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define L_BUT_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define L_BUT_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define L_BUT_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SWITCH_EN aliases
#define SWITCH_EN_TRIS                 TRISCbits.TRISC2
#define SWITCH_EN_LAT                  LATCbits.LATC2
#define SWITCH_EN_PORT                 PORTCbits.RC2
#define SWITCH_EN_WPU                  WPUCbits.WPUC2
#define SWITCH_EN_OD                   ODCONCbits.ODCC2
#define SWITCH_EN_ANS                  ANSELCbits.ANSC2
#define SWITCH_EN_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SWITCH_EN_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SWITCH_EN_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SWITCH_EN_GetValue()           PORTCbits.RC2
#define SWITCH_EN_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SWITCH_EN_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SWITCH_EN_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SWITCH_EN_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SWITCH_EN_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SWITCH_EN_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SWITCH_EN_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SWITCH_EN_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set VOL_DATA aliases
#define VOL_DATA_TRIS                 TRISCbits.TRISC3
#define VOL_DATA_LAT                  LATCbits.LATC3
#define VOL_DATA_PORT                 PORTCbits.RC3
#define VOL_DATA_WPU                  WPUCbits.WPUC3
#define VOL_DATA_OD                   ODCONCbits.ODCC3
#define VOL_DATA_ANS                  ANSELCbits.ANSC3
#define VOL_DATA_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define VOL_DATA_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define VOL_DATA_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define VOL_DATA_GetValue()           PORTCbits.RC3
#define VOL_DATA_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define VOL_DATA_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define VOL_DATA_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define VOL_DATA_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define VOL_DATA_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define VOL_DATA_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define VOL_DATA_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define VOL_DATA_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set VOLT aliases
#define VOLT_TRIS                 TRISCbits.TRISC4
#define VOLT_LAT                  LATCbits.LATC4
#define VOLT_PORT                 PORTCbits.RC4
#define VOLT_WPU                  WPUCbits.WPUC4
#define VOLT_OD                   ODCONCbits.ODCC4
#define VOLT_ANS                  ANSELCbits.ANSC4
#define VOLT_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define VOLT_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define VOLT_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define VOLT_GetValue()           PORTCbits.RC4
#define VOLT_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define VOLT_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define VOLT_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define VOLT_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define VOLT_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define VOLT_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define VOLT_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define VOLT_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set VOL_BUT aliases
#define VOL_BUT_TRIS                 TRISCbits.TRISC5
#define VOL_BUT_LAT                  LATCbits.LATC5
#define VOL_BUT_PORT                 PORTCbits.RC5
#define VOL_BUT_WPU                  WPUCbits.WPUC5
#define VOL_BUT_OD                   ODCONCbits.ODCC5
#define VOL_BUT_ANS                  ANSELCbits.ANSC5
#define VOL_BUT_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define VOL_BUT_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define VOL_BUT_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define VOL_BUT_GetValue()           PORTCbits.RC5
#define VOL_BUT_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define VOL_BUT_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define VOL_BUT_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define VOL_BUT_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define VOL_BUT_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define VOL_BUT_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define VOL_BUT_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define VOL_BUT_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set SWITCH_STATE aliases
#define SWITCH_STATE_TRIS                 TRISCbits.TRISC6
#define SWITCH_STATE_LAT                  LATCbits.LATC6
#define SWITCH_STATE_PORT                 PORTCbits.RC6
#define SWITCH_STATE_WPU                  WPUCbits.WPUC6
#define SWITCH_STATE_OD                   ODCONCbits.ODCC6
#define SWITCH_STATE_ANS                  ANSELCbits.ANSC6
#define SWITCH_STATE_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SWITCH_STATE_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SWITCH_STATE_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SWITCH_STATE_GetValue()           PORTCbits.RC6
#define SWITCH_STATE_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SWITCH_STATE_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SWITCH_STATE_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SWITCH_STATE_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SWITCH_STATE_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SWITCH_STATE_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define SWITCH_STATE_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define SWITCH_STATE_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set VOL_L_S aliases
#define VOL_L_S_TRIS                 TRISCbits.TRISC7
#define VOL_L_S_LAT                  LATCbits.LATC7
#define VOL_L_S_PORT                 PORTCbits.RC7
#define VOL_L_S_WPU                  WPUCbits.WPUC7
#define VOL_L_S_OD                   ODCONCbits.ODCC7
#define VOL_L_S_ANS                  ANSELCbits.ANSC7
#define VOL_L_S_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define VOL_L_S_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define VOL_L_S_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define VOL_L_S_GetValue()           PORTCbits.RC7
#define VOL_L_S_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define VOL_L_S_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define VOL_L_S_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define VOL_L_S_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define VOL_L_S_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define VOL_L_S_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define VOL_L_S_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define VOL_L_S_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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