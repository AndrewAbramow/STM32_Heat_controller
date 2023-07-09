/*
 * PIDRegulaor.hpp
 *
 *  Created on: May 15, 2023
 *      Author: abramov.a
 */

#ifndef SRC_PIDREGULATOR_HPP_
#define SRC_PIDREGULATOR_HPP_

#include "memory"

#include "adaptive_filter.hpp"
#include "ds18b20.hpp"
#include "relay_output.hpp"

// https://alexgyver.ru/lessons/pid/

class PID_Regulator {
 public:
	                                PID_Regulator(unsigned char target_temp,
	                                    unsigned char period,
	                                    std::shared_ptr<AdaptiveFilter> filter,
	                                    std::shared_ptr<DS18B20> ds18b20,
	                                    std::shared_ptr<RelayOutput> relay);
  virtual                           ~PID_Regulator();

  float                             GetTemperature();
  int                               GetNewWidth (float input);
  void                              TemperatureSupport(float current_temp);
  float                             Clamp(float value, float min, float max);
 private:
  unsigned char                     target_temp_ = 0;
  unsigned char                     period_;
  std::shared_ptr<AdaptiveFilter>   filter_;
  std::shared_ptr<DS18B20>          ds18b20_;
  std::shared_ptr<RelayOutput>      relay_;
  int                               dt_ = 1;
  int                               min_out_ = 0;
  int                               max_out_ = 7;
  float                             kp_ = 12;
  float                             ki_ = 0.5;
  float                             kd_ = 50;
  float                             integral_ = 1;
  float                             prev_err_ = 1;
  unsigned char                     cool_down_;
  unsigned char                     heat_up_;
  enum Cycle {
		kOff,
		kOn
	};
	enum Stage {
		kCoolDown,
		kHeatUp
	};
  Cycle cycle_;
  Stage stage_;
};

#endif /* SRC_PIDREGULAOR_HPP_ */
