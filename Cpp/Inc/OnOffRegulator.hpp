/*
 * LogicDevice.hpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#ifndef SRC_LOGICDEVICE_HPP_
#define SRC_LOGICDEVICE_HPP_

#include <memory>

#include <stdint.h>

#include "AdaptiveFilter.hpp"
#include "DS18B20.hpp"
#include "RelayOutput.hpp"

enum RegulatorMode {
  kHeater,
  kCooler
};

enum RegulatorState {
  kRegulatorOn,
  kRegulatorOff
};

class OnOffRegulator {
 public:
	                                OnOffRegulator( uint8_t targetTemp,
	                                    uint8_t hysteresis,
									    std::shared_ptr<AdaptiveFilter>filter,
									    std::shared_ptr<DS18B20>ds18b20,
									    std::shared_ptr<RelayOutput>relay);
  virtual                           ~OnOffRegulator();
  float                             GetTemperature();
  void                              TemperatureSupport(RegulatorMode regulatorMode);

 private:
  uint8_t                           target_temp_ =     0;
  uint8_t                           hysteresis_ =      0;
  std::shared_ptr<AdaptiveFilter>   filter_;
  std::shared_ptr<DS18B20>          ds18b20_;
  std::shared_ptr<RelayOutput>      relay_;
  RegulatorState                    regulator_state_ = kRegulatorOff;
  RegulatorMode                     regulator_mode_ =  kCooler;
};

#endif /* SRC_LOGICDEVICE_HPP_ */
