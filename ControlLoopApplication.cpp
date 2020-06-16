
#include <iostream>
#include "Ticker.h"

bool Accel1EventFlag = false;
bool Accel2EventFlag = false;
bool Accel3EventFlag = false;
bool AzimuthEventFlag = false;
bool ElevationEventFlag = false;
bool TempEventFlag = false;


int main()
{
	Timer::Ticker t(1000, 5); // A timer ticking every second. Resets at 5 secconds

	Timer::Ticker Accel1Ticker(1000, 3); // Accelerometer 1 ticker

	Timer::Ticker Accel2Ticker(1000, 5); // Accelerometer 2 ticker

	Timer::Ticker Accel3Ticker(1000, 7); // Accelerometer 3 ticker

	// Start tickers
	t.start(); 

	Accel1Ticker.start();
	Accel2Ticker.start();
	Accel3Ticker.start();

    // This is a super loop that check evnet flags and uses a ticker event to set other event flags
	while (true) {

		if (Accel1Ticker.isMax())
				Accel1EventFlag = true;

		if (Accel2Ticker.isMax())
				Accel2EventFlag = true;

		if (Accel3Ticker.isMax())
				Accel3EventFlag = true;

		
		int NumTicks1 = Accel1Ticker.get_tick();
		int NumTicks2 = Accel2Ticker.get_tick();
		int NumTicks3 = Accel3Ticker.get_tick();
		int NumTicks = t.get_tick();
		if (t.updated()) {
			
			//std::cout << NumTicks << std::endl; // Printing the current tick of the ticker t

			if (NumTicks == 1)
				AzimuthEventFlag = true;

			if (NumTicks == 3)
				ElevationEventFlag = true;

			if (NumTicks == 4)
				TempEventFlag = true;	
		}

		// Are accelerometers ready to be read
		if (Accel1EventFlag) {
			Accel1EventFlag = false;
			std::cout << "Hello World from the Accelerometer 1\n";
		}
		if (Accel2EventFlag) {
			Accel2EventFlag = false;
			std::cout << "Hello World from the Accelerometer 2\n";
		}
		if (Accel3EventFlag) {
			Accel3EventFlag = false;
			std::cout << "Hello World from the Accelerometer 3\n";
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
	return 0;
}
