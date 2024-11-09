#include "Scheduler.h"
#include "avrcontext_arduino.h"

uint8_t currentTask;

//Scheduler
uint8_t scheduler(){
 
 reSchedule:

 currentTask = (currentTask + 1) % TASK_COUNT;  // Switch to the next task (round-robin)
    if(taskList[currentTask].isActive){
      // Set the current task context
    }
    else{
      goto reSchedule;
    }
  return currentTask;
}

