#include "Mailbox.h"


//______________________________VARIABLES______________________________//
Mailbox *mailboxList[MAX_MAILBOXES];
uint8_t mailboxCount;

//________________________________INIT________________________________//
//ADD MAILBOX
void initMailbox(uint8_t size) {
    if (mailboxCount < MAX_MAILBOXES && size > 0) {
        mailboxList[mailboxCount] = (Mailbox *)malloc(sizeof(Mailbox));
        mailboxList[mailboxCount]->messages = (char **)malloc(size * sizeof(char *));
        for (uint8_t i = 0; i < size; i++) {
            mailboxList[mailboxCount]->messages[i] = (char *)malloc(MESSAGE_SIZE * sizeof(char));
        }
        mailboxList[mailboxCount]->head = 0;
        mailboxList[mailboxCount]->tail = 0;
        mailboxList[mailboxCount]->count = 0;
        mailboxList[mailboxCount]->maxSize = size;
        mailboxCount++;
        return; 
    }
}



//________________________________FUNCTIONS________________________________//
//Send Message
bool sendMessage(uint8_t mailboxIndex, const char *message) {
    if (mailboxIndex < mailboxCount && mailboxList[mailboxIndex]->count < mailboxList[mailboxIndex]->maxSize) {
        strncpy(mailboxList[mailboxIndex]->messages[mailboxList[mailboxIndex]->head], message, MESSAGE_SIZE);
        mailboxList[mailboxIndex]->head = (mailboxList[mailboxIndex]->head + 1) % mailboxList[mailboxIndex]->maxSize;
        mailboxList[mailboxIndex]->count++;
        return true;
    }
    return false; // Mailbox full or invalid index
}

//Receive Message
bool receiveMessage(uint8_t mailboxIndex, char *buffer) {
    if (mailboxIndex < mailboxCount && mailboxList[mailboxIndex]->count > 0) {
        strncpy(buffer, mailboxList[mailboxIndex]->messages[mailboxList[mailboxIndex]->tail], MESSAGE_SIZE);
        mailboxList[mailboxIndex]->tail = (mailboxList[mailboxIndex]->tail + 1) % mailboxList[mailboxIndex]->maxSize;
        mailboxList[mailboxIndex]->count--;
        return true;
    }
    return false; // Mailbox empty or invalid index
}

//Clear Mailbox
void freeMailbox(uint8_t index) {
    if (index < mailboxCount) {
        for (uint8_t i = 0; i < mailboxList[index]->maxSize; i++) {
            free(mailboxList[index]->messages[i]);
        }
        free(mailboxList[index]->messages);
        free(mailboxList[index]);
        mailboxList[index] = nullptr;
    }
}
