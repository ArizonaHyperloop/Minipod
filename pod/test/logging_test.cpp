#define DEBUG

#include <iostream>
#include "logging.h"

using namespace std;

// Testing implementation of Logger class

int main() {
	Logger logger;

	// logger.log(<any_string_var>, <any_int/double/string_var>);		// Writes a description and a value to the log file
	// logger.getLogSize();		// Prints log size in bytes, returns int

	string typeTest = "Test";
	int test = 15;
	logger.log(typeTest, test);
	double test2 = 83.9765;
	logger.log("Information", test2);

	for (int i = 0; i < 10; i++) {
		int y = 0; y++;
		for (int x = 0; x < 400000; x++) {
			//just takes up time to test timestamp
			logger.log("12345", 67890);
			y = 0; y++;
		}
	}

	for (int i = 0; i < 100; i++) {
		logger.log("12345", 67890);
	}

	string test3 = "The state is...";
	logger.log("State", test3);

	logger.getLogSize();

	return 0;
}
