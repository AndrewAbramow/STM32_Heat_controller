/*
 * LogicDevice.hpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#ifndef SRC_LOGICDEVICE_HPP_
#define SRC_LOGICDEVICE_HPP_

#include <stdint.h>
#include <memory>
#include "AdaptiveFilter.hpp"
#include "DS18B20.hpp"
#include "RelayOutput.hpp"

enum RegulatorMode
{
	HEATER,
	COOLER
};

enum RegulatorState
{
	REGULATOR_ON,
	REGULATOR_OFF
};

class OnOffRegulator {
public:
	OnOffRegulator( uint8_t targetTemp,
					uint8_t hysteresis,
					std::shared_ptr<AdaptiveFilter>filter,
					std::shared_ptr<DS18B20>ds18b20,
					std::shared_ptr<RelayOutput>relay);
	virtual ~OnOffRegulator();
	float GetTemperature();
	void TemperatureSupport(RegulatorMode regulatorMode);

private:
	uint8_t _targetTemp = 0;
	uint8_t _hysteresis = 0;

	std::shared_ptr<AdaptiveFilter>_filter;
	std::shared_ptr<DS18B20>_ds18b20;
	std::shared_ptr<RelayOutput>_relay;

	RegulatorState regulatorState = REGULATOR_OFF;
	RegulatorMode regulatorMode = HEATER;
};

#endif /* SRC_LOGICDEVICE_HPP_ */
