#include <msp430.h>
/**
 * main.c
 * Blink multiple LEDs
 * MSP430G2553
 * Shani Thapa
 * 10/7/17
 * Multiple Blink
 */

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
   // PM5CTL0 &= ~LOCKLPM5;                 // Disable the GPIO power-on High-Z mode, but turned off since board won't run with it on

    P1DIR |= BIT0;                          // Set P1.0, LED1, as an output
    P1DIR |= BIT6;                          // Set P1.6, LED2, as an output
    for(;;) {                               // For loop runs forever
        volatile unsigned int i;            // volatile to prevent optimization
        __delay_cycles(500000);             // Delay toggling LED1 by injecting junk code
        P1OUT ^= BIT0;                      // Toggle P1.0, LED1, using XOR
        __delay_cycles(100000);
        P1OUT ^= BIT6;                      // Toggle P1.6, LED2, using XOR

        i = 10000;                          // Delay toggling LEDs by running through do-while statement
        do i--;
        while(i != 0);
    }
}
