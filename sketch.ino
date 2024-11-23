// Sketch.ino
#include "EMSAS-RT_Config.h"

// Tasks
void task1() {
    while (true) {
        Serial.print("Task1: ");
        Serial.println(millis());
        eRTDelay(5000);
    }
}

void task2() {
    while (true) {
        Serial.print("Task2: ");
        Serial.println(micros() / 1000);
        eRTDelay(100);
    }
}

void task3() {
    while (true) {
        Serial.print("Task3: ");
        Serial.println(micros() / 1000);
        eRTDelay(100);
    }
}

void task4() {
    while (true) {
        Serial.print("Task4: ");
        Serial.println(micros() / 1000);
        eRTDelay(100);
    }
}

void setup() {
    Serial.begin(9600);
    // Adding tasks with different priorities and intervals
    addTask(task1, 1, 128); // Task 1
    addTask(task2, 0, 128); // Task 2
    addTask(task3, 0, 128); // Task 3
    addTask(task4, 0, 128); // Task 4
    eRTSetup();

}

void loop() {
    scheduler();
}
