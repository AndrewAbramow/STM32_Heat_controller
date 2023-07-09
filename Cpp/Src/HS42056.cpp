/*
 * HS42056.cpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#include "hs42056.hpp"

HS42056::HS42056() {
	// TODO Auto-generated constructor stub

}

HS42056::~HS42056() {
	// TODO Auto-generated destructor stub
}

void HS42056::Init() {
	for (auto& el : displayAGpioPin) {
		HAL_GPIO_WritePin(GPIOA, el, GPIO_PIN_RESET);
	}
	HAL_GPIO_WritePin(GPIOB, displayDGpioPin[0] |
							 displayDGpioPin[3] |
							 displayDGpioPin[1] |
							 displayDGpioPin[2],
							 GPIO_PIN_SET);
}

void HS42056::SevenSegmentUpdate(uint8_t number) {
	uint8_t i = 0;
	for (auto& el : displayAGpioPin) {
		HAL_GPIO_WritePin(GPIOA, el, (GPIO_PinState)((number>>i) & 0x01));  // explicit conversion also works
		++i;
	}
}

void HS42056::SeparateDigits (uint8_t number) {
	numbers[0] = number/1000;
	numbers[1] = ((number/100)%10);
	numbers[2] = ((number/10)%10);
	numbers[3] = (number%10);
}

void HS42056::DisplayNumber(uint8_t number) {
	SeparateDigits (number);
	SevenSegmentUpdate(numbers[0]);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_Delay(7);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
	SevenSegmentUpdate(numbers[1]);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_Delay(7);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
	SevenSegmentUpdate(numbers[2]);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_Delay(7);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
	SevenSegmentUpdate(numbers[3]);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_Delay(7);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
	HAL_Delay(1000);
}
