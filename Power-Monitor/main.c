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
        Device            :  PIC18F45K40
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

#include "mcc_generated_files/mcc.h"
#include "HD_Power.h"

/*
                         Main application
 */

void Test_Failed(void)
{
    print("****Failed****\n\r");
    while(1);
}

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    INTERRUPT_PeripheralInterruptEnable();
    INTERRUPT_GlobalInterruptLowEnable();
    INTERRUPT_GlobalInterruptHighEnable();
    
    PMD1 = 0x6A;
    PMD2 = 0x47;
    PMD3 = 0x0F;
    PMD4 = 0xB1;
    
    uint8_t undervolt_timer;
    uint16_t timer_read;
    uint16_t re_en_timer;
    uint16_t time_out;
    uint8_t ignf;
    uint8_t test_counter;
    char pr[50];
    
    LIGHT_RELAY_SetLow();
    SIREN_RELAY_SetLow();
    RADIO_RELAY_SetLow();
    LOWCURR_RELAY_SetLow();
    ACC4_SetLow();
    ACC5_SetLow();
    ACC6_SetLow();
    ACC7_SetLow();
    ACC8_SetLow();
    ACC9_SetLow();
    ACC10_SetLow();
    V3_EN_SetHigh();
    LED_SetHigh();
    
    time_out = 0;
    test_counter = 0;
    TMR4_StartTimer();
    print("\n\nPress <space> 3 times to test.");
    while(time_out < 16)
    {        
        if(TMR4_HasOverflowOccured())
        {
            time_out++;
            print(".");
        }
        
        if(EUSART1_is_rx_ready())
        {
            if(EUSART1_Read() == ' ')
                test_counter++;
            else
                test_counter = 0;
            
            if(test_counter == 3)       //Perform Functional Test
            {
                if(EUSART1_is_rx_ready())
                    EUSART1_Read();         //Throw away any key presses
                __delay_ms(500);
                ADCINT_Init();
                print("Apply 12V\n\r");
                if(EUSART1_is_rx_ready())
                    EUSART1_Read();         //Throw away any key presses
                __delay_ms(1000);
                print("Install all fuses\n\r");
                if(EUSART1_is_rx_ready())
                    EUSART1_Read();         //Throw away any key presses
                __delay_ms(1000);
                print("Set all DIP switches On - Press <space>\n");
                EUSART1_Read();         
                print("SW2 ");
                if(GetSwitches() != 0x3FF)
                    Test_Failed();
                print("Passed.\n\rSW1 ");

                if(GetTimeout() != 6300 || GetVoltThresh() != 110)
                {
                    Test_Failed();
                }
                print("Passed.\n\r");
                
                LED_SetHigh();
                print("Press <space> if LED Off?\n\r");
                if(EUSART1_Read() != ' ')
                {
                    Test_Failed();
                }
                print("Passed.\n\r");

                LED_SetLow();
                print("Press <space> if LED On?\n\r");
                if(EUSART1_Read() != ' ')
                {
                    Test_Failed();
                }
                print("Passed.\n\r");

                print("Disconnect IGN Input - Press <space>\n\r");
                if(EUSART1_Read() == ' ')
                {
                    if(GetIgnition() > 60)
                        Test_Failed();
                }
                print("Passed.\n\r");

                print("Connect IGN Input - Press <space>\n\r");
                if(EUSART1_Read() == ' ')
                {
                    if(GetIgnition() < 60)
                        Test_Failed();
                }
                print("Passed.\n\r");

                print("Probe odd shaped P2 terminal - Press <space> if 12V\n\r");
                if(EUSART1_Read() != ' ')
                {
                    Test_Failed();
                }
                print("Passed.\n\r");

                RADIO_RELAY_SetHigh();
                LIGHT_RELAY_SetHigh();
                SIREN_RELAY_SetHigh();
                print("Probe left screw terminals of P3/P5/P7 - Press <space> if all 12V\n\r");
                if(EUSART1_Read() != ' ')
                {
                    Test_Failed();
                }
                print("Passed.\n\r");

                RADIO_RELAY_SetLow();
                LIGHT_RELAY_SetLow();
                SIREN_RELAY_SetLow();
                print("Probe left screw terminals of P3/P5/P7 - Press <space> if all <1V\n\r");
                if(EUSART1_Read() != ' ')
                {
                    Test_Failed();
                }
                print("Passed.\n\r");

                LOWCURR_RELAY_SetHigh();
                ACC4_SetHigh();
                ACC5_SetHigh();
                ACC6_SetHigh();
                ACC7_SetHigh();
                ACC8_SetHigh();
                ACC9_SetHigh();
                ACC10_SetHigh();
                print("Apply green load to P1_2 thru P1_8.  Each should be 150-200. Press <space> if good.\n\r");
                while(!EUSART1_is_rx_ready())
                {
                    print("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
                    sprintf(pr,"2:%3d 3:%3d 4:%3d 5:%3d 6:%3d 7:%3d 8:%3d", current[0], current[1], current[2], current[3], current[4], current[5], current[6]);
                    print(pr);
                    __delay_ms(250);
                }
                print("Passed.\n\r");
                print("Test Complete");
            }
        }
    }
    
    print("\n\nWaiting for ign ...");
    while (ADCC_GetSingleConversion(IGN) < 250) {}
    
    ADCINT_Init();
    
    undervolt_timer = 0;
    timer_read = 0;
    
    print("\n\n\n\n");
    print(PROMPT);
    T0_ENABLE = 1;
    T1_ENABLE = 0;
    PIE0bits.TMR0IE = 0;
    
    
    while (1)
    {
        ProcessSerial();
        
        if (current[3] > 0x8000)
        {
            ACC7_SetLow();
            current[3] &= 0x03FF;
            tripped |= ACC7_t;
        }
        if (current[4] > 0x8000)
        {
            ACC8_SetLow();
            current[4] &= 0x03FF;
            tripped |= ACC8_t;
        }
        if (current[5] > 0x8000)
        {
            ACC9_SetLow();
            current[5] &= 0x03FF;
            tripped |= ACC9_t;
        }
        if (current[6] > 0x8000)
        {
            ACC10_SetLow();
            current[6] &= 0x03FF;
            tripped |= ACC10_t;
        }        
        
        if (GetIgnition() < 70)
        {
            ignf = 0;
            
            uint16_t switchpos;
            switchpos = GetSwitches();
            if (~switchpos & 0x080) ACC8_SetLow();
            if (~switchpos & 0x008) ACC4_SetLow();
            if (~switchpos & 0x010) ACC5_SetLow();
            if (~switchpos & 0x020) ACC6_SetLow();
            if (~switchpos & 0x040) ACC7_SetLow();
            if (~switchpos & 0x100) ACC9_SetLow();
            if (~switchpos & 0x200) ACC10_SetLow();
            if (~switchpos & 0x001) RADIO_RELAY_SetLow();
            if (~switchpos & 0x002) LIGHT_RELAY_SetLow();
            if (~switchpos & 0x004) SIREN_RELAY_SetLow();
            
            // If under threshold
            if (GetVoltage() + 2 < GetVoltThresh())
                undervolt_timer++;
            if (GetVoltage() < GetVoltThresh())
            {
                LED_Toggle();
                undervolt_timer++;
                print("\nundervolt timing");
                if (undervolt_timer > 240)
                    timer_read = 63000;  // power down now
            }
            else
                undervolt_timer = 0;  // Voltage is above threshold
            
            
            // TMR0 overflow at 1Hz
            if (PIR0bits.TMR0IF)
            {
                PIR0bits.TMR0IF = 0;
                LED_Toggle();
                timer_read++;
                re_en_timer++;
                time_out = GetTimeout();
                sprintf(pr,"\n%d out of %d", timer_read, time_out);
                print(pr);
                if (timer_read > time_out)
                {
                    timer_read = 0;
                    print("\nsleeping");
                    PowerOff();
                    print("\nwoke up");
                }
            }
        }
        else
        {
            if (re_en_timer > 30)
            {
                re_en_timer = 0;
                ACC4_SetHigh();
                ACC5_SetHigh();
                ACC6_SetHigh();
                ACC7_SetHigh();
                ACC8_SetHigh();
                ACC9_SetHigh();
                ACC10_SetHigh();
                tripped = 0;
            }

            if(TMR4_HasOverflowOccured())
                LEDRoutine();

            if (!ignf)
            {
                ACC4_SetHigh();
                ACC5_SetHigh();
                ACC6_SetHigh();
                ACC7_SetHigh();
                ACC8_SetHigh();
                ACC9_SetHigh();
                ACC10_SetHigh();
                ignf = 1;
            }
            
            LIGHT_RELAY_SetHigh();
            RADIO_RELAY_SetHigh();
            SIREN_RELAY_SetHigh();
            LOWCURR_RELAY_SetHigh();
            
            undervolt_timer = 0;
            timer_read = 0;
            if (PIR0bits.TMR0IF)
            {
                PIR0bits.TMR0IF = 0;
                re_en_timer++;
            }
        }
    }
}
/**
 End of File
*/