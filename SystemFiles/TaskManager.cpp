#include "TaskManager.h"

//______________________________VARIABLES______________________________//
TCB taskList[MAX_TASKS+1];
uint8_t taskCount = 0;


void sortTasks();


//________________________________INIT________________________________//
//ADD TASK Function
bool addTask(void (*taskFunc)(), uint8_t priority, uint16_t stackSize ){

  if( taskCount< MAX_TASKS+1){
    taskList[taskCount].taskFunction = taskFunc;
    taskList[taskCount].isActive = true;
        taskList[taskCount].priority = priority;
        taskList[taskCount].nextRuntime = 0;
    uint8_t* stack = new uint8_t[stackSize];
    taskList[taskCount].stack = stack;
      // Get the context for this task
      avr_getcontext(&taskList[taskCount].context);
      avr_makecontext(&taskList[taskCount].context, stack, stackSize, NULL, taskFunc, NULL);

    taskCount++;
    sortTasks();
    return true;
  }
  return false;
}

void sortTasks() {
    // Simple insertion sort
    for (int i = 1; i < taskCount; i++) {
        TCB key = taskList[i];
        int j = i - 1;

        // Shift tasks that have a higher priority (lower value)
        while (j >= 0 && taskList[j].priority > key.priority) {
            taskList[j + 1] = taskList[j]; // Shift
            j--;
        }
        taskList[j + 1] = key; // Insert the key in the correct position
        
    }
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
