/**
 * Allow GRBL to control a BLTouch
 * 
 * Uses A4 as an output to communicate with a PIC using a basic one-wire protocol
 * 
 * The PIC generates the appropriate PWM to control the BLTouch
 */
#ifndef BLTOUCH_H
#define BLTOUCH_H

#include "grbl.h"

#define BLT_DEPLOY 1
#define BLT_M119 2
#define BLT_STOW 3
#define BLT_SELF_TEST 4
#define BLT_EEPROM_CVR 5
#define BLT_EEPROM_5V_ZMIN 6
#define BLT_EEPROM_OD_ZMIN 7
#define BLT_ALARM_OFF_UP  8

// Custom message to the PIC to start PWM
#define BLT_CONTROLLER_STARTUP 9
#define BLT_CONTROLLER_SHUTDOWN 10


void bltouch_init();
void bltouch_deploy();
void bltouch_stow();
void bltouch_self_test();
void bltouch_alarm_off_up();

void bltouch_send(uint8_t data); 



#endif 
/* bltouch_h */