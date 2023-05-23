/*
 * CppMain.h
 *
 *  Created on: Mar 20, 2023
 *      Author: abramov.a
 */

#ifndef INC_CPPMAIN_HPP_
#define INC_CPPMAIN_HPP_

#include "main.h"
#include "OnOffRegulator.hpp"
#include "TM1637.hpp"
#include <string>

extern unsigned char KeyboardReadFlag;
extern TIM_HandleTypeDef htim2;

std::string String2Float(float number);
void MainCpp();

#endif /* INC_CPPMAIN_HPP_ */
