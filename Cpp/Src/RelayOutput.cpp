/*
 * OutputDevice.cpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#include "RelayOutput.hpp"

RelayOutput::RelayOutput() {

	relayGpiox = GPIOB;
	relayGpioPin = GPIO_PIN_9;
	relayState = RELAY_OFF;
}

RelayOutput::~RelayOutput() {
	// TODO Auto-generated destructor stub
}

void RelayOutput::On()
{
	if (relayState == RELAY_OFF)
	{
		HAL_GPIO_WritePin(relayGpiox, relayGpioPin, GPIO_PIN_SET);
		relayState = RELAY_ON;
	}
}

void RelayOutput::Off()
{
	if (relayState == RELAY_ON)
	{
		HAL_GPIO_WritePin(relayGpiox, relayGpioPin, GPIO_PIN_RESET);
		relayState = RELAY_OFF;
	}
}
