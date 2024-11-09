#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>
#include "TaskManager.h"


extern uint8_t currentTask;
uint8_t scheduler();

#endif
