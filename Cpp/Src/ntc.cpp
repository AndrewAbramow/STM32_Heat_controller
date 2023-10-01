/*
 * ntc.cpp
 *
 *  Created on: Sep 22, 2023
 *      Author: Andrew
 */
#include <math.h>

#include <ntc.hpp>

NTC::NTC() {
	b_ = 3495;          // temperature coefficient
	t_ = 25;            // normal temperature
	Rt_ = 11000;        // resistance at normal temperature
	R_ = 10000;         // additional resistance
	resolution_ = 12;   // blue pill ADC - 12 bit
	analog_val_ = 0.0f; // default value
}

NTC::~NTC() {
	// TODO Auto-generated destructor stub
}

uint16_t NTC::ReadAnalogNTC(ADC_HandleTypeDef hadc1) {
	HAL_ADC_Start(&hadc1);
	analog_val_ = (float)HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);
	return (float)analog_val_;
}

float NTC::NTC_Compute() {
	analog_val_ = 0.9f/((float)(4096 - 1)/analog_val_ - 1.0f);
	analog_val_ = (log(analog_val_) / b_) + 1.0f / (t_ + 273.15f);
	return (1.0f / analog_val_ - 273.15f);
}

