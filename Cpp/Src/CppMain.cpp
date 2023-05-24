#include "CppMain.hpp"


// Main Cpp event loop to run application
void CppMain()
{
	//OnOffRegulator regulator(20,1);
	TM1637 display;
	TIMER timing = TIMER(&htim2);
	DS18B20 temp = DS18B20(&timing);
	std::string s {"6667"};
	//DS18B20 thermometer(&htim2);
	//PID_Regulator reg ();


	while(true)
	{
		if (KeyboardReadFlag == 1)
		{
			// Temperature support
			//regulator.TemperatureSupport(HEATER);
			//currentTemperature = regulator.GetTemperature();
			float t = temp.readTemperature();

			uint8_t whole = t;
			char wholeD = whole/10 + 48;
			char wholeU = whole%10 + 48;

			uint8_t fract = (t - whole)*100;
			char fractD = fract/10 + 48;
			char fractU = fract%10 + 48;

			s = wholeD;
			s.push_back(wholeU);
			s.push_back(fractD);
			s.push_back(fractU);

			// show temperature on display
			//display.DisplayClear();
			//auto currentTemp = thermometer.readTemperature();
			KeyboardReadFlag = 0;

			// Count the number of CP ticks
			//reg.TemperatureSupport(t);
		}
		else
		{
			display.DisplayHandle(5, s);
		}
	}
}


