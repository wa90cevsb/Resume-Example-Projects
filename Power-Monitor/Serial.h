/* 
 * File:   Serial.h
 * Author: maste
 *
 * Created on November 29, 2022, 1:26 PM
 */

#ifndef SERIAL_H
#define	SERIAL_H
#include "mcc_generated_files/mcc.h"
#ifdef	__cplusplus
extern "C" {
#endif

#define PROMPT "\nHD_Power>>"
#define COM_LENGTH 15
void print(char *s);
void ProcessSerial();

#ifdef	__cplusplus
}
#endif

#endif	/* SERIAL_H */

