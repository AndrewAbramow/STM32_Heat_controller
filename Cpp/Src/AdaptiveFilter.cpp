/*
 * DigitalFilter.cpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#include <AdaptiveFilter.hpp>

AdaptiveFilter::AdaptiveFilter() {
	current_val = 0;
	k           = 1;
}

AdaptiveFilter::~AdaptiveFilter() {
	// TODO Auto-generated destructor stub
}

float AdaptiveFilter::RenewVal(float new_val) {
	if (abs(new_val - current_val) > 1.5) k = 0.9;
	else k = 0.03;
	current_val += (new_val - current_val) * k;
	return current_val;
}
