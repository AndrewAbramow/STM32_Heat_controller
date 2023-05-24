/*
 * PIDRegulaor.cpp
 *
 *  Created on: May 15, 2023
 *      Author: abramov.a
 */

#include "PIDRegulaor.hpp"

PID_Regulaor::PID_Regulaor() {
	// TODO Auto-generated constructor stub

}

PID_Regulaor::~PID_Regulaor() {
	// TODO Auto-generated destructor stub
}

float PID_Regulaor::Clamp(float value, float min, float max)
{
  return (value < min)? min : (value > max)? max : value;
}

void PID_Regulaor::TemperatureSupport(float input)
{
	 float err = setpoint - input;

	 integral = Clamp(integral + (float)err * dt * ki, minOut, maxOut);

	 float D = (err - prevErr) / dt;
	 prevErr = err;

	 return constrain(err * kp + integral + D * kd, minOut, maxOut);
}
