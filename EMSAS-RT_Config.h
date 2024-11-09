#ifndef PRIVRTOS_CONFIG_H
#define PRIVRTOS_CONFIG_H

//________________________________CONSTANTS________________________________//
#define MAX_TASKS 10
#define TASK_COUNT 2
#define MAX_SEMAPHORE 5
#define MAX_COUNT_SEMAPHORE 5
#define MAX_MUTEX 5
#define MAX_MAILBOXES 5
#define MAX_MAILBOX_SIZE 10
#define MESSAGE_SIZE 32
#define MAX_EVENT_GROUPS 5
#define MAX_FLAGS_PER_GROUP 8
#define TASK_COUNT 2




//________________________________FUNCTION FILES________________________________//
#include <Arduino.h>
#include "TaskManager.h"
#include "Scheduler.h"
#include "Semaphore.h"
#include "Mutex.h"
#include "Mailbox.h"
#include "EventFlag.h"
#include "avrcontext_arduino.h"
#include "interruptManager.h"

#endif