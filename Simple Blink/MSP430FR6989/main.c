#include <msp430.h>
/**
 * main.c
 * Blink LED1
 * MSP430FR6989
 * Author: Shani Thapa
 * Last Updated: 10/7
 * Simple Blink
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode

    P1DIR |= BIT0;                          // Set P1.0, LED1, to output direction
    for(;;) {
        volatile unsigned int i;            // volatile to prevent optimization

        P1OUT ^= BIT0;                      // Toggle P1.0, LED1, using XOR

        i = 10000;                          // Delay toggling LED by running through do-while statement
        do i--;
        while(i != 0);
    }
}
