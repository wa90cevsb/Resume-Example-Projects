



/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F15345
        Driver Version    :  2.00
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

#include "BT_Audio.h"






/*
                         Main application
 */


void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    uint16_t buffer[ERASE_FLASH_BLOCKSIZE];
    
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    __delay_ms(250);
    
    
    SWITCH_EN_SetHigh();
    
    print("\n\n\n");
    print(PROMPT);
    SWITCH_STATE_SetHigh();
    min_vol = FLASH_ReadWord(0x1FFD);
    if (min_vol > 100)
    {
        min_vol = 100;
        FLASH_WriteWord(0x1FFD,buffer,100);
    }
    vol = min_vol;
    SetVolume(vol, 0);
    SetVolume(vol, 1);
    SWITCH_EN_SetLow();
    
    uint16_t short_thresh = SECONDS/20;
    uint16_t med_thresh = SECONDS;
    uint16_t wait_timout = SECONDS/10;
    uint16_t long_thresh = 4*SECONDS;
    uint8_t l_state,r_state,b_state;
    
    
    for (int i = 0; i < 21; i++)
    {
        __delay_ms(11);
        AMP_MUTE_L_Toggle();
        AMP_MUTE_R_Toggle();
    }
    
    
    uint8_t sine_cnt = 0;
    uint8_t beep_cnt = 1;
    uint16_t left_tmr_cnt;
    uint16_t right_tmr_cnt;
    uint16_t board_tmr_cnt;
    uint8_t sine_table[22] = { 7,9,11,12,13,14,14,13,12,11,9,7,5,3,2,1,0,0,1,2,3,5 };
    Init_Buttons();
    
    while (1)
    {
        Serial();
        
        
        if (beep)
        {
            sine_cnt++;
            if ((beep_cnt < 15) || (beep_cnt > 22))
                DAC1_SetOutput(sine_table[sine_cnt]);
            if (sine_cnt == 22)
            {
                sine_cnt = 0;
                if (beep_cnt++ > 35)
                {
                    beep = 0;
                    beep_cnt = 1;
                }
            }
        }
        
        
        
        switch (l_state)
        {
            case NO_PRESS:
                if(Get_L())
                {
                    l_state = PRESS;
                    left_tmr_cnt = TMR0_ReadTimer();
                }
                break;
            case PRESS:
                if (!Get_L())
                    l_state = NO_PRESS;
                else if (TMR0_ReadTimer()-left_tmr_cnt > short_thresh)
                    l_state = SHORT_PRESS;
                break;
            case SHORT_PRESS:
                if (!Get_L())
                {
                    l_state = WAIT;
                    left_tmr_cnt = TMR0_ReadTimer();
                }
                else if (TMR0_ReadTimer()-left_tmr_cnt > med_thresh)
                    l_state = LONG_PRESS;
                break;
            case WAIT:
                if (Get_L())
                {
                    LeftDoubleCb();  // Left button double press callback
                    while (Get_L());
                    l_state = NO_PRESS;
                }
                else if (TMR0_ReadTimer()-left_tmr_cnt > wait_timout)
                {
                    LeftShortCb();    // Left button short press callback
                    l_state = NO_PRESS;
                }
                break;
            case LONG_PRESS:
                if (!Get_L())
                {
                    LeftMedCb();   // Left button medium press callback
                    l_state = NO_PRESS;
                }
                else if (TMR0_ReadTimer()-left_tmr_cnt > long_thresh)
                {
                    LeftLongCb();   // Left button long press callback
                    while (Get_L());
                    l_state = NO_PRESS;
                }
                break;
            default:
                l_state = NO_PRESS;
                break;
        }
        
        switch (r_state)
        {
            case NO_PRESS:
                if(Get_R())
                {
                    r_state = PRESS;
                    right_tmr_cnt = TMR0_ReadTimer();
                }
                break;
            case PRESS:
                if (!Get_R())
                    r_state = NO_PRESS;
                else if (TMR0_ReadTimer()-right_tmr_cnt > short_thresh)
                    r_state = SHORT_PRESS;
                break;
            case SHORT_PRESS:
                if (!Get_R())
                {
                    r_state = WAIT;
                    right_tmr_cnt = TMR0_ReadTimer();
                }
                else if (TMR0_ReadTimer()-right_tmr_cnt > med_thresh)
                    r_state = LONG_PRESS;
                break;
            case WAIT:
                if (Get_R())
                {
                    RightDoubleCb();  // Right button double press callback
                    while (Get_R());
                    r_state = NO_PRESS;
                }
                else if (TMR0_ReadTimer()-right_tmr_cnt > wait_timout)
                {
                    RightShortCb();    // Right button short press callback
                    r_state = NO_PRESS;
                }
                break;
            case LONG_PRESS:
                if (!Get_R())
                {
                    RightMedCb();   // Right button medium press callback
                    r_state = NO_PRESS;
                }
                else if (TMR0_ReadTimer()-right_tmr_cnt > long_thresh)
                {
                    RightLongCb();   // Right button long press callback
                    while (Get_R());
                    r_state = NO_PRESS;
                }
                break;
            default:
                r_state = NO_PRESS;
                break;
        }
        
        switch (b_state)
        {
            case NO_PRESS:
                if(BOARD_PRESSED)
                {
                    b_state = PRESS;
                    board_tmr_cnt = TMR0_ReadTimer();
                }
                break;
            case PRESS:
                if (!BOARD_PRESSED)
                    b_state = NO_PRESS;
                else if (TMR0_ReadTimer()-board_tmr_cnt > short_thresh)
                    b_state = SHORT_PRESS;
                break;
            case SHORT_PRESS:
                if (!BOARD_PRESSED)
                {
                    b_state = WAIT;
                    board_tmr_cnt = TMR0_ReadTimer();
                }
                else if (TMR0_ReadTimer()-board_tmr_cnt > med_thresh)
                    b_state = LONG_PRESS;
                break;
            case WAIT:
                if (BOARD_PRESSED)
                {
                    BoardDoubleCb();  // Board button double press callback
                    while (BOARD_PRESSED);
                    b_state = NO_PRESS;
                }
                else if (TMR0_ReadTimer()-board_tmr_cnt > wait_timout)
                {
                    BoardShortCb();    // Board button short press callback
                    b_state = NO_PRESS;
                }
                break;
            case LONG_PRESS:
                if (!BOARD_PRESSED)
                {
                    BoardMedCb();   // Board button medium press callback
                    b_state = NO_PRESS;
                }
                else if (TMR0_ReadTimer()-board_tmr_cnt > long_thresh)
                {
                    BoardLongCb();   // Board button long press callback
                    while (BOARD_PRESSED);
                    b_state = NO_PRESS;
                }
                break;
            default:
                b_state = NO_PRESS;
                break;
        }
    }
}
/**
 End of File
*/