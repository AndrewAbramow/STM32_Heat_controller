/*
 * LogicDevice.cpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#include "OnOffRegulator.hpp"

OnOffRegulator::OnOffRegulator(	uint8_t targetTemp,
								uint8_t hysteresis,
								std::shared_ptr<AdaptiveFilter>filter,
								std::shared_ptr<DS18B20>ds18b20,
								std::shared_ptr<RelayOutput>relay)
								:
								_targetTemp(targetTemp),
								_hysteresis(hysteresis),
								_filter(filter),
								_ds18b20(ds18b20),
								_relay(relay) {}

OnOffRegulator::~OnOffRegulator() {
	// TODO Auto-generated destructor stub
}

float OnOffRegulator::GetTemperature()
{
	return _filter->RenewVal(_ds18b20->readTemperature());
}

void OnOffRegulator::TemperatureSupport(RegulatorMode regulatorMode)
{
	uint8_t temp = GetTemperature();

	if (regulatorMode == HEATER)
	{
		if ((temp <= (_targetTemp - _hysteresis))
				&& regulatorState == REGULATOR_OFF)
		{
			// Heater ON
			_relay -> On();
			regulatorState = REGULATOR_ON;

		}
		else if ((temp >= (_targetTemp + _hysteresis))
				&& regulatorState == REGULATOR_ON)
		{
			// Heater OFF
			_relay -> Off();
			regulatorState = REGULATOR_OFF;
		}
	}
	else if (regulatorMode == COOLER)
	{
		if ((temp > (_targetTemp + _hysteresis))
				&& regulatorState == REGULATOR_OFF)
		{
			// Cooler ON
			_relay -> On();
			regulatorState = REGULATOR_ON;
		}
		else if ((temp < (_targetTemp - _hysteresis))
				&& regulatorState == REGULATOR_ON)
		{
			// Cooler OFF
			_relay -> Off();
			regulatorState = REGULATOR_OFF;
		}
	}
}


