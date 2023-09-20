/* 
 * File:   BT_Audio.h
 * Author: maste
 *
 * Created on January 13, 2023, 1:20 PM
 */








#ifndef BT_AUDIO_H
#define	BT_AUDIO_H

#include "mcc_generated_files/mcc.h"
#include "Serial.h"
#include "ButtonDefinitions.h"
#include "stdio.h"
#include "string.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define BOARD_PRESSED !VOL_BUT_GetValue()
#define PRESS_THRESH 400
#define NO_PRESS    0
#define PRESS       1
#define SHORT_PRESS 2
#define WAIT        3
#define LONG_PRESS  4
#define SECONDS 3875
    
#define MAX_VOL 5
uint8_t vol;
uint8_t min_vol;
uint8_t beep;
uint8_t Get_L();
uint8_t Get_R();
uint8_t GetVoltage();
void SetVolume(uint8_t volume, uint8_t channel);

#ifdef	__cplusplus
}
#endif

#endif	/* BT_AUDIO_H */

