#ifndef RM_SEMAPHORE_H
#define RM_SEMAPHORE_H

#include "../EMSAS-RT_Config.h"

//Binary Semaphore
typedef struct{
bool isLocked;
uint8_t ownerIndex;
}BinarySemaphore;

extern BinarySemaphore binarySemaphoreList[MAX_SEMAPHORE];
extern uint8_t binarySemaphoreCount;

void initBinarySemaphore();
bool acquireBinarySemaphore(uint8_t index);
void releaseBinarySemaphore(uint8_t index);


//Counting Semaphore
typedef struct{
  uint8_t count;
  uint8_t maxCount;
}CountingSemaphore;

extern CountingSemaphore countingSemaphoreList[MAX_COUNT_SEMAPHORE];
extern uint8_t countingSemaphoreCount;

void initCountingSemaphore(uint8_t maxCount);
bool acquireCountingSemaphore(uint8_t index);
void releaseCountingSemaphore(uint8_t index);

#endif
