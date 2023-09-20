/* 
 * File:   Serial.h
 * Author: maste
 *
 * Created on January 13, 2023, 1:20 PM
 */

#ifndef SERIAL_H
#define	SERIAL_H

#ifdef	__cplusplus
extern "C" {
#endif

#define PROMPT "\nBTAud>>"

uint8_t pr[100];

void print(uint8_t *s);
void Serial();


#ifdef	__cplusplus
}
#endif

#endif	/* SERIAL_H */

