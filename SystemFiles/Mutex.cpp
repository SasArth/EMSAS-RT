#include "Mutex.h"

//______________________________VARIABLES______________________________//
Mutex mutexList[MAX_MUTEX];
uint8_t mutexCount = 0;


//________________________________INIT________________________________//
//ADD MUTEX
void initMutex() {
    if (mutexCount < MAX_SEMAPHORE) {
        mutexList[mutexCount].isLocked = false;
        mutexList[mutexCount].ownerIndex = 255;
        mutexCount++;
    }
}



//________________________________FUNCTIONS________________________________//
//Acquire Mutex
bool acquireMutex(uint8_t index){
  if(!mutexList[index].isLocked){
    mutexList[index].isLocked = true;
    mutexList[index].ownerIndex = currentTask;
    return true;
  }
  else{
  return false;
}
}

//Release Mutex
void releaseMutex(uint8_t index){
if (mutexList[index].ownerIndex == currentTask){
  mutexList[index].isLocked = false;
  mutexList[index].ownerIndex = 255;
}
}