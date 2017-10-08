#include <msp430.h> 


/**
 * main.c
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode

    P1REN |= BIT1; //enable resistor on P5.5
    P1OUT = BIT1;  // set resistor to pull up, P
    P1DIR = BIT0;  // set P1.0 as an output

    while(1)
    {
        if(!(P1IN & BIT1))
        {
            __delay_cycles(100000);
            P1OUT ^= BIT0;
        }
    }
}
