
#include <msp430.h>
/**
 * main.c
 * Blink LED1
 * MSP430FR2311
 * Author: Shani Thapa
 * Last Updated: 10/7
 * Simple Blink
 */

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode

    P1DIR |= 0x01;                          // Set P1.0 to output direction
    for(;;) {
        volatile unsigned int i;            // volatile to prevent optimization

        P1OUT ^= 0x01;                      // Toggle P1.0, LED1, with XOR

        i = 10000;                          // Delay blinking through a do-while loop
        do i--;
        while(i != 0);
    }
}
