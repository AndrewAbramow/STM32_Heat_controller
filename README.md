# STM32_Heat_controller

## Oversimplified version of TRM1 (heat controller) based on STM32F103C8. 

![Alt text](Docs/Heat_controller.jpg)

## Additional devices

- DS18B20 input (temperature)
- SRD-05VDC relay output

## Features

- ON-OFF regulator
![Alt text](Docs/ON_OFF.png)
- PID regulator
![Alt text](Docs/PID.png)
- Adaptive filter

## Project goal

Design relatively cheap heat cotroller

## Tech

- [Adaptive filter implementation](https://alexgyver.ru/lessons/pid/)

- [DS18B20](https://github.com/vtx22/STM32-DS18B20)

- [PID controller implementation](https://alexgyver.ru/lessons/pid/)

- [TM1637](https://github.com/UsefulElectronics/stm32-tm1637-library)

## Requirements

STM32CubeIDE 1.11.0 or higher

## Schemes

![Alt text](Docs/Structure.png)
![Alt text](Docs/Scheme.png)

## Documentation

[by Doxygen](Docs)
