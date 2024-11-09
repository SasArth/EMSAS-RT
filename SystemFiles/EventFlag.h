#ifndef COMM_EVENTFLAG_H
#define COMM_EVENTFLAG_H

#include "Mailbox.h"

//Event Flag
typedef struct {
    uint8_t flags; // Bitmask to represent the state of each flag
} EventGroup;

extern EventGroup eventGroupList[MAX_EVENT_GROUPS];
extern uint8_t eventGroupCount;

void initEventGroup();
void setEventFlag(uint8_t groupIndex, uint8_t flag);
void clearEventFlag(uint8_t groupIndex, uint8_t flag);
bool isEventFlagSet(uint8_t groupIndex, uint8_t flag);

#endif