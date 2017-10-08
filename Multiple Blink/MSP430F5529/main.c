#include <msp430.h>
/**
 * main.c
 * Blink multiple LEDs
 * MSP430F5529
 * Shani Thapa
 * 10/7/17
 * Multiple Blink
 */

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
   // PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= (BIT0) ;                        // Set P1.0 to output direction
    P4DIR |= BIT7;                         // Set P1.7 to output direction

    for(;;)
    {
        __delay_cycles(500000);               // Delay LED blinking by injecting junk code
        P1OUT ^= (BIT0);                      // Toggle P1.0 using XOR
        __delay_cycles(100000);
        P4OUT ^= (BIT7);                      // Toggle P4.7 using XOR

    }

}
