# rc-receiver-joystick
A super simple adapter to connect a RC Receiver, to an USB port, using a Digispark board.

The board uses the PPM output of a 2 (or 3) channel RC Receiver, to enable a USB Joystick, that enable the use of a RC Transmitter in RC simulators on the PC

**Requirements:**

1. Digispark board (http://digistump.com/products/1)
2. Arduino IDE 1.8.5
3. Digistump libraries hack, to enable interrupt on change in IO pins (https://github.com/J-Rios/Digispark_DigiUSB-SoftSerial)
4. 2 Servo extensions (to connect the Digispark board to the RC receiver)
4. Some soldering
5. A couple of cold drinks ;)

**Schematic:**

```
RC Receiver               Digispark board

Channel 1  -------------- Pin 0
Channel 2  -------------- Pin 1
                     |--- Pin 2 *
                     |--- Pin 3 *
                          Pin 4
Channel 3  -------------- Pin 5                       
```

*Pins 2 and 3 must be short in order to enable USB device (because of the library hack)

Tested with a Hobbyking 3 channel transmitter and receiver, and VRC simulator. Works great, just like the original VRC adapter. Photos and more info (I will upload a video soon) in http://patolin.com/blog/2018/05/29/receptor-rc-digispark/
