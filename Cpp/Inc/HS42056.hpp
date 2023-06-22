/*
 * HS42056.hpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#ifndef SRC_HS42056_HPP_
#define SRC_HS42056_HPP_
// https://microcontrollerslab.com/stm32-blue-pill-4-digit-7-segment-display-stm32cubeide/
#include <array>

#include <stdint.h>

#include "stm32f1xx_hal.h"
// HS420561K-32 4-digit 7 segment display
class HS42056 {
public:
	                                            HS42056();
  virtual                                       ~HS42056();
  void                                          Init();
  void                                          SevenSegmentUpdate(uint8_t number);
  void                                          SeparateDigits (uint8_t number);
  void                                          DisplayNumber(uint8_t number);
 private:
	// HEX code for digits
	std::array<uint8_t,10> segmentNumber = {    0x3f,
											    0x06,
											    0x5b,
											    0x4f,
											    0x66,
											    0x6d,
											    0x7d,
											    0x07,
											    0x7f,
											    0x67 };
	// D1 - D4 pins:
	GPIO_TypeDef * displayDGpiox;
	std::array<uint16_t,4> displayDGpioPin = {	GPIO_PIN_6,
												GPIO_PIN_4,
											    GPIO_PIN_5,
												GPIO_PIN_3};
	// A - G pins
	GPIO_TypeDef * displayAGpiox;
	std::array<uint16_t,7> displayAGpioPin = {	GPIO_PIN_0,
												GPIO_PIN_1,
												GPIO_PIN_2,
												GPIO_PIN_3,
												GPIO_PIN_4,
												GPIO_PIN_5,
												GPIO_PIN_6};
	// buffers for digits
	std::array<uint8_t,4> numbers =             {1, 2, 3, 4};
};

#endif /* SRC_HS42056_HPP_ */
