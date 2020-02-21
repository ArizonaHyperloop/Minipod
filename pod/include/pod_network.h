#ifndef PODNETWORK_H
#define PODNETWORK_H

#include <iostream>
#include <netinet/in.h>

// debug() functions as cout if DEBUG is defined before FPGA_H
#ifdef DEBUG
#define debug(...) std::cout << "[DEBUG] " << __VA_ARGS__;
// Otherwise debug() does not output to console
#else
#define debug(...)
#endif

// NetworkConnection class declaration
class NetworkConnection {
	public:
		int sockfd, port, connection;
		sockaddr_in sockaddr;
		char buffer[1024];
			
		NetworkConnection(int port);
		void netStart();
		std::string netRead();
		void netWrite(std::string data);
		void netClose();
};

#endif
