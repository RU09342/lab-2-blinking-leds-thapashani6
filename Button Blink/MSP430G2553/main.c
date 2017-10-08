#include <msp430.h> 
/**
 * main.c
 * Blink an LED using a button press
 * MSP430G2553
 * Author: Shani Thapa
 * Last Updated: 10/7
 * Button Blink
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
   // PM5CTL0 &= ~LOCKLPM5;                 // Disable the GPIO power-on High-Z mode

    P1REN |= BIT3;                          // enable resistor on P1.3, a switch
    P1OUT = BIT3;                           // set resistor to pull up on P1.3, a switch
    P1DIR = BIT0;                           // set P1.0, LED1, as an output

    while(1)                                // while loop that runs forever
    {
        if(!(P1IN & BIT3))                  // If statement: when button, P1.3, is pushed
        {
            __delay_cycles(100000);         // delays toggling LED by injecting junk code
            P1OUT ^= BIT0;                  // Toggles P1.0, LED1, with XOR
        }
    }
}
