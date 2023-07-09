/*
 * OutputDevice.hpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#ifndef OUTPUTDEVICE_HPP_
#define OUTPUTDEVICE_HPP_

#include "stm32f1xx_hal.h"

enum RelayState {
	kRelayOn,
	kRelayOff
};

class RelayOutput {
 public:
                RelayOutput();
  virtual       ~RelayOutput();
  void          On();
  void          Off();
 private:
  GPIO_TypeDef* relay_gpiox_;
  uint16_t      relay_gpio_pin_;
  RelayState    relay_state_;
};

#endif /* OUTPUTDEVICE_HPP_ */
