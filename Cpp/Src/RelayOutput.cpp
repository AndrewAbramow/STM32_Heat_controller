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
	HAL_GPIO_WritePin(relayGpiox, relayGpioPin,GPIO_PIN_SET);
}

void RelayOutput::Off()
{
	HAL_GPIO_WritePin(relayGpiox, relayGpioPin,GPIO_PIN_RESET);
}
