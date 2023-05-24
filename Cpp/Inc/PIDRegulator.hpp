/*
 * PIDRegulaor.hpp
 *
 *  Created on: May 15, 2023
 *      Author: abramov.a
 */

#ifndef SRC_PIDREGULATOR_HPP_
#define SRC_PIDREGULATOR_HPP_

#include "memory"
#include "AdaptiveFilter.hpp"
#include "DS18B20.hpp"
#include "RelayOutput.hpp"

// https://alexgyver.ru/lessons/pid/

class PID_Regulator {
public:
	PID_Regulator(  uint8_t targetTemp,
					std::shared_ptr<AdaptiveFilter>filter,
					std::shared_ptr<DS18B20>ds18b20,
					std::shared_ptr<RelayOutput>relay);
	virtual ~PID_Regulator();

	float GetTemperature();
	int GetNewWidth (float input); // PWM
	int TemperatureSupport(float input);
	float Clamp(float value, float min, float max);

private:

	uint8_t _targetTemp = 0;

	std::shared_ptr<AdaptiveFilter>_filter;
	std::shared_ptr<DS18B20>_ds18b20;
	std::shared_ptr<RelayOutput>_relay;

	int dt = 0;
	int minOut = 0;
	int maxOut = 0;

	float kp = 1;
	float ki = 1;
	float kd = 1;
	float setpoint;
	float integral = 0;
	float prevErr = 0;

	int tickCount = 0;

	bool state = false;

};

#endif /* SRC_PIDREGULAOR_HPP_ */
