// ClientApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    std::cout << "Starting client...\n";

	// Client side step
	// 1. WSAStartup
	// 2. Create socket
	// 3. Setup a SOCKADDR address structure with the name of server you
	//   are going to connect to. For TCP/IP, this is the server's IP
	//   and port number its application it listen on.
	// 4. Initiate the connection with connect or WSAConnect.

	// 1. WSAStartup
	WSADATA wsaData;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
	
	// 2. Create socket
	SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	// 3. Setup server address
	SOCKADDR_IN serverAddress;
	int port = 9900;
	int serverAddr = 
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(port);
	serverAddress.sin_addr.s_addr = inet_addr("192.168.68.207");

	// 4. Initiate the connection with connect or WSAConnect
	connect(clientSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress));

	// 5. Close socket and cleanup winsock
	closesocket(clientSocket);
	WSACleanup();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
