/*
 * LogicDevice.hpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#ifndef SRC_LOGICDEVICE_HPP_
#define SRC_LOGICDEVICE_HPP_

#include <stdint.h>
#include "AdaptiveFilter.hpp"
#include "DS18B20.hpp"
#include "RelayOutput.hpp"

enum Mode
{
	HEATER,
	COOLER
};

enum State
{
	ON,
	OFF
};

class OnOffRegulator {
public:
	OnOffRegulator(uint8_t targetTemp, uint8_t hysteresis);
	virtual ~OnOffRegulator();
	float GetTemperature();
	void TemperatureSupport(Mode mode);


private:
	//std::unique_ptr<AdaptiveFilter> filter;
	//std::unique_ptr<DS18B20> ds18b20;
	//std::unique_ptr<RelayOutput> relay;

	uint8_t _targetTemp;
	uint8_t _hysteresis;

	State state;
};

#endif /* SRC_LOGICDEVICE_HPP_ */
