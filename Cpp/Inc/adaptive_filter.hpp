/*
 * DigitalFilter.hpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#ifndef DIGITALFILTER_HPP_
#define DIGITALFILTER_HPP_

#include "math.h"

class AdaptiveFilter {
 public:
	        AdaptiveFilter();
  virtual   ~AdaptiveFilter();

  float     RenewVal(float newVal);
 private:
  float     current_val_;
  float     k_;
};

#endif /* DIGITALFILTER_HPP_ */
