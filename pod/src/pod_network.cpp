#define DEBUG

#include "pod_network.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

NetworkConnection::NetworkConnection(int port) {
	this->port = port;
	
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->sockfd == 0) {
		debug("Failed to create socket\n");
	}
	
	this->sockaddr.sin_family = AF_INET;
	this->sockaddr.sin_addr.s_addr = INADDR_ANY;
	this->sockaddr.sin_port = htons(this->port);
	
	if (bind(this->sockfd, (struct sockaddr*)&this->sockaddr, sizeof(this->sockaddr)) < 0) {
		debug("Failed to bind to port 9999\n");
	}
}

void NetworkConnection::netStart() {
	if (listen(this->sockfd, 1) < 0) {
		debug("Failed to listen on socket\n");
	}
	
	auto addrlen = sizeof(this->sockaddr);
	this->connection = accept(this->sockfd, (struct sockaddr*)&this->sockaddr, (socklen_t*)&addrlen);
	if (this->connection < 0) {
		debug("Failed to grab connection\n");
	}
}

std::string NetworkConnection::netRead() {
	auto bytesRead = read(this->connection, this->buffer, 1024);
	this->buffer[bytesRead] = '\0';
	return this->buffer;
}
	
void NetworkConnection::netWrite(std::string data) {	
	send(this->connection, data.c_str(), data.size(), 0);
}
	
void NetworkConnection::netClose() {	
	close(this->connection);
	close(this->sockfd);
}
