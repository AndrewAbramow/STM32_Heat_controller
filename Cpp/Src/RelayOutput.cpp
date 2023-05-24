/*
 * OutputDevice.cpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#include "RelayOutput.hpp"

RelayOutput::RelayOutput() {

	relayGpiox = GPIOB;
	relayGpioPin = 9;
}

RelayOutput::~RelayOutput() {
	// TODO Auto-generated destructor stub
}

void RelayOutput::On()
{
	if (relayState == RELAY_OFF)
	{
		HAL_GPIO_TogglePin(relayGpiox, relayGpioPin);
		relayState = RELAY_ON;
	}
}

void RelayOutput::Off()
{
	if (relayState == RELAY_ON)
	{
		HAL_GPIO_TogglePin(relayGpiox, relayGpioPin);
		relayState = RELAY_OFF;
	}
}
