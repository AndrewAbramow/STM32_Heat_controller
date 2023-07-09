/*
 * PIDRegulaor.cpp
 *
 *  Created on: May 15, 2023
 *      Author: abramov.a
 */

#include <pid_regulator.hpp>

PID_Regulator::PID_Regulator(unsigned char target_temp,
    unsigned char period,
    std::shared_ptr<AdaptiveFilter>filter,
    std::shared_ptr<DS18B20>ds18b20,
    std::shared_ptr<RelayOutput>relay)
    : target_temp_(target_temp),
    period_(period),
    filter_(filter),
    ds18b20_(ds18b20),
    relay_(relay) {
	//int dt_ = 0;
	//int min_out_ = 1; // 1 sec
	//int max_out_ = 10; // 10 sec
	//float kp_ = 1;
	//float ki_ = 1;
	//float kd_ = 1;
	cycle_ = kOff;
}

PID_Regulator::~PID_Regulator() {
	// TODO Auto-generated destructor stub
}

float PID_Regulator::GetTemperature() {
	return filter_->RenewVal(ds18b20_->readTemperature());
}

float PID_Regulator::Clamp(float value, float min, float max) {
  return (value < min)? min : (value > max)? max : value;
}

int PID_Regulator::GetNewWidth (float input) {
  float err = (float)target_temp_ - input;
  integral_ = Clamp(integral_ + (float)err * dt_ * ki_, min_out_, max_out_);
  float D = (err - prev_err_) / dt_;
  prev_err_ = err;
  return Clamp(err * kp_ + integral_ + D * kd_, min_out_, max_out_);
}

void PID_Regulator::TemperatureSupport(float current_temp) {
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
      if (cool_down_ == 0) stage_ = kHeatUp;  // stop cooling, start heating
	} else if(stage_ == kHeatUp && heat_up_ != 0) {  // heating
      relay_-> On();
      --heat_up_;
    } else if (heat_up_ == 0 && cool_down_ == 0) {  // end of cycle
      relay_-> Off();
      cycle_ = kOff;
    }
  }
}
