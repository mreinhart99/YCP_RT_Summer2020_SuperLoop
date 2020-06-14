/*
 * This is the header file for the ticker
 */

#ifndef TICKER_H
#define TICKER_H

#include <chrono>

namespace Timer
{
	class Ticker
	{
	protected:
		int _tick_duration; // Tick duration in msec
		int      _max_tick; // Max ticks before max ticks gets back to 0
		int  _current_tick; // Current tick
		bool       _update; // If the tick count has updated
		/* Timers */
		std::chrono::time_point<std::chrono::system_clock> _start;   // Time start
		std::chrono::time_point<std::chrono::system_clock>   _end;   // End
		std::chrono::duration<double> _elapsed;                      // Delta
		/* Calculations */
		void calculate(); // Calculates the stuff
	public:
		Ticker(); // Default constructor
		Ticker(int const& tick_duration, int const& max_tick = 10000); // Creates a timer
		/* Getters */
		int get_tick(); // Returns current tick
		/* Setters */
		void set_tick_duration(int const& d); // Sets tick duration
		void    set_max_tick(int const& max); // Sets max tick 
		/* Methods */
		void start();   // Starts the timer
		void reset();   // Resets the timer
		bool updated(); // If the tick count has changed
	};
};

#endif