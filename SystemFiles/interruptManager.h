#ifndef INTERRUPT_MANAGER_H
#define INTERRUPT_MANAGER_H

#include <Arduino.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include "../EMSAS-RT_Config.h"
#include "avrcontext_arduino.h"


void startTimer(void);
ISR(WDT_vect, ISR_NAKED);




#endif