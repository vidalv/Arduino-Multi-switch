# Arduino-Multi-switch
Arduino code 2 buttons -> 6 functions.
With an Arduino, it's easy to assign a function to a switch / push button.
This video shows how to interact on multiple buttons to perform a function with the button combination.
Here 2 momentary push buttons act to access 6 functions. The pusg delay time is programmable.
To see the functions, I use LEDs.
At the start, everything is "OFF"
The actions act on the functions:
- BP1 -> Short press = Blue LED BP1 ON / OFF.
- BP2 -> Press Short = red LED BP2 ON / OFF.
- BP1 -> Long press = green LED ON / OFF.
- BP2 -> Long press = white LED ON / OFF.
- BP1 + BP2 -> Press Short = blue LED = ON / OFF.
- BP1 + BP2 -> Long press = yellow LED ON / OFF.

On schematic I use ULN2803 to drive the leds (not Nano output drive directly) and to avoid bouncing I use
Capacitor and Schmitt Trigger like SN74LS540 circuit.
