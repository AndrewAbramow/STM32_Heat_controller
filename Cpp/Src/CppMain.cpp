#include "CppMain.hpp"


// Main Cpp event loop to run application
void CppMain()
{
	OnOffRegulator regulator(20,1);
	TM1637 display;
	std::string testString {"1234"};
	float currentTemperature = 0.0f;

	while(true)
	{
		//if (timerFlag == 1)
		{
			// Temperature support
			regulator.TemperatureSupport(HEATER);
			currentTemperature = regulator.GetTemperature();
			std::string s = std::to_string(currentTemperature).substr(0, s.find(".")+3);

			// show temperature on display
			display.DisplayHandle(7, s);
		}
	}
}


