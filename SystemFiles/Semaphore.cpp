#include "Semaphore.h"

//______________________________VARIABLES______________________________//
BinarySemaphore binarySemaphoreList[MAX_SEMAPHORE];
uint8_t binarySemaphoreCount = 0;

CountingSemaphore countingSemaphoreList[MAX_COUNT_SEMAPHORE];
uint8_t countingSemaphoreCount = 0;

//________________________________INIT________________________________//

//ADD BINARY SEMAPHORE
void initBinarySemaphore() {
  if(binarySemaphoreCount<MAX_SEMAPHORE){
    binarySemaphoreList[binarySemaphoreCount].isLocked = false;
    binarySemaphoreList[binarySemaphoreCount].ownerIndex = 255;
    binarySemaphoreCount++;
  }
    }

//ADD COUNTING SEMAPHORE
void initCountingSemaphore(uint8_t maxCount) {
    if (countingSemaphoreCount < MAX_COUNT_SEMAPHORE) {
        countingSemaphoreList[countingSemaphoreCount].count = maxCount;
        countingSemaphoreList[countingSemaphoreCount].maxCount = maxCount;
        countingSemaphoreCount++;
    }
}


//________________________________FUNCTIONS________________________________//

//Take Binary Semaphore
bool acquireBinarySemaphore(uint8_t index) {
      if(!binarySemaphoreList[index].isLocked || binarySemaphoreList[index].ownerIndex == currentTask){
      binarySemaphoreList[index].isLocked = true;
      binarySemaphoreList[index].ownerIndex = currentTask;
      return true;
      }
      return false;
}

//Relese Binary Semaphore
void releaseBinarySemaphore(uint8_t index){
  binarySemaphoreList[index].isLocked = false;
  binarySemaphoreList[index].ownerIndex = 255;
}


//Acquire Counting Semaphore
bool acquireCountingSemaphore(uint8_t index){
  if (countingSemaphoreList[index].count > 0) {
        countingSemaphoreList[index].count--;
        return true;
}
return false;
}

//Release Counting Semaphore
void releaseCountingSemaphore(uint8_t index) {
    if (countingSemaphoreList[index].count < countingSemaphoreList[index].maxCount) {
        countingSemaphoreList[index].count++;
        }
}
