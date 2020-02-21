#include "pod_network.h"
#include <iostream>

using namespace std;

int main() {
	// Set which port to listen on
	int PORT = 9999;
	
	// Create the socket with the port
	NetworkConnection net = NetworkConnection(PORT);
	
	// Start listening on the socket
	net.netStart();
	
	// Read the incoming message
	cout << "Message: " << net.netRead() << endl;
	
	// Respond with data
	net.netWrite("temperature_1=990");
	
	// Close the socket
	net.netClose(); 
	
	return 0; 
}
