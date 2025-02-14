#include <msp430.h>
/**
 * main.c
 * Blink multiple LEDs
 * MSP430FR5994
 * Shani Thapa
 * 10/7/17
 * Multiple Blink
 */

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default High-Z mode

    P1DIR |= (BIT0+BIT1) ;                  // Set P1.0 and P1.1, LED1 + LED2, as outputs
    for(;;)
    {
        __delay_cycles(500000);               // Delay toggling of LED1 by injecting junk code
        P1OUT ^= (BIT0);                      // Toggle P1.0, LED1, using XOR
        __delay_cycles(100000);
        P1OUT ^= (BIT1);                      // Toggle P1.1, LED2, using XOR
    }

}
