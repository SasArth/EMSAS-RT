#include "utils.h"


bool changeFlag = false;


void eRTDelay(uint32_t delayTime){
  changeFlag = true;
  taskList[currentTask].nextRuntime = millis() + delayTime;
  while(changeFlag){
    delay(5);
  }
}

void idleTask() {
  while(true);
}


void eRTSetup(){
  addTask(idleTask, MAX_PRIORITY+1, 64);
  startTimer(); // Start timer
}