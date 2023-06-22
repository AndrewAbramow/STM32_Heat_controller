/*
 * PIDRegulaor.cpp
 *
 *  Created on: May 15, 2023
 *      Author: abramov.a
 */

#include <PIDRegulator.hpp>

PID_Regulator::PID_Regulator(unsigned char targetTemp,
		unsigned char period,
		std::shared_ptr<AdaptiveFilter>filter,
		std::shared_ptr<DS18B20>ds18b20,
		std::shared_ptr<RelayOutput>relay)
		: targetTemp_(targetTemp),
		  period_(period),
		  filter_(filter),
		  ds18b20_(ds18b20),
		  relay_(relay) {
	int dt = 0;
	int minOut = 1; // 1 sec
	int maxOut = 10; // 10 sec
	float kp = 1;
	float ki = 1;
	float kd = 1;
	cycle_ = kOff;
}

PID_Regulator::~PID_Regulator() {
	// TODO Auto-generated destructor stub
}

float PID_Regulator::GetTemperature()
{
	return filter_->RenewVal(ds18b20_->readTemperature());
}

float PID_Regulator::Clamp(float value, float min, float max)
{
  return (value < min)? min : (value > max)? max : value;
}

int PID_Regulator::GetNewWidth (float input)
{
	 float err = (float)targetTemp_ - input;

	 integral = Clamp(integral + (float)err * dt * ki, minOut, maxOut);

	 float D = (err - prevErr) / dt;
	 prevErr = err;

	 return Clamp(err * kp + integral + D * kd, minOut, maxOut);
}

void PID_Regulator::TemperatureSupport(float current_temp)
{
	// calling this function in CppMain every second
	// regulation range: 1-10 sec
	if (cycle_ == kOff) {  // start new cycle
		heat_up_ = GetNewWidth(current_temp);  // heating time (sec)
		cool_down_ = period_ - heat_up_;  // cooling time (sec)
		cycle_ = kOn;
		stage_ = kCoolDown;
	}
	if(cycle_ == kOn) {
		if (stage_ == kCoolDown) {  // cooling
			if (cool_down_ != 0) {
			relay_-> Off();
			--cool_down_;
			}
			if (cool_down_ == 0) stage_ = kHeatUp;
		} else if(stage_ == kHeatUp && heat_up_ != 0) {  // heating
			relay_-> On();
			--heat_up_;
		} else if (heat_up_ == 0 && cool_down_ == 0) {  // end of cycle
			relay_-> Off();
			cycle_ = kOff;
		}
	}
}
