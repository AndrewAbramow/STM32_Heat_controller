#include "CppMain.hpp"


// Main Cpp event loop to run application
void CppMain()
{
	OnOffRegulator regulator(20,1);

	while(true)
	{
		//if (timerFlag == 1)
		{
			regulator.TemperatureSupport(HEATER);
		}
	}
}


