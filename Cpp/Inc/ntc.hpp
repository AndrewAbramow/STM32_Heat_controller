/*
 * ntc.h
 *
 *  Created on: Sep 22, 2023
 *      Author: Andrew
 */

#ifndef INC_NTC_HPP_
#define INC_NTC_HPP_

#include <stdint.h>
#include "stm32f1xx_hal.h"

class NTC {
public:
	NTC();
	virtual ~NTC();
	uint16_t ReadAnalogNTC(ADC_HandleTypeDef hadc1);
	float NTC_Compute();
private:
	float analog_val_;
	uint32_t R_;
	uint32_t Rt_;
	uint16_t b_;
	uint8_t t_;
	uint8_t resolution_;
};

#endif /* INC_NTC_HPP_ */
