#include "sensor.h"

// Sensor constructor loads the FPGA C Library
Sensor::Sensor() {
	debug("FPGA: Created session...\n");
	status = NiFpga_Initialize();	
	debug("FPGA: Loaded C API library...\n");
}

// Sensor destructor closes the FPGA session
Sensor::~Sensor() {
	NiFpga_MergeStatus(&status, NiFpga_Close(session, 0));
	debug("FPGA: Session closed...\n");
}

// start opens the FPGA session using the dependencies contained in
// the fpga_lib directory. 
void Sensor::start() {
	NiFpga_MergeStatus(&status, NiFpga_Open("NiFpga_FPGA.lvbitx",
											NiFpga_FPGA_Signature,
											"RIO://172.22.11.2/RIO0",
											0,
											&session));
	
	// Always print the error when the session fails to load										
	if (NiFpga_IsError(status)) {
		std::cout << "FPGA: Failed to open session, Error = " << status << std::endl;
	}
	else{
		debug("FPGA: Opened session...\n");
	}
}

int Sensor::getAccelX() {
	short int accelX;

	NiFpga_MergeStatus(&status, NiFpga_ReadI16(session,
											NiFpga_FPGA_IndicatorI16_AccelerationX,
											  &accelX));		  
											  
	return accelX;
	} 
		
int Sensor::getAccelY() {
	short int accelY;

	NiFpga_MergeStatus(&status, NiFpga_ReadI16(session,
											  NiFpga_FPGA_IndicatorI16_AccelerationY,
											  &accelY));		  
											  
	return accelY;
} 
		
int Sensor::getAccelZ() {
	short int accelZ;

	NiFpga_MergeStatus(&status, NiFpga_ReadI16(session,
											  NiFpga_FPGA_IndicatorI16_AccelerationZ,
											  &accelZ));		  
											  
	return accelZ;
} 

