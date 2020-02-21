#ifndef LOGGING_H
#define LOGGING_H

#include <iostream> 
#include <fstream> 
#include <time.h> 
#include <string> 
#include <stdio.h>
#include <chrono>

// debug() functions as cout if DEBUG is defined before FPGA_H
#ifdef DEBUG
#define debug(...) std::cout << "[DEBUG] " << __VA_ARGS__;
// Otherwise debug() does not output to console
#else
#define debug(...)
#endif

class Logger {
public:
	std::ofstream file;
	std::ifstream fileHandle;
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
	std::ofstream::pos_type fileSize;
	std::string date;

	Logger();
	~Logger();

	int getLogSize();

	const std::string currentDateTime();
	int getMin(float store);
	std::string formMin(int min);
	int getSec(float store);
	std::string formSec(int sec);
	std::string getMil(float store);
	std::string getStamp();

	void log(std::string type, int data);
	void log(std::string type, double data);
	void log(std::string type, std::string data);

	void saveLog();
};

#endif
