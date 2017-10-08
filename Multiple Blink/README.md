# Shani Thapa
## Added Code on 10/8
## Populated README on 10/8

### Code
The task was to blink multiple LEDs. The code is very similar to Simple Blink, just a couple bit more lines.
* This time, **Two** LEDs pin had to be set as output pins
* Then the LEDs were made to blink by XORing the pins 
* The LEDs blinking was delayed 

### Differences
There were more differences with each board's code than Simple Blink. 
* Every board has LED1 set to pin 1.0, however, LED2 is usually different for each board. 
* Once again, all boards besides the G2554 and F5994 had to have the code: `PM5CTL0 &= ~LOCKLPM5;` or the LEDs will not blink. 

#### Example Code Differnces for Setting LEDs as Output Pins 
##### Code for G2553
```
P1DIR |= BIT0;
P1DIR |= BIT6;
```

#### Code for FR2311 
```
P1DIR |= BIT0 + BIT1
``` 