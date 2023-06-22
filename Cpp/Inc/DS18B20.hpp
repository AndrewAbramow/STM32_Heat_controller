#ifndef INC_DS18B20_HPP_
#define INC_DS18B20_HPP_

#include <stdint.h>

#include "stm32f1xx_hal.h"

#include "Timing.hpp"

class DS18B20
{
 public:
	        DS18B20(TIMER *tim);
  float     readTemperature();
 private:
	//PIN CONFIG AND SETTING
  void      setDataPin(bool on);
  void      toggleDataPin();
  void      setPinOUTPUT();
  void      setPinINPUT();
	//INTERFACING FUNCTIONS
  void      startSensor();
  void      writeData(uint8_t data);
  uint8_t   readData();
  TIMER * _tim;
};
#endif /* INC_DS18B20_HPP_ */
