# EMSAS-RT: Easy-Multi-tasking SAS's Real-Time Operating System

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
- [Non-Blocking Delay](#non-blocking-delay)
- [Tasks](#tasks)
- [Semaphore](#semaphore)
  - [Binary Semaphore](#binary-semaphore)
  - [Counting Semaphore](#counting-semaphore)
- [Mutex](#mutex)
- [Mailbox](#mailbox)
- [Event Groups](#event-groups)

## Introduction

**EMSAS-RT** (Embedded Multi-Scheduling and Synchronization Real-Time Operating System) is a lightweight RTOS designed for Arduino platforms with AVR architecture. It provides task management, semaphores, mutexes, mailboxes, and event groups for easy multitasking and inter-task communication. It uses preemptive scheduling based on task priority and RoundRobin if the priority is same.

---

## Getting Started

### Installation

1. Download or clone the EMSAS-RT repository.
2. Use EMSAS-RT repo folder as your `Arduino` Project
3. Make changes in `Sketch.ino` and `EMSAS_RT` File.

### Initialization

In the `setup()` function, initialize the system components and add tasks:

```cpp
void setup() {
    Serial.begin(9600);

    // Initialize system components
    initEventGroup();
    initMailbox(3);

    // Add tasks to the system
    addTask(task1, 0, 128);
    addTask(task2, 1, 128);

    //RTOS Setup and Starting Timer
    eRTSetup();
}

void loop() {
    // The RTOS runs tasks; no need for code in loop().
}
```

---
## Non-Blocking Delay
To delay a task for a specified amount of time without blocking other tasks, a non-blocking delay can be used. This ensures that the task is not scheduled during the delay, allowing lower-priority tasks to execute in the meantime. This can be achieved using `eRTDelay(delayDuration-ms)`.

```cpp
void eRTDelay(uint32_t delayDuration)

//Example
eRTDelay(5000);
```

---
## Tasks

### Adding a Task

Tasks are added using the `addTask()` function, which registers the task and it's priority and sets up its stack. You can create multiple tasks for multitasking. Keep all Tasks as Infinite Loops.

```cpp
bool addTask(void (*taskFunc)(), uint16_t stackSize);
```

#### Example

```cpp
void task1() {
    while(true) {
        Serial.println("Task 1 running");
        eRTDelay(1000);
    }
}

void task2() {
    while(true) {
        Serial.println("Task 2 running");
        eRTDelay(1000);
    }
}

void setup() {
    addTask(task1, 0, 128);
    addTask(task2, 1, 128);
    eRTSetup();
}
```

### Deactivating & Reactivating Tasks
Task can be activated and reactivated using the `activateTask(taskName)` & `activateTask(taskName)`. 

```cpp
void deactivateTask(void (*taskFunc)());
void activateTask(void (*taskFunc)());

//Example
deactivateTask(task2);
activateTask(task1);
```

---

## Semaphore

### Binary Semaphore

A binary semaphore can be used to control access to a shared resource between tasks. Only one task can hold the semaphore at any given time.

#### Functions

- **Initialize:** `initBinarySemaphore()`
- **Acquire:** `acquireBinarySemaphore(index)`
- **Release:** `releaseBinarySemaphore(index)`

#### Example

```cpp
void task1() {
    if (acquireBinarySemaphore(0)) {
        Serial.println("Task 1 acquired semaphore");
        releaseBinarySemaphore(0);
    }
}

void setup() {
    initBinarySemaphore();
    addTask(task1, 128);
    start_system_timer();
}
```

### Counting Semaphore

Counting semaphores allow multiple tasks to access a resource up to a specified limit.

#### Functions

- **Initialize:** `initCountingSemaphore(maxCount)`
- **Acquire:** `acquireCountingSemaphore(index)`
- **Release:** `releaseCountingSemaphore(index)`

#### Example

```cpp
void task1() {
    if (acquireCountingSemaphore(0)) {
        Serial.println("Task 1 using shared resource");
        releaseCountingSemaphore(0);
    }
}

void setup() {
    initCountingSemaphore(3);  // Allow up to 3 tasks to use the resource
    addTask(task1, 128);
    start_system_timer();
}
```

---

## Mutex

A mutex ensures that only one task can access a critical section of code at any given time.

#### Functions

- **Initialize:** `initMutex()`
- **Acquire:** `acquireMutex(index)`
- **Release:** `releaseMutex(index)`

#### Example

```cpp
void task1() {
    if (acquireMutex(0)) {
        Serial.println("Task 1 locked mutex");
        releaseMutex(0);
    }
}

void setup() {
    initMutex();
    addTask(task1, 128);
    start_system_timer();
}
```

---

## Mailbox

Mailboxes allow message passing between tasks. Tasks can send and receive messages through a mailbox.

#### Functions

- **Initialize:** `initMailbox(size)`
- **Send Message:** `sendMessage(mailboxIndex, message)`
- **Receive Message:** `receiveMessage(mailboxIndex, buffer)`
- **Free Mailbox:** `freeMailbox(index)`

#### Example

```cpp
void task1() {
    sendMessage(0, "Hello from Task 1");
}

void task2() {
    char buffer[MESSAGE_SIZE];
    if (receiveMessage(0, buffer)) {
        Serial.println(buffer);
    }
}

void setup() {
    initMailbox(3);
    addTask(task1, 128);
    addTask(task2, 128);
    start_system_timer();
}
```

---

## Event Groups

Event groups allow synchronization between tasks using flags. Tasks can set, clear, and check event flags.

#### Functions

- **Initialize:** `initEventGroup()`
- **Set Event Flag:** `setEventFlag(groupIndex, flag)`
- **Clear Event Flag:** `clearEventFlag(groupIndex, flag)`
- **Check Event Flag:** `isEventFlagSet(groupIndex, flag)`

#### Example

```cpp
void task1() {
    setEventFlag(0, 0);  // Set flag 0 in group 0
}

void task2() {
    if (isEventFlagSet(0, 0)) {
        Serial.println("Event flag set");
    }
}

void setup() {
    initEventGroup();
    addTask(task1, 128);
    addTask(task2, 128);
    start_system_timer();
}
```

---

## Task Scheduler

The EMSAS-RT uses a priority-based preemptive scheduling system. The `scheduler()` function switches between tasks based on their priority and runtime, iterating through the task list.

---

## Conclusion

EMSAS-RT provides essential real-time operating system features for multitasking, synchronization, and inter-task communication. This guide covers how to use tasks, semaphores, mutexes, mailboxes, and event groups in your Arduino projects.

---
