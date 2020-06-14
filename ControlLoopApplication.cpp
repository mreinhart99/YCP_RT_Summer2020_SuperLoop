
#include <iostream>
#include "Ticker.h"

bool AccelEventFlag = false;
bool AzimuthEventFlag = false;
bool ElevationEventFlag = false;
bool TempEventFlag = false;


int main()
{
	Timer::Ticker t(1000); // A timer ticking every second

	t.set_max_tick(30); // Set ticker to reset at 30 secconds

	t.start(); // Start ticker

    // This is a super loop that check evnet flags and uses a ticker event to set other event flags
	while (true) {

		int NumTicks = t.get_tick();
		if (t.updated()) {
			
			std::cout << NumTicks << std::endl; // Printing the current tick

			if (NumTicks == 1)
				AccelEventFlag = true;

			if (NumTicks == 10)
				AzimuthEventFlag = true;

			if (NumTicks == 15)
				ElevationEventFlag = true;

			if (NumTicks == 25)
				TempEventFlag = true;

			// Are accelerometers ready to be read
			if (AccelEventFlag) {
				AccelEventFlag = false;
				std::cout << "Hello World from the Accelerometers\n";
			}

			// Is aximuth encoder ready to be read
			if (AzimuthEventFlag) {
				AzimuthEventFlag = false;
				std::cout << "Hello World from the Aximuth Encoder\n";
			}

			// Is elevation encoder ready to be read
			if (ElevationEventFlag) {
				ElevationEventFlag = false;
				std::cout << "Hello World from the Elevation Encoder\n";
			}

			// Are temps ready to be read
			if (TempEventFlag) {
				TempEventFlag = false;
				std::cout << "Hello World from the Temperature Sensors\n";
			}
		}
	}
	return 0;
}
