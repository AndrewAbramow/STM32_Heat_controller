#pragma once
#include "stm32f1xx_hal.h"
#include <stdint.h>
#include <memory>

// https://github.com/vtx22/STM32-DS18B20

class DS18B20
{
public:
	DS18B20();
	~DS18B20();
	float readTemperature();

private:
	//PIN CONFIG AND SETTING
	void setDataPin(bool on);
	void toggleDataPin();

	void setPinOUTPUT();
	void setPinINPUT();

	//INTERFACING FUNCTIONS
	void startSensor();

	void writeData(uint8_t data);
	uint8_t readData();

	void delayUS(uint16_t us);

	TIM_HandleTypeDef* _tim;
};
