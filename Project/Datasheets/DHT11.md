###### [`Home`](https://mohanadsinan.github.io/IoT-Based-Healthcare-System/)

# DHT11 Temperature and Humidity Sensor
| ![](https://i.imgur.com/xChE6H7.jpg) | ![](https://i.imgur.com/wG1RNkT.jpg) |
| :---: | :---: |
| DHT11 Temperature and Humidity Sensor | DHT11 Sensor Pinout |

## Pin Identification and Configuration
### For Sensor
| No. | Pin Name | Description |
| :---: | :---: | --- |
| **1** | **Vcc** | Power supply 3.5V to 5.5V |
| **2** | **Data** | Outputs both Temperature and Humidity through serial Data |
| **3** | **NC** | No Connection and hence not used |
| **4** | **Ground** | Connected to the ground of the circuit |

### For module
| No. | Pin Name | Description |
| :---: | :---: | --- |
| **1** | **Vcc** | Power supply 3.5V to 5.5V |
| **2** | **Data** | Outputs both Temperature and Humidity through serial Data |
| **4** | **Ground** | Connected to the ground of the circuit |

## Specifications
- Operating Voltage: 3.5V to 5.5V
- Operating current: 0.3mA (measuring) 60uA (standby)
- Output: Serial data
- Temperature Range: 0°C to 50°C
- Humidity Range: 20% to 90%
- Resolution: Temperature and Humidity both are 16-bit
- Accuracy: ±1°C and ±1%

> **Note:** The [**DHT11 datasheet**](#component-datasheet) can be found at the bottom of the page

## Equivalent Temperature Sensors
DHT22, AM2302, SHT71

## Other Temperature Sensors:
Thermocouple, TMP100, LM75, DS18820, SHT15, LM35DZ, TPA81, D6T

## Difference between DHT11 Sensor and module
The DHT11 sensor can either be purchased as a sensor or as a module. Either way, the performance of the sensor is same. The sensor will come as a 4-pin package out of which only three pins will be used whereas the module will come with three pins as shown above.

The only difference between the sensor and module is that the module will have a filtering capacitor and pull-up resistor inbuilt, and for the sensor, you have to use them externally if required.

## Where to use DHT11
The DHT11 is a commonly used Temperature and humidity sensor. The sensor comes with a dedicated NTC to measure temperature and an 8-bit microcontroller to output the values of temperature and humidity as serial data. The sensor is also factory calibrated and hence easy to interface with other microcontrollers.

The sensor can measure temperature from 0°C to 50°C and humidity from 20% to 90% with an accuracy of ±1°C and ±1%. So if you are looking to measure in this range then this sensor might be the right choice for you.

## How to use DHT11 Sensor
The DHT11 Sensor is factory calibrated and outputs serial data and hence it is highly easy to set it up. The connection diagram for this sensor is shown below.

![](https://i.imgur.com/P9q8Meb.png)

As you can see the data pin is connected to an I/O pin of the MCU and a 5K pull-up resistor is used. This data pin outputs the value of both temperature and humidity as serial data. If you are trying to interface DHT11 with Arduino then there are ready-made libraries for it which will give you a quick start.

If you are trying to interface it with some other MCU then the datasheet given below will come in handy. The output given out by the data pin will be in the order of 8bit humidity integer data + 8bit the Humidity decimal data +8 bit temperature integer data + 8bit fractional temperature data +8 bit parity bit. To request the DHT11 module to send these data the I/O pin has to be momentarily made low and then held high as shown in the timing diagram below

![](https://i.imgur.com/9IyVHoy.png)

The duration of each host signal is explained in the DHT11 datasheet, with neat steps and illustrative timing diagrams

## Applications
- Measure temperature and humidity
- Local Weather station
- Automatic climate control
- Environment monitoring

## Component Datasheet
[DHT11 Sensor Datasheet](DHT11.pdf)
