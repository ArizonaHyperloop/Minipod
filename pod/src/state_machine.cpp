/* System includes */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

/* Pod includes */
#include "logging.h"
#include "sensor.h"
#include "pod_network.h"

using namespace std;

/* Use function pointer to keep track of current state */
void (*currentState)();
std::string currentStateName;

void state_machine();
void state_idle();
void state_safety_checks();
void state_ready_to_launch();
void state_launching();
void state_flight();
void state_coasting();
void state_braking();
void state_shutdown();
void state_end_of_run();

Logger logger;
Sensor sensor;
NetworkConnection network(3962);

int main()
{
    currentState = &state_idle;
    state_machine();
    return 0;
}

void state_machine() {	
    while (true) {
        currentState();
        
        if (currentState == state_end_of_run) {
        	return;
		}
        
        usleep(100000);
    }
}

void state_idle() {
    currentStateName = "Idle";
    cout << "Running State: " << currentStateName << endl;
    
    //sensor.start();
    
    currentState = &state_safety_checks;
}

void state_safety_checks() {
    currentStateName = "Safety Checks";
    cout << "Running State: " << currentStateName << endl;
    
    //logger.log("AccelX" , sensor.getAccelX());
    //logger.log("AccelY" , sensor.getAccelY());
    //logger.log("AccelZ" , sensor.getAccelZ());
    //logger.saveLog();
    
    currentState = &state_ready_to_launch;
}

void state_ready_to_launch() {
    currentStateName = "Ready To Launch";
    cout << "Running State: " << currentStateName << endl;
    
    currentState = &state_launching;
}

void state_launching() {
    currentStateName = "Launching";
    cout << "Running State: " << currentStateName << endl;
    
    currentState = &state_launching;
}

void state_flight() {
	/* Not yet implemented */
}

void state_coasting() {
	/* Not yet implemented */
}

void state_braking() {
	/* Not yet implemented */
}

void state_shutdown() {
	/* Not yet implemented */
}

void state_end_of_run() {
	/* Not yet implemented */
}










