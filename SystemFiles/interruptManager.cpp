#include "interruptManager.h"
#include "avrcontext_arduino.h"


extern "C" {
    avr_context_t *volatile current_task_ctx;  // Current task context pointer
}


void startTimer(void) {
    cli();  // Disable interrupts
    MCUSR &= ~(1 << WDRF);  // Clear the watchdog reset flag
    wdt_reset();            // Reset the watchdog timer

    // Configure the watchdog timer to interrupt every 1 second
    WDTCSR |= (1 << WDCE) | (1 << WDE);  // Enable WD timer configuration
    WDTCSR = 0;  // Reset the WD timer configuration
    wdt_enable(WDTO_15MS);  // Set the watchdog timer period to 1 second
    WDTCSR |= (1 << WDIE);  // Enable watchdog timer interrupt mode
    sei();  // Enable global interrupts
}



ISR(WDT_vect, ISR_NAKED) {
    // Save the context of the current task
    AVR_SAVE_CONTEXT_GLOBAL_POINTER(
        "cli\n",  // Disable interrupts while switching tasks
        current_task_ctx);

    current_task_ctx = &taskList[scheduler()].context;

    // Re-enable the watchdog timer interrupt to avoid a reset
    WDTCSR |= (1 << WDIE);

    // Restore the context of the next task
    AVR_RESTORE_CONTEXT_GLOBAL_POINTER(current_task_ctx);

    // Return from interrupt and activate the task context
    asm volatile("reti\n");
}