/*
 * LogicDevice.cpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#include "OnOffRegulator.hpp"

OnOffRegulator::OnOffRegulator(	uint8_t target_temp,
    uint8_t hysteresis,
    std::shared_ptr<AdaptiveFilter>filter,
    std::shared_ptr<DS18B20>ds18b20,
    std::shared_ptr<RelayOutput>relay)
    : target_temp_(target_temp),
    hysteresis_(hysteresis),
    filter_(filter),
    ds18b20_(ds18b20),
    relay_(relay) {}

OnOffRegulator::~OnOffRegulator() {
	// TODO Auto-generated destructor stub
}

float OnOffRegulator::GetTemperature() {
	return filter_->RenewVal(ds18b20_->readTemperature());
}

void OnOffRegulator::TemperatureSupport(RegulatorMode regulator_mode) {
  uint8_t temp = GetTemperature();
  if (regulator_mode == kHeater) {
	if ((temp <= (target_temp_ - hysteresis_))
	    && regulator_state_ == kRegulatorOff) {
		// Heater ON
		relay_ -> On();
		regulator_state_ = kRegulatorOn;
	} else if ((temp >= (target_temp_ + hysteresis_))
		&& regulator_state_ == kRegulatorOn) {
		// Heater OFF
		relay_ -> Off();
		regulator_state_ = kRegulatorOff;
	}
  } else if (regulator_mode == kCooler)	{
    if ((temp > (target_temp_ + hysteresis_))
		&& regulator_state_ == kRegulatorOff) {
		// Cooler ON
		relay_ -> On();
		regulator_state_ = kRegulatorOn;
    } else if ((temp < (target_temp_ - hysteresis_))
		&& regulator_state_ == kRegulatorOn) {
		// Cooler OFF
		relay_ -> Off();
		regulator_state_ = kRegulatorOff;
    }
  }
}


