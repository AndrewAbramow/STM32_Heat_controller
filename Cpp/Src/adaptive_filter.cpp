/*
 * DigitalFilter.cpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#include "adaptive_filter.hpp"

AdaptiveFilter::AdaptiveFilter() {
	current_val_ = 0;
	k_           = 1;
}

AdaptiveFilter::~AdaptiveFilter() {
	// TODO Auto-generated destructor stub
}

float AdaptiveFilter::RenewVal(float new_val) {
	if (abs(new_val - current_val_) > 1.5) k_ = 0.9;
	else k_ = 0.03;
	current_val_ += (new_val - current_val_) * k_;
	return current_val_;
}
