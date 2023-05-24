/*
 * OutputDevice.hpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#ifndef OUTPUTDEVICE_HPP_
#define OUTPUTDEVICE_HPP_

#include "stm32f1xx_hal.h"

enum RelayState
{
	RELAY_ON,
	RELAY_OFF
};

class RelayOutput {
public:
	RelayOutput();
	virtual ~RelayOutput();

	void On();
	void Off();

private:
	GPIO_TypeDef* relayGpiox;
	uint16_t relayGpioPin;

	RelayState relayState;
};

#endif /* OUTPUTDEVICE_HPP_ */
