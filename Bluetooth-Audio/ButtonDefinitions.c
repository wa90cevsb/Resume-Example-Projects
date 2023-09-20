#include "BT_Audio.h"


void Init_Buttons(void)
{
    SetLeftShort(VolumeUp);
    SetLeftMed(Mute);
    SetLeftLong(SwitchPath);
    SetLeftDouble(Skip);
    
    SetRightShort(NullCb);
    SetRightMed(NullCb);
    SetRightLong(NullCb);
    SetRightDouble(NullCb);
    
    SetBoardShort(MinVolUp);
    SetBoardMed(MinVolReset);
    SetBoardLong(MinVolReset);
    SetBoardDouble(NullCb);
}



void NullCb(void) { return; }

void VolumeUp(void)
{
    SWITCH_EN_SetLow();
    if (vol > MAX_VOL)
    {
        vol -= 5;
        SetVolume(vol, 0);
        SetVolume(vol, 1);
    }
    else
        beep = 1;
}

void Mute(void)
{
    SWITCH_EN_Toggle();
    vol = min_vol;
    SetVolume(min_vol, 0);
    SetVolume(min_vol, 1);
}

void SwitchPath(void)
{
    SWITCH_STATE_Toggle();
}

void Skip(void)
{
    BT_NEXT_SetHigh();
    __delay_ms(70);
    BT_NEXT_SetLow();
}

void MinVolUp(void)
{
    if (min_vol > 30)
    {
        min_vol -= 5;
        vol = min_vol;
        SetVolume(vol, 0);
        SetVolume(vol, 1);
        uint16_t buffer[ERASE_FLASH_BLOCKSIZE];
        FLASH_WriteWord(0x1FFD,buffer,min_vol);
    }
}

void MinVolReset(void)
{
    min_vol = 100;
    vol = 100;
    SetVolume(100, 0);
    SetVolume(100, 1);
    uint16_t buffer[ERASE_FLASH_BLOCKSIZE];
    FLASH_WriteWord(0x1FFD,buffer,min_vol);
}



void SetLeftShort(void (* Cb)(void))
{
    LeftShortCb = Cb;
}

void SetRightShort(void (* Cb)(void))
{
    RightShortCb = Cb;
}

void SetBoardShort(void (* Cb)(void))
{
    BoardShortCb = Cb;
}

void SetLeftMed(void (* Cb)(void))
{
    LeftMedCb = Cb;
}

void SetRightMed(void (* Cb)(void))
{
    RightMedCb = Cb;
}

void SetBoardMed(void (* Cb)(void))
{
    BoardMedCb = Cb;
}

void SetLeftLong(void (* Cb)(void))
{
    LeftLongCb = Cb;
}

void SetRightLong(void (* Cb)(void))
{
    RightLongCb = Cb;
}

void SetBoardLong(void (* Cb)(void))
{
    BoardLongCb = Cb;
}

void SetLeftDouble(void (* Cb)(void))
{
    LeftDoubleCb = Cb;
}

void SetRightDouble(void (* Cb)(void))
{
    RightDoubleCb = Cb;
}

void SetBoardDouble(void (* Cb)(void))
{
    BoardDoubleCb = Cb;
}