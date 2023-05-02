/*
 * DigitalFilter.cpp
 *
 *  Created on: May 2, 2023
 *      Author: abramov.a
 */

#include <AdaptiveFilter.hpp>

AdaptiveFilter::AdaptiveFilter() {
	currentVal = 0;
	k = 1;
}

AdaptiveFilter::~AdaptiveFilter() {
	// TODO Auto-generated destructor stub
}

float AdaptiveFilter::RenewVal(float newVal)
{
	if (abs(newVal - currentVal) > 1.5) k = 0.9;
	else k = 0.03;

	currentVal += (newVal - currentVal) * k;
	return currentVal;
}
