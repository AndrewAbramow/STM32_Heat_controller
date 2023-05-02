/*
 * HS42056.cpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#include "HS42056.hpp"

HS42056::HS42056() {
	// TODO Auto-generated constructor stub

}

HS42056::~HS42056() {
	// TODO Auto-generated destructor stub
}

void HS42056::Init()
{
	for (auto& el : displayAGpioPin)
	{
		HAL_GPIO_WritePin(GPIOA, el, GPIO_PIN_RESET);
	}

	HAL_GPIO_WritePin(GPIOB, displayDGpioPin[0] |
													 displayDGpioPin[3] |
													 displayDGpioPin[1] |
													 displayDGpioPin[2],
													 GPIO_PIN_SET);
}

void HS42056::SevenSegmentUpdate(uint8_t number){

	uint8_t i = 0;
	for (auto& el : displayAGpioPin)
	{
		HAL_GPIO_WritePin(GPIOA, el, (GPIO_PinState)((number>>i) & 0x01)); // explicit conversion also works
		++i;
	}
}

// I need middle function for
// highlight the digits of a number
// HERE \\

void HS42056::DisplayNumber(uint8_t number)
{
	SevenSegmentUpdate(segmentNumber[temp1]);
		  D1_LOW;
		  HAL_Delay(7);
		  D1_HIGH;

		  SevenSegment_Update(segmentNumber[temp2]);
		  D2_LOW;
		  HAL_Delay(7);
		  D2_HIGH;

		  SevenSegment_Update(segmentNumber[temp3]);
		  D3_LOW;
		  HAL_Delay(7);
		  D3_HIGH;

		  SevenSegment_Update(segmentNumber[temp4]);
		  D4_LOW;
		  HAL_Delay(7);
		  D4_HIGH;

		  counter++;
		  if (counter >= 1000){
			  counter = 0;
		  }
		 HAL_Delay(1000);
}
