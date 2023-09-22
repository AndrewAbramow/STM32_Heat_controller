#include "cpp_main.hpp"

#include "adaptive_filter.hpp"
#include "ds18b20.hpp"
#include "on_off_regulator.hpp"
#include "relay_output.hpp"
#include "tm1637.hpp"
#include "pid_regulator.hpp"
#include "timing.hpp"
#include "ntc.hpp"


// Main Cpp event loop to run application
void CppMain()
{
	// initialize custom timer for temp sensor
	TIMER timing = TIMER(&htim2);
	// initialize ds18b20 temp sensor
	std::shared_ptr<DS18B20> temp = std::make_shared<DS18B20>(&timing);
	// initialize ntc temp sensor
	std::shared_ptr<NTC> ntc = std::make_shared<NTC>();
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
	//PID_Regulator regulator(35, 10, filter, temp, relay);

	while(true)
	{
		if (KeyboardReadFlag == 1)
		{
			// Temperature support
			//regulator.TemperatureSupport(HEATER);
			//currentTemperature = regulator.GetTemperature();
			/*
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
			*/
			// get ntc raw data
			uint16_t raw_ntc = ntc->ReadAnalogNTC(hadc1);
			float ntc_temp = ntc->NTC_Compute();

			// correct temperature
			//regulator.TemperatureSupport(t);

			//auto currentTemp = thermometer.readTemperature();
			KeyboardReadFlag = 0;

			// Count the number of CP ticks
			//reg.TemperatureSupport(t);
		}
	}
}


