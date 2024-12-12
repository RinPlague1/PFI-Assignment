#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "Client.h"


Client::Client() :
	Timer(0.0167f), m_clientSocket()
{
	//WSADATA wsaData;
	//int wserr;
	//WORD wVersionRequested = MAKEWORD(2, 2);
	//wserr = WSAStartup(wVersionRequested, &wsaData);

	//if (wserr != 0) {
	//	std::cout << "The winsock dll not found" << std::endl;
	//}
	//else {
	//	std::cout << "The Winsock dll found" << std::endl;
	//	std::cout << "The status: " << wsaData.szSystemStatus << std::endl;
	//}

	//socketConnect = false;

	//m_clientSocket = INVALID_SOCKET;
	//m_clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//// Check for socket creation success
	//if (m_clientSocket == INVALID_SOCKET) {
	//	std::cout << "Error at socket(): " << WSAGetLastError() << std::endl;
	//	WSACleanup();
	//}
	//else {
	//	std::cout << "client Socket is OK!" << std::endl;
	//	
	//}

	/*u_long mode = 1;
	if (ioctlsocket(m_clientSocket, FIONBIO, &mode) == SOCKET_ERROR)
	{
		throw std::runtime_error("Failed to set non-blocking");
	}*/

}

Client::~Client()
{

}



void Client::on_tick()
{

	
}