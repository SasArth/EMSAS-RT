#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>
#include "../EMSAS-RT_Config.h"

void eRTDelay(uint32_t delayTime);
void idleTask();
void eRTSetup();
extern bool changeFlag;


#endif
