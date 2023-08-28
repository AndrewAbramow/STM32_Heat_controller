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
  float								Map(float val, float in_min, float in_max,
		  	  	  	  	  	  	  		float out_min, float out_max);
 private:
  int			                    target_temp_ = 0;
  int			                    period_;
  std::shared_ptr<AdaptiveFilter>   filter_;
  std::shared_ptr<DS18B20>          ds18b20_;
  std::shared_ptr<RelayOutput>      relay_;
  int                               dt_ = 10;
  int                               min_out_ = 0;
  int                               max_out_ = 10;
  int								call_count = 0;
  float                             kp_ = 3;
  float                             ki_ = 0.3;
  float                             kd_ = 30;
  float                             integral_ = 0;
  float                             prev_err_ = 0;
  int                     			cool_down_;
  int			                    heat_up_;
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
