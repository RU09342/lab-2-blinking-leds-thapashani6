## Name: Shani Thapa 
1. Uploaded Code at 10/8
2. Populated README at 10/8

## Code 
The code for each of the Dev boards for Simple Blink were extremely similar. 
* All that was required was to set the LED that was going to blink as an output pin, and then toggle the LED by XORing it. These two lines of codes were doing most of the work. 
* The other part was to slow down the blinking. 
* Finally, there was a line of code to disable High-Z mode which must be present in some boards but absent in others

### Differences
The line of code: PM5CTL0 &= ~LOCKLPM5; which disables High-Z Mode must be present in the following boards: FR6989, FR2311, and FR5994. Meanwhile, that line must be commented out in the G2553 and F5529. Otherwise the LED will not blink.  