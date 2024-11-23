#ifndef PRIVRTOS_CONFIG_H
#define PRIVRTOS_CONFIG_H

//________________________________CONSTANTS________________________________//
#define MAX_TASKS 10
#define MAX_SEMAPHORE 5
#define MAX_COUNT_SEMAPHORE 5
#define MAX_MUTEX 5
#define MAX_MAILBOXES 5
#define MAX_MAILBOX_SIZE 10
#define MESSAGE_SIZE 32
#define MAX_EVENT_GROUPS 5
#define MAX_FLAGS_PER_GROUP 8
#define MAX_PRIORITY 5




//________________________________FUNCTION FILES________________________________//
#include <Arduino.h>
#include "SystemFiles/TaskManager.h"
#include "SystemFiles/Scheduler.h"
#include "SystemFiles/Semaphore.h"
#include "SystemFiles/Mutex.h"
#include "SystemFiles/Mailbox.h"
#include "SystemFiles/EventFlag.h"
#include "SystemFiles/avrcontext_arduino.h"
#include "SystemFiles/interruptManager.h"
#include "SystemFiles/utils.h"

#endif