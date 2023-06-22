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
	PID_Regulator(  unsigned char targetTemp,
					unsigned char period,
					std::shared_ptr<AdaptiveFilter>filter,
					std::shared_ptr<DS18B20>ds18b20,
					std::shared_ptr<RelayOutput>relay);
	virtual ~PID_Regulator();

	float GetTemperature();
	int GetNewWidth (float input);
	void TemperatureSupport(float current_temp);
	float Clamp(float value, float min, float max);

private:

	enum cycle {
		kOff,
		kOn
	};

	enum stage {
		kCoolDown,
		kHeatUp
	};

	unsigned char targetTemp_ = 0;

	std::shared_ptr<AdaptiveFilter>filter_;
	std::shared_ptr<DS18B20>ds18b20_;
	std::shared_ptr<RelayOutput>relay_;

	int dt = 1;
	int minOut = 0;
	int maxOut = 10;

	float kp = 1.8;
	float ki = 3.6;
	float kd = 0.225;
	float integral = 1;
	float prevErr = 1;

	unsigned char period_;
	unsigned char cool_down_;
	unsigned char heat_up_;

	//bool state = false;

	cycle cycle_;
	stage stage_;
};

#endif /* SRC_PIDREGULAOR_HPP_ */
