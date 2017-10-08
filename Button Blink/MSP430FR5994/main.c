#include <msp430fr5994.h>
/**
 * main.c
 * Blink an LED using a button press
 * MSP430FR5994
 * Author: Shani Thapa
 * Last Updated: 10/7
 * Button Blink
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode

    P5REN |= BIT5;                          // enable pull-up resistor on P5.5
    P5OUT = BIT5;                           // set resistor to pull up on switch P5.5
    P1DIR = BIT0;                           // set P1.0 as an output

    while(1)                                // loop forever
    {
        if(!(P5IN & BIT5))                  // when button P5.5 is pressed
        {
            __delay_cycles(100000);         // delay toggling by injecting junk code
            P1OUT ^= BIT0;                  // Toggle LED1
        }
    }
}
