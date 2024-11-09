#include "EventFlag.h"

//______________________________VARIABLES______________________________//
EventGroup eventGroupList[MAX_EVENT_GROUPS];
uint8_t eventGroupCount = 0;


//________________________________INIT________________________________//
//EVENT FLAG
void initEventGroup() {
    if (eventGroupCount < MAX_EVENT_GROUPS) {
        eventGroupList[eventGroupCount].flags = 0; // All flags are cleared
        eventGroupCount++;
        return;
    }
}



//________________________________FUNCTIONS________________________________//

//Set Event Flag
void setEventFlag(uint8_t groupIndex, uint8_t flag) {
    if (groupIndex < eventGroupCount && flag < MAX_FLAGS_PER_GROUP) {
        eventGroupList[groupIndex].flags |= (1 << flag); // Set the specified flag
    }
}

//Clear Event Flag
void clearEventFlag(uint8_t groupIndex, uint8_t flag) {
    if (groupIndex < eventGroupCount && flag < MAX_FLAGS_PER_GROUP) {
        eventGroupList[groupIndex].flags &= ~(1 << flag); // Clear the specified flag
    }
}

//Check Event Flag
bool isEventFlagSet(uint8_t groupIndex, uint8_t flag) {
    if (groupIndex < eventGroupCount && flag < MAX_FLAGS_PER_GROUP) {
        return (eventGroupList[groupIndex].flags & (1 << flag)) != 0; // Check if the flag is set
    }
    return false; // Invalid group or flag
}