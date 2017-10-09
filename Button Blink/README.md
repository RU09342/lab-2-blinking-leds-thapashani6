## Name: Shani Thapa
* Uploaded Code at 10/8
* Populated README at 10/9

### Code 
The task was to blink an LED through a button press. The code is more complex since more registers have to be manipulated to use the button. Not only does the button pin have to be set, but a pull-up/down resistor must be enabled and set on that pin. 
* The PxREN register is manipulated to high(1) to enalbe a resister at that pin
* The PxOUT register is also set to high(1) to set the resister
* The PxDIR register is set at high(1) to make the LED an output 
* Finally, the LED pin is toggled by XORing it 

### Differences 
* Each board generally had a different pinout for thier buttons 
* All the FR boards had to have `PM5CTL0 &= ~LOCKLPM5;` in the code

#### Example Code Differences for Button pinouts 
##### Code for F5994
```
P1REN |= BIT1;                          //enable resistor on P1.1, a switch
P1OUT = BIT1;                           // set resistor to pull up on a switch, P1.1
P1DIR = BIT0;                           // set P1.0, LED1, as an output
```
##### Code for FR5994
```
    P5REN |= BIT5;                          // enable pull-up resistor on P5.5
    P5OUT = BIT5;                           // set resistor to pull up on switch P5.5
    P1DIR = BIT0;                           // set P1.0 as an output
```    