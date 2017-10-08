#include <msp430.h>
/**
 * main.c
 * Blink LED1
 * MSP430F5529
 * Author: Shani Thapa
 * Last Updated: 10/7
 * Simple Blink
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
   // PM5CTL0 &= ~LOCKLPM5;                 // Disable High-Z mode, but the board doesn't run with this on

    P1DIR |= 0x01;                          // Set P1.0, LED1, to output direction

    for(;;) {
        volatile unsigned int i;            // volatile to prevent optimization

        P1OUT ^= 0x01;                      // Toggle P1.0, LED1, with XOR

        i = 10000;                          // Delay toggling LED by running through do-while statement
        do i--;
        while(i != 0);
    }
}
