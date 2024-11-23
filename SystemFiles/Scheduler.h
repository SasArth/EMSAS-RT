#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>
#include "../EMSAS-RT_Config.h"


extern uint8_t currentTask;
extern int prio;

uint8_t scheduler();

#endif
