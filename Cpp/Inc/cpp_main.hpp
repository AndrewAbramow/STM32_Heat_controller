/*
 * CppMain.h
 *
 *  Created on: Mar 20, 2023
 *      Author: abramov.a
 */

#ifndef INC_CPPMAIN_HPP_
#define INC_CPPMAIN_HPP_

#include "main.h"

#include <string>

#include "adaptive_filter.hpp"
#include "ds18b20.hpp"
#include "on_off_regulator.hpp"
#include "relay_output.hpp"
#include "tm1637.hpp"
#include "pid_regulator.hpp"
#include "timing.hpp"

extern unsigned char KeyboardReadFlag;
extern TIM_HandleTypeDef htim2;

std::string String2Float(float number);
void MainCpp();

#endif /* INC_CPPMAIN_HPP_ */
