#include "Scheduler.h"
#include "avrContext/avrcontext_arduino.h"

uint8_t currentTask;
int prio=0;

//Scheduler
uint8_t scheduler() {
    changeFlag = false;
    prio=0;

    reSchedule:
    currentTask = (currentTask + 1) % taskCount; 
    if((taskList[currentTask].nextRuntime > millis())){
      goto reSchedule;
    }

  if(currentTask==(taskCount-1)){prio++;}

  if(taskList[currentTask].priority>prio){
   goto reSchedule; 
  }
  if(!taskList[currentTask].isActive){
    goto reSchedule;
  }


return currentTask;

}

