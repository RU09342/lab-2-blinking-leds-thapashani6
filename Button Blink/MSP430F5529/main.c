#include <msp430.h> 
/**
 * main.c
 * Blink an LED using a button press
 * MSP430F5529
 * Author: Shani Thapa
 * Last Updated: 10/7
 * Button Blink
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    //PM5CTL0 &= ~LOCKLPM5;                 // Disable the GPIO power-on High-Z mode

    P1REN |= BIT1;                          //enable resistor on P1.1, a switch
    P1OUT = BIT1;                           // set resistor to pull up on a switch, P1.1
    P1DIR = BIT0;                           // set P1.0, LED1, as an output

    while(1)
    {
        if(!(P1IN & BIT1))                  // If statement for button push
        {
            __delay_cycles(100000);         // delay code by injecting junk
            P1OUT ^= BIT0;                  // toggle P1.0, LED1, with XOR
        }
    }
}
