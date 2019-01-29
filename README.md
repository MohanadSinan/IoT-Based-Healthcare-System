# IoT Based Healthcare System

>**[Graduation Project]**
>
>**Team Members:**
>----
>- Mohanad Mohammed Sinan
>- 
>- 
>- 
>- 
>**Supervisor:**
>----
>- Dr. Ghazi BEN HMIDA
----

#
| Contents |
| --- |
| [Abstract](#abstract) |
| [Block Diagram](#block-diagram) |
| [Components](#components) |
| [Pulse Sensor](#pulse-sensor) |
| [LM35 Temperature Sensor](#lm35-temperature-sensor) |
| [ESP8266](#esp8266) |
| [Circuit Diagram & Connections](#circuit-diagram--connections) |
| [ThingSpeak](#thingspeak) |
| [Source Code/Program](#source-codeprogram) |
| [Video Tutorial & Explanation](#video-tutorial--explanation) |



## Abstract:

![IoT Based Healthcare System](https://i.imgur.com/0HTZxRd.jpg)

In this project we have designed IoT Based Patient Health Monitoring System using *ESP8266* &amp; *Arduino*.
The IoT platform used in this project is *ThingSpeak*.
ThingSpeak is an open source Internet of Things (IoT) application and API to store and retrieve data from things 
using the HTTP protocol over the Internet or via a Local Area Network.
This IoT device could read pulse rate and measure surrounding temperature.
It continuously monitors the pulse rate and surrounding temperature and updates them to an IoT platform.

The Arduino Sketch running over the device implements the various functionalities of the project like reading sensor data,
converting them into strings, passing them to the IoT platform and displaying measured pulse rate and temperature on character LCD.

## Block Diagram:

![Block Diagram](https://i.imgur.com/7HIYp80.jpg)

This is a simple block diagram that explains IoT Based Patient Health Monitoring System using *ESP8266* & *Arduino*.
*Pulse Sensor* and *LM35 Temperature Sensors* measures BPM & Environmental Temperature respectively.
The Arduino processes the code and displays to 16*2 LCD Display.
ESP8266 Wi-Fi module connects to Wi-Fi and sends the data to IoT device server. The IoT server used here is ThingSpeak.
Finally, the data can be monitored from any part of the world by logging into ThingSpeak channel.

## Components:
1. *Arduino UNO Board*
2. *ESP8266 Wi-Fi Module*
3. *Pulse Sensor*
4. *LM35 Temperature Sensor*
5. *16***2 LCD Display*
6. *Resistor 2K*
7. *Resistor 1K*
8. *LED*
9. *Breadboard*
10. *Connecting Wires*

## Pulse Sensor:

![pulse-sensor](https://i.imgur.com/nzjsUrZ.png)

The *Pulse Sensor* is a plug-and-play *heart-rate sensor for Arduino*.
It can be used by students, artists, athletes, makers,
and game & mobile developers who want to easily incorporate live heart-rate data into their projects.
Essence it is an integrated optical amplifying circuit and noise eliminating circuit sensor.
Clip the Pulse Sensor to your earlobe or fingertip and plug it into your Arduino, you can ready to read heart rate.
Also, it has an Arduino demo code that make it easy to use.

The pulse sensor has three pins: VCC, GND & Analog Pin.
![pulse-sensor](https://i.imgur.com/tzXCQah.png)
There is also a LED in the center of this sensor module which helps in detecting the heartbeat.
Below the LED, there is a noise elimination circuitry which is supposed to keep away the noise from affecting the readings.

## LM35 Temperature Sensor:

![Temperature-sensor](https://i.imgur.com/4Ml4XvM.jpg)

The LM35 series are precision integrated-circuit temperature devices with an output voltage linearly-proportional to the Centigrade 
temperature. 
The LM35 device has an advantage over linear temperature sensors calibrated in Kelvin, 
as the user is not required to subtract a large constant voltage from the output to obtain convenient Centigrade scaling. 
The LM35 device does not require any external calibration or trimming to provide typical accuracies of ±¼°C at room temperature 
and ±¾°C over a full −55°C to 150°C temperature range.

## ESP8266:

![ESP8266](https://i.imgur.com/OYU41gv.png)

The ESP8266 is a very user friendly and low-cost device to provide internet connectivity to your projects. 
The module can work both as an Access point (can create hotspot) and as a station (can connect to Wi-Fi), 
hence it can easily fetch data and upload it to the internet making Internet of Things as easy as possible. 
It can also fetch data from internet using API’s hence your project could access any information that is available in the internet, 
thus making it smarter. 
Another exciting feature of this module is that it can be programmed using the Arduino IDE which makes it a lot more user friendly.

The ESP8266 module works with 3.3V only, anything more than 3.7V would kill the module hence be cautions with your circuits. 
Here are its pins description.

**Pin 1: Ground:** Connected to the ground of the circuit
**Pin 2: Tx/GPIO – 1:** Connected to Rx pin of programmer/uC to upload program
**Pin 3: GPIO – 2:** General purpose Input/output pin
**Pin 4: CH_EN:** Chip Enable/Active high
**Pin 5: Flash/GPIO – 0:** General purpose Input/output pin
**Pin 6: Reset:** Resets the module
**Pin 7: RX/GPIO – 3:** General purpose Input/output pin
**Pin 8: Vcc:** Connect to +3.3V only

## Circuit Diagram & Connections:
For designing IoT Based Patient Health Monitoring System using ESP8266 & Arduino, assemble the circuit as shown in the figure below.

![Connections](https://i.imgur.com/FUAW5eu.jpg)

1. Connect Pulse Sensor output pin to A0 of Arduino and other two pins to VCC & GND.
2. Connect LM35 Temperature Sensor output pin to A1 of Arduino and other two pins to VCC & GND.
3. Connect the LED to Digital Pin 7 of Arduino via 220-ohm resistor.
4. Connect Pin 1,3,5,16 of LCD to GND.
5. Connect Pin 2,15 of LCD to VCC.
6. Connect Pin 4,6,11,12,13,14 of LCD to Digital Pin12,11,5,4,3,2 of Arduino.
7. The RX pin of ESP8266 works on 3.3V and it will not communicate with the Arduino when we will connect it directly to the Arduino. So, 
we will have to make a voltage divider for it which will convert the 5V into 3.3V. 
This can be done by connecting 2.2K & 1K resistor. 
Thus, the RX pin of the ESP8266 is connected to the pin 10 of Arduino through the resistors.
8. Connect the TX pin of the ESP8266 to the pin 9 of the Arduino.

## ThingSpeak:

ThingSpeak provides very good tool for IoT based projects. 
By using ThingSpeak site, we can monitor our data and control our system over the Internet, 
using the Channels and web pages provided by ThingSpeak. So first you need to sign up for ThingSpeak. 
So, visit https://thingspeak.com and create an account.

![ThingSpeak](https://i.imgur.com/MjsGQnk.jpg)

Then create a new channel and set up what you want.

Then create the *API keys*. This key is required for programming modifications and setting your data.

![ThingSpeak](https://i.imgur.com/glYoIaV.jpg)

Then upload the code to the Arduino UNO by assembling the circuit shown above. 
Open serial monitors and it will automatically connect to Wi-Fi and set up everything.

Now click on channels so that you can see the online data streaming, i.e. 
IoT Based Patient Health Monitoring System using ESP8266 & Arduino as shown in figure here.

![ThingSpeak](https://i.imgur.com/TEUvdau.png)

## Source Code/Program:

The source code for the project IoT Based Patient Health Monitoring System using ESP8266 & Arduino is given below. 
Simply copy the code and paste it to your Arduino IDE, then compile it and upload to your Arduino UNO Board.

[iot_based_healthcare_system.ino]

## Video Tutorial & Explanation:

https://www.youtube.com/watch?v=Utlnd_FDB9A
