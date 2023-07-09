# STM32_Heat_controller

## Oversimplified version of TRM1 (heat controller) based on STM32F103C8. 

![Alt text](Docs/Heat_controller.jpg)

![Alt text](Docs/Scheme.jpg)

video also will be here

## Features

- DS18B20 input (temperature)
- SRD-05VDC relay output

## Project goal

Design relatively cheap heat cotroller

## Tech

- [Adaptive filter implementation](https://alexgyver.ru/lessons/pid/)

- [DS18B20](https://github.com/vtx22/STM32-DS18B20)

- [PID controller implementation](https://alexgyver.ru/lessons/pid/)

- [TM1637](https://github.com/UsefulElectronics/stm32-tm1637-library)

## Requirements

STM32CubeIDE 1.11.0 or higher

## Documentation

[by Doxygen](Docs/html)