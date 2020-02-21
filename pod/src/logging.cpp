
#include <iostream> 
#include <fstream> 
#include <time.h> 
#include <string> 
#include <stdio.h>
#include <chrono>

#include "logging.h"

// type denotes a string describing what is being logged, data denotes the actual values being logged.
Logger::Logger() { // Constructor
	start = std::chrono::high_resolution_clock::now();
	date = currentDateTime();
	fileHandle.open("logs/" + date + ".txt", std::ios::app);
	file.open("logs/" + date + ".txt", std::ios::app);

}
Logger::~Logger() { // Destructor
	file.close();
	fileHandle.close();
}

int Logger::getLogSize() {
	saveLog();

	std::ifstream fileHandle("logs/" + date + ".txt", std::ios::binary | std::ios::ate);
	int fileSize = fileHandle.tellg();

	if (fileHandle.is_open())
		file << fileSize << " bytes" << "\n";
	debug("Logged: " << fileSize << " bytes" << std::endl);
	return fileSize;
}

const std::string Logger::currentDateTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%y-%m-%d-%H_%M_%S", &tstruct);

	return buf;
}

int Logger::getMin(float store) {				// Formats chrono minutes
	int min = store / 60;
	return min;
}

std::string Logger::formMin(int min) {			// Formats minutes to string
	std::string minStr = std::to_string(min);
	if (minStr.length() < 2) {
		minStr = "0" + minStr;
	}
	return minStr;
}

int Logger::getSec(float store) {				// Formats chrono seconds
	int sec = (store / 1) - (getMin(store) * 60);
	return sec;
}

std::string Logger::formSec(int sec) {				// Formats seconds to string
	std::string secStr = std::to_string(sec);
	if (secStr.length() < 2) {
		secStr = "0" + secStr;
	}
	return secStr;
}

std::string Logger::getMil(float store) {		// Formats chrono milliseconds
	float millFull = store;									// Correctly this time
	std::string millStr = std::to_string(millFull);
	std::size_t decimal = millStr.find(".");
	std::string mill = millStr.substr(decimal+1, 3);
	return mill;
}

std::string Logger::getStamp() {
	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> stamp = stop - start;
	float store = stamp.count();
	std::string format = "[" + formMin(getMin(store)) + ":" + formSec(getSec(store)) + "." + getMil(store) + "]: ";

	return format;
}

void Logger::log(std::string type, int data) { // Output

	if (fileHandle.is_open())
		file << getStamp() << type << ": " << data << "\n";
	debug("Logged: " << getStamp() << type << ": " << data << std::endl);
}

void Logger::log(std::string type, double data) {

	if (fileHandle.is_open())
		file << getStamp() << type << ": " << data << "\n";
	debug("Logged: " << getStamp() << type << ": " << data << std::endl);
}

void Logger::log(std::string type, std::string data) {

	if (fileHandle.is_open())
		file << getStamp() << type << ": " << data << "\n";
	debug("Logged: " << getStamp() << type << ": " << data << std::endl);
}

// saveLog forces all data in write buffer to be immediately written
// If not periodically called, some data may be lost if the program
// crashes before completion 
void Logger::saveLog() {
	file.flush();
}
