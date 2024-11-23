#ifndef RM_MUTEX_H
#define RM_MUTEX_H

#include "../EMSAS-RT_Config.h"

//Mutex
typedef struct{
  bool isLocked;
  uint8_t ownerIndex;
}Mutex;

extern Mutex mutexList[MAX_MUTEX];
extern uint8_t mutexCount;

void initMutex();
bool acquireMutex(uint8_t index);
void releaseMutex(uint8_t index);

#endif
