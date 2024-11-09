#include "TaskManager.h"

//______________________________VARIABLES______________________________//
TCB taskList[MAX_TASKS];
uint8_t taskCount = 0;



//________________________________INIT________________________________//
//ADD TASK Function
bool addTask(void (*taskFunc)(), uint16_t stackSize ){
  if( taskCount< MAX_TASKS){
    taskList[taskCount].taskFunction = taskFunc;
    taskList[taskCount].isActive = true;
    uint8_t* stack = new uint8_t[stackSize];
    taskList[taskCount].stack = stack;
      // Get the context for this task
      avr_getcontext(&taskList[taskCount].context);
      avr_makecontext(&taskList[taskCount].context, stack, sizeof(stack), NULL, taskFunc, NULL);

    taskCount++;
    return true;
  }
  return false;
}


//________________________________FUNCTIONS________________________________//
//Deactivation
void deactivateTask(int taskIndex){
  taskList[taskIndex].isActive = false;
}
//Activation
void activateTask(int taskIndex){
  taskList[taskIndex].isActive = true;
}
