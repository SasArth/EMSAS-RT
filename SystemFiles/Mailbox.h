#ifndef COMM_MAILBOX_H
#define COMM_MAILBOX_H

#include "Mutex.h"

//Mailbox
typedef struct {
    char **messages; // Pointer to dynamically allocated array of messages
    uint8_t head;
    uint8_t tail;
    uint8_t count;
    uint8_t maxSize;
} Mailbox;

extern Mailbox *mailboxList[MAX_MAILBOXES];
extern uint8_t mailboxCount;

void initMailbox(uint8_t size);
bool sendMessage(uint8_t mailboxIndex, const char *message);
bool receiveMessage(uint8_t mailboxIndex, char *buffer);
void freeMailbox(uint8_t index);

#endif