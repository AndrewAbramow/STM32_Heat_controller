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

extern TIM_HandleTypeDef htim2;
extern ADC_HandleTypeDef hadc1;
extern unsigned char KeyboardReadFlag;

std::string String2Float(float number);
void MainCpp();

#endif /* INC_CPPMAIN_HPP_ */
