#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include "NiFpga_FPGA.h" 
//#include "NiFpga.c"

// debug() functions as cout if DEBUG is defined before FPGA_H
#ifdef DEBUG
#define debug(...) std::cout << "[DEBUG] " << __VA_ARGS__;
// Otherwise debug() does not output to console
#else
#define debug(...)
#endif

/* Sensor class loads the FPGA C API library, creates an interfacing session,
 * and allows for data to be written to or retrieved from the FPGA.
 * Call <SensorObject>.start() to open the session
 * Session is automatically closed in <SensorObject> destructor
 *
 * NOTE: cRIO must be connected or else the session will fail to open
 */
class Sensor {
	public:		
		NiFpga_Session session;	
		NiFpga_Status status;
		
		Sensor();		
		~Sensor();
		
		void start();
		
		int getAccelX();
		int getAccelY();
		int getAccelZ();
};

#endif
