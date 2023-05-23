/*
 * LogicDevice.cpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#include "OnOffRegulator.hpp"

OnOffRegulator::OnOffRegulator(uint8_t targetTemp, uint8_t hysteresis) :
													_targetTemp(targetTemp),
													_hysteresis(hysteresis)
{
	//filter = std::make_unique<AdaptiveFilter>();
	//ds18b20 = std::make_unique<DS18B20>();
	//relay = std::make_unique<RelayOutput>();
}
OnOffRegulator::~OnOffRegulator() {
	// TODO Auto-generated destructor stub
}

float OnOffRegulator::GetTemperature()
{
	//return filter->RenewVal(ds18b20->readTemperature());
}

void OnOffRegulator::TemperatureSupport(Mode mode)
{
	uint8_t temp = GetTemperature();

	if (mode == HEATER)
	{
		if ((temp < (_targetTemp - _hysteresis)) && state == OFF)
		{
			// Heater ON
			//relay -> On();
			state = ON;

		}
		else if ((temp > (_targetTemp + _hysteresis)) && state == ON)
		{
			// Heater OFF
			//relay -> Off();
			state = OFF;
		}
	}
	else if (mode == COOLER)
	{
		if ((temp > (_targetTemp + _hysteresis)) && state == OFF)
		{
			// Cooler ON
			//relay -> On();
			state = ON;
		}
		else if ((temp < (_targetTemp - _hysteresis)) && state == ON)
		{
			// Cooler OFF
			//relay -> Off();
			state = OFF;
		}
	}
}


