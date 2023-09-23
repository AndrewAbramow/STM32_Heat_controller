# STM32_Heat_controller

## Oversimplified version of TRM1 (heat controller) based on STM32F103C8. 
## Video demonstration

[Youtube](https://youtu.be/MHSAD7J2xEI)

## Additional devices

- DS18B20 input (temperature)
- SRD-05VDC relay output
- NTC Thermistor

## Features

![Alt text](Docs/ON_OFF.png)
- ON-OFF regulator

![Alt text](Docs/PID.png)
- PID regulator

- Adaptive filter

## Project goal

Design relatively cheap heat cotroller

## Tech

- [Adaptive filter implementation](https://alexgyver.ru/lessons/filters/)

- [DS18B20](https://github.com/vtx22/STM32-DS18B20)

- [PID controller implementation](https://alexgyver.ru/lessons/pid/)

- [TM1637](https://github.com/UsefulElectronics/stm32-tm1637-library)

- [GyverNTC](https://github.com/GyverLibs/GyverNTC)

## Requirements

STM32CubeIDE 1.11.0 or higher

## Schemes

![Alt text](Docs/Structure.png)
![Alt text](Docs/Scheme.png)
