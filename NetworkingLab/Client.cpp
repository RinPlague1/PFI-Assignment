#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "Client.h"


Client::Client():
			Timer(0.0167f)
{
	WSADATA wsaData;
	int wserr;
	WORD wVersionRequested = MAKEWORD(2, 2);
	wserr = WSAStartup(wVersionRequested, &wsaData);

	if (wserr != 0) {
		std::cout << "The winsock dll not found" << std::endl;
	}
	else {
		std::cout << "The Winsock dll found" << std::endl;
		std::cout << "The status: " << wsaData.szSystemStatus << std::endl;
	}

	socketConnect = false;

	m_clientSocket = INVALID_SOCKET;
	m_clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// Check for socket creation success
	if (m_clientSocket == INVALID_SOCKET) {
		std::cout << "Error at socket(): " << WSAGetLastError() << std::endl;
		WSACleanup();
	}
	else {
		std::cout << "Socket is OK!" << std::endl;
	}

	
	ClientService.sin_family = AF_INET;
	ClientService.sin_addr.s_addr = inet_addr("127.0.0.1");
	ClientService.sin_port = htons(8080);

	if (connect(m_clientSocket, reinterpret_cast<SOCKADDR*>(&ClientService), sizeof(ClientService)) == SOCKET_ERROR) 
	{
		std::cout << "Client: connect - Failed to connect: " << WSAGetLastError() << std::endl;
		WSACleanup();
		
	}
	else 
	{

		std::cout << "Client: Connect is OK!" << std::endl;
		std::cout << "Client: Can start sending and receiving data..." << std::endl;
		socketConnect = true;

	}
}

Client::~Client()
{

}


void Client::on_tick()
{
	if (socketConnect == true)
	{

		char buffer[200];
		std::cout << "Enter the message: ";
		std::cin.getline(buffer, 200);
		int sbyteCount = send(m_clientSocket, buffer, 200, 0);
		if (sbyteCount == SOCKET_ERROR) {
			std::cout << "Client send error: " << WSAGetLastError() << std::endl;
		}
		else {
			std::cout << "Client: Sent " << sbyteCount << " bytes" << std::endl;
		}

		// Receiving data from the server
		char receiveBuffer[200];
		int rbyteCount = recv(m_clientSocket, receiveBuffer, 200, 0);
		if (rbyteCount < 0) {
			std::cout << "Client recv error: " << WSAGetLastError() << std::endl;

		}
		else {
			std::cout << "Client: Received data: " << receiveBuffer << std::endl;
		}
	}
	else
	{
		ClientService.sin_family = AF_INET;
		ClientService.sin_addr.s_addr = inet_addr("127.0.0.1");
		ClientService.sin_port = htons(3243);

		if (connect(m_clientSocket, reinterpret_cast<SOCKADDR*>(&ClientService), sizeof(ClientService)) == SOCKET_ERROR)
		{
			std::cout << "Client: connect - Failed to connect: " << WSAGetLastError() << std::endl;
			WSACleanup();

		}
		else
		{

			std::cout << "Client: Connect is OK!" << std::endl;
			std::cout << "Client: Can start sending and receiving data..." << std::endl;
			socketConnect = true;

		}
	}


}