#include <msp430.h>
/**
 * main.c
 * Blink multiple LEDs
 * MSP430FR6989
 * Shani Thapa
 * 10/7/17
 * Multiple Blink
 */

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on High-Z mode

    P1DIR |= BIT0;                          // Set P1.0, LED1, as an output
    P9DIR |= BIT7;                          // Set P9.7, LED1, as an output
    for(;;)
    {                               // For loop runs forever
        __delay_cycles(500000);             // Delay toggling of LED1 by injecting junk code
        P1OUT ^= BIT0;                      // Toggle P1.0, LED1, using XOR
        __delay_cycles(100000);             // Delay toggling of LED2 by injecting junk code
        P9OUT ^= BIT7;                      // Toggle P1.0, LED2, using XOR


    }
}
