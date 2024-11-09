#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <Arduino.h>
#include "../EMSAS-RT_Config.h"
#include "avrcontext_arduino.h"

typedef struct{
void (*taskFunction)(); //Task ptr
bool isActive;
uint8_t *stack;
avr_context_t context;   
}TCB;

extern TCB taskList[MAX_TASKS];
extern uint8_t taskCount;

bool addTask(void (*taskFunc)(), uint16_t stackSize );
void deactivateTask(int taskIndex);
void activateTask(int taskIndex);

#endif