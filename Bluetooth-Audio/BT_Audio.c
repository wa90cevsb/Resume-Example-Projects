#include "BT_Audio.h"


uint8_t vol;
uint8_t min_vol;
uint8_t beep;

// Read left button, return high if pressed
uint8_t Get_L()
{
    uint32_t accumulator = 0;
    uint8_t i;
    for (i=0;i<3;i++)
        accumulator += ADC_GetConversion(L_BUT);
    accumulator /= 3;
    return accumulator > PRESS_THRESH;
}

// Read right button, return high if pressed
uint8_t Get_R()
{
    uint32_t accumulator = 0;
    uint8_t i;
    for (i=0;i<3;i++)
        accumulator += ADC_GetConversion(R_BUT);
    accumulator /= 3;
    return accumulator > PRESS_THRESH;
}

uint8_t GetVoltage()
{
    uint32_t convert_result;
    convert_result = (uint32_t)ADC_GetConversion(VOLT);
    convert_result *= 322;
    convert_result *= 57;
    convert_result /= 10;
    uint8_t result = convert_result / 10000;
    return result;
}


void SetVolume(uint8_t volume, uint8_t channel)
{
    uint8_t i;
    
    
    VOL_CLK_SetLow();
    VOL_L_S_SetLow();
    for(i=0;i<8;i++)
    {
        if((channel & 0x80) == 0x80)
            VOL_DATA_SetHigh();
        else
            VOL_DATA_SetLow();
        VOL_CLK_SetHigh();
        channel = channel << 1;
        VOL_CLK_SetLow();
    }
    for(i=0;i<8;i++)
    {
        if((volume & 0x80) == 0x80)
            VOL_DATA_SetHigh();
        else
            VOL_DATA_SetLow();
        VOL_CLK_SetHigh();
        volume = volume << 1;
        VOL_CLK_SetLow();
    }
    VOL_L_S_SetHigh();
}