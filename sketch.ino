// Sketch.ino
#include "EMSAS-RT_Config.h"

// Tasks
void task1() {
  //while(true){
   Serial.println("Task1: ");
    //Serial.println(micros());
    delay(5000);
//}
}

void task2() {
   //while(true){
   Serial.println("Task2: ");
    //Serial.println(micros());
    delay(1000);
//}
}

void setup() {
    Serial.begin(9600);
    
    // Adding tasks with different priorities and intervals
    addTask(task1, 128);
    addTask(task2, 128);
    startTimer();

}

void loop() {
    scheduler();
}
