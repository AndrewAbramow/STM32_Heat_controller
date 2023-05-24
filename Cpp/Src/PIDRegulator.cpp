/*
 * PIDRegulaor.cpp
 *
 *  Created on: May 15, 2023
 *      Author: abramov.a
 */

#include <PIDRegulator.hpp>

PID_Regulator::PID_Regulator(	uint8_t targetTemp,
								std::shared_ptr<AdaptiveFilter>filter,
								std::shared_ptr<DS18B20>ds18b20,
								std::shared_ptr<RelayOutput>relay)
								:
								_targetTemp(targetTemp),
								_filter(filter),
								_ds18b20(ds18b20),
								_relay(relay) {
	int dt = 0;
	int minOut = 1; // 1 sec
	int maxOut = 10; // 10 sec
	float kp = 1;
	float ki = 1;
	float kd = 1;
	float setpoint;
	uint8_t tickCount = 0;
}

PID_Regulator::~PID_Regulator() {
	// TODO Auto-generated destructor stub
}

float PID_Regulator::GetTemperature()
{
	return _filter->RenewVal(_ds18b20->readTemperature());
}

float PID_Regulator::Clamp(float value, float min, float max)
{
  return (value < min)? min : (value > max)? max : value;
}

int PID_Regulator::GetNewWidth (float input)
{
	 float err = setpoint - input;

	 integral = Clamp(integral + (float)err * dt * ki, minOut, maxOut);

	 float D = (err - prevErr) / dt;
	 prevErr = err;

	 return Clamp(err * kp + integral + D * kd, minOut, maxOut);
}

int PID_Regulator::TemperatureSupport(float input)
{
	// calling this function in CppMain every second
	// regulation range: 1-10 sec
	if (state)
	{
		tickCount = GetNewWidth(GetTemperature());
		state = true;
	}
	else
	{
		--tickCount;
	}
}
