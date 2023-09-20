/* 
 * File:   ButtonDefinitions.h
 * Author: maste
 *
 * Created on February 28, 2023, 11:49 AM
 */

#ifndef BUTTONDEFINITIONS_H
#define	BUTTONDEFINITIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

void Init_Buttons(void);
    
void (*LeftShortCb)(void);
void (*RightShortCb)(void);
void (*BoardShortCb)(void);
void (*LeftMedCb)(void);
void (*RightMedCb)(void);
void (*BoardMedCb)(void);
void (*LeftLongCb)(void);
void (*RightLongCb)(void);
void (*BoardLongCb)(void);
void (*LeftDoubleCb)(void);
void (*RightDoubleCb)(void);
void (*BoardDoubleCb)(void);

void NullCb(void);
void VolumeUp(void);
void Mute(void);
void SwitchPath(void);
void Skip(void);
void MinVolUp(void);
void MinVolReset(void);


void SetLeftShort(void (* Cb)(void));
void SetRightShort(void (* Cb)(void));
void SetBoardShort(void (* Cb)(void));
void SetLeftMed(void (* Cb)(void));
void SetRightMed(void (* Cb)(void));
void SetBoardMed(void (* Cb)(void));
void SetLeftLong(void (* Cb)(void));
void SetRightLong(void (* Cb)(void));
void SetBoardLong(void (* Cb)(void));
void SetLeftDouble(void (* Cb)(void));
void SetRightDouble(void (* Cb)(void));
void SetBoardDouble(void (* Cb)(void));


#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONDEFINITIONS_H */

