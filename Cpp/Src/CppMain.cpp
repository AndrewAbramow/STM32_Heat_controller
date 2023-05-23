#include "CppMain.hpp"
#include "Timing.hpp"
#include "DS18B20.hpp"

// Main Cpp event loop to run application
void CppMain()
{
	//OnOffRegulator regulator(20,1);
	TM1637 display;
	//std::string testString {"6666"};
	//float currentTemperature = 0.0f;
	TIMER timing = TIMER(&htim2);
	DS18B20 temp = DS18B20(&timing);
	std::string s {"6667"};
	//DS18B20 thermometer(&htim2);


	while(true)
	{
		if (KeyboardReadFlag == 1)
		{
			// Temperature support
			//regulator.TemperatureSupport(HEATER);
			//currentTemperature = regulator.GetTemperature();
			float t = temp.readTemperature();
			int dec = t/10;
			int unit = t - dec*10;
			char d = dec + 48;
			char u = unit + 48;
			s = d;
			s.push_back(u);
			//s = std::to_string(t);//.substr(0, s.find(".")+2);

			// show temperature on display
			//display.DisplayClear();
			//auto currentTemp = thermometer.readTemperature();
			KeyboardReadFlag = 0;
		}
		else
		{
			display.DisplayHandle(5, s);
		}
	}
}


