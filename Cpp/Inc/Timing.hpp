#pragma once
#include <stdint.h>
#include "stm32f1xx_hal.h"

class TIMER {
 public:
  TIMER(TIM_HandleTypeDef* tim);
  void delayUS(uint16_t us);
 private:
  TIM_HandleTypeDef* _tim;
};

/*Now, let’s start the cubeIDE, and open the clock setup tab.
Here you can see that, once I set the HCLK at MAX i.e. 72MHz, the APB2 clock is also at 72MHz.

This means that the TIMER 1 is also running at 72MHz, as the TIM1 is connected to the APB2.
Now, let’s reduce this frequency in the timer setup section.

First of all, set the clock source as internal clock.
Prescaler divides the Timer clock further, by the value that you input in the prescaler.
As we want the delay of 1 microsecond, the timer frequency must be (1/(1 us)), i.e 1 MHz.
And for this reason, the prescaler value is 72.
Note that it’s 72-1, because the prescaler will add 1 to any value that you input there.
The ARR I am setting is the max value it can have.
Basically, the counter is going to count from 0 to this value. Every count will take 1 us.
So setting this value as high as possible is the best, because this way you can have large
delays also.
I have set it to 0xffff-1, and it is the maximum value that a 16 bit register (ARR) can have.
I have also enabled the pin PA1 as output, so that we can see the result in an oscilloscope.
*/
