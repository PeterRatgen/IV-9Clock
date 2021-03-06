# IV-9Clock

The goal of this project is to make a clock with IV-9 numitrons. 
# Milestones:

- Preliminary board schematic **Done**
- Development component list **(WIP)**
- Program development, for this the Arduino will be used **(WIP)**
- Custom board schematic
- Prototyping
- Assembly and finish

## Preliminary board schematic

#### Choices of components

The preliminary choice of microcontroller is the ATMEL ATmega328P. Because an Arduino Nano can be used for development. We are likely to use a TFQP package to save space on our board. For resistors and other components, we'll use SMD components.
We will use an ATmega328P. For timekeeping a 16 MHz crystal will be used. To the crystal we will use to capacitors:

CL = (C1 * C2) / (C1 + C2) + Cstray, CL = capcitative load of the crystal = 20, Cstray = 4pF. Here C1 = C2.  
From this we get C1 = C2 = 32 pF.

At this time, using shift registers presents themselves as the best way of communicating with the IV-9 numitrons. The TPIC6B595N shift register will be used, as it can handle the 20 mA current.

A shift register (the TPIC6B595N model) is the logical choice as, it is possible to control 6 displays with four ports(the SRCK, SRCLR, RCLK and SER_IN ports). 

We will use connectors to connect the IV-9's, this should give the ability to swap out the numitrons at ease. As the connectors on the IV-9's are circular the plan is to use this: <img src="https://github.com/PeterRatgen/IV-9Clock/blob/master/connection.jpg" width = "200"> scheme using two 1x5 connectors. However will first be relevant when producing the final custom board layout. 

Since the connectors to the IV-9's act as the ground lead the ground lead should be connected to a 4.5V supply. Thus we might consider a way of adjusting 5V to 4.5V.

#### Programming

At this time, we've experimented with programming "hello world" type programs. Of course C programming will be used. `avr-gcc` will be used for compiling code and `avrdude` will be used for uploading code. More specifically we will use `AVRDUDESS 2.6`. To program the chip we will use the PICKIT2, as is supported by `AVRDUDESS 2.6`. to control the PICKIT2 we will use MPLAB IDE 8.92.
After examining more options, a better way of compling is using `AVRstudio 7.0`. 


## Component list

### Bought

- ATmega328P
- 16 MHz crystal https://www.sparkfun.com/products/536
- Wires
- Arduino Nano
- 22 pF capacitor
- 220 Ohm resistor  for the numitrons because, 4.5V = 19.5 mA/x, solved for x = 230

### To-buy

- Power supply (maybe a varible one)

### Contraints of components

#### IV-9

Cannot update segments faster than 1,4 s.

## Resources:

#### SMD and TQFP soldering techniques:
https://www.youtube.com/watch?v=wUyetZ5RtPs&ab_channel=CuriousInventor
https://www.youtube.com/watch?v=VxMV6wGS3NY&ab_channel=GreatScott%21

#### IV-9
http://www.tube-tester.com/sites/nixie/data/IV-9/iv-9.htm

#### Arduino Nano
https://store.arduino.cc/arduino-nano

#### TPIC6B595
http://www.ti.com/lit/ds/symlink/tpic6b595.pdf
