#include "cpp_main.hpp"


// Main Cpp event loop to run application
void CppMain()
{
	// initialize custom timer for temp sensor
	TIMER timing = TIMER(&htim2);
	// initialize temp sensor
	std::shared_ptr<DS18B20> temp = std::make_shared<DS18B20>(&timing);
	//DS18B20 temp = DS18B20(&timing);
	// initialize display
	TM1637 display;
	display.Initialize(0);
	std::string temperature_str {"none"};
	//initialize filter
	std::shared_ptr<AdaptiveFilter> filter = std::make_shared<AdaptiveFilter>();
	// initialize relay output device
	std::shared_ptr<RelayOutput> relay = std::make_shared<RelayOutput>();
	// initialize controller
	//OnOffRegulator regulator(30, 1, filter, temp, relay);
	PID_Regulator regulator(40, 7, filter, temp, relay);


	while(true)
	{
		if (KeyboardReadFlag == 1)
		{
			// Temperature support
			//regulator.TemperatureSupport(HEATER);
			//currentTemperature = regulator.GetTemperature();
			float t = temp->readTemperature();

			uint8_t whole = t;
			char wholeD = whole/10 + 48;
			char wholeU = whole%10 + 48;

			uint8_t fract = (t - whole)*100;
			char fractD = fract/10 + 48;
			char fractU = fract%10 + 48;

			temperature_str = wholeD;
			temperature_str.push_back(wholeU);
			temperature_str.push_back(fractD);
			temperature_str.push_back(fractU);

			// show temperature on display
			display.DisplayClear();
			display.DisplayHandle(6, temperature_str);

			// correct temperature
			regulator.TemperatureSupport(t);

			//auto currentTemp = thermometer.readTemperature();
			KeyboardReadFlag = 0;

			// Count the number of CP ticks
			//reg.TemperatureSupport(t);
		}
	}
}


