#define DEBUG //Define DEBUG to enable debug outputs

#include "sensor.h"
#include <iostream>
#include <iomanip>

// Testing implementation of the Sensor class

using namespace std;

int main() {
	// Create Sensor ojbect, which loads the FPGA C API libraries
	Sensor sensor;
	// Start the FPGA session
	sensor.start();
	
	// Example of how to read a value from the FPGA session
	int accelX, accelY, accelZ;
	accelX = sensor.getAccelX();
	accelY = sensor.getAccelY();
	accelZ = sensor.getAccelZ();
	
	// Format cout to print 2 decimal places
	cout << "X Accel: " << fixed << setprecision(2) << accelX << endl;
	cout << "Y Accel: " << fixed << setprecision(2) << accelY << endl;
	cout << "Z Accel: " << fixed << setprecision(2) << accelZ << endl;
		
	// The FPGA session is automatically closed when sensor deconstructs  	
	cout << "Exiting..." << endl;
	return 0;
}
