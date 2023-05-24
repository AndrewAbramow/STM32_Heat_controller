/*
 * PIDRegulaor.hpp
 *
 *  Created on: May 15, 2023
 *      Author: abramov.a
 */

#ifndef SRC_PIDREGULAOR_HPP_
#define SRC_PIDREGULAOR_HPP_

// https://alexgyver.ru/lessons/pid/

class PID_Regulaor {
public:
	PID_Regulaor();
	virtual ~PID_Regulaor();
	void TemperatureSupport(float input);
	float Clamp(float value, float min, float max);

private:
	int dt = 0;
	int minOut = 0;
	int maxOut = 0;

	float kp = 1;
	float ki = 1;
	float kd = 1;

	float setpoint;

	float integral = 0;
	float prevErr = 0;

};

#endif /* SRC_PIDREGULAOR_HPP_ */
