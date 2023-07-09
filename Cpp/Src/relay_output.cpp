/*
 * OutputDevice.cpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#include "relay_output.hpp"

RelayOutput::RelayOutput() {

	relay_gpiox_ = GPIOB;
	relay_gpio_pin_ = GPIO_PIN_9;
	relay_state_ = kRelayOff;
}

RelayOutput::~RelayOutput() {
	// TODO Auto-generated destructor stub
}

void RelayOutput::On() {
	if (relay_state_ == kRelayOff) {
		HAL_GPIO_WritePin(relay_gpiox_, relay_gpio_pin_, GPIO_PIN_SET);
		relay_state_ = kRelayOn;
	}
}

void RelayOutput::Off() {
	if (relay_state_ == kRelayOn) {
		HAL_GPIO_WritePin(relay_gpiox_, relay_gpio_pin_, GPIO_PIN_RESET);
		relay_state_ = kRelayOff;
	}
}
