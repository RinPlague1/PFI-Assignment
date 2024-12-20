#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "ClientSocket.h"
#include "ServerSocket.h"
#include <iostream>

ClientSocket::ClientSocket()
	: m_socket(INVALID_SOCKET)	//assigns all the standard user data to the socket
	, m_closed(false)
	, m_username("�")
	, m_legion("1")
	, m_connected(false)

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

	//socketConnect = false;

	m_socket = INVALID_SOCKET;
	m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// Check for socket creation success
	if (m_socket == INVALID_SOCKET) {
		std::cout << "Error at socket(): " << WSAGetLastError() << std::endl;
		WSACleanup();
	}
	else {
		std::cout << "client Socket is OK!" << std::endl;

	}

}

ClientSocket::~ClientSocket()
{
	if (m_socket != INVALID_SOCKET)
	{
		closesocket(m_socket);	//closes socket when disconnected
	}
}


void ClientSocket::nonBlocking()
{
	u_long mode = 1;	//sets nonBlocking
	if (ioctlsocket(m_socket, FIONBIO, &mode) == SOCKET_ERROR)
	{
		throw std::runtime_error("Failed to set non-blocking");
	}
}


bool ClientSocket::receive(std::string& _message)
{
	char buffer[512] = { 0 };
	int bytes = ::recv(m_socket, buffer, sizeof(buffer) - 1, 0);	//general recieve function from winsock
	if (bytes == SOCKET_ERROR)
	{
		if (WSAGetLastError() != WSAEWOULDBLOCK)
		{
			throw std::runtime_error("Read failed");
		}
		return false;
	}
	else if (bytes == 0)
	{
		m_closed = true;
		return false;
	}
	_message = buffer;
	return true;
}

int ClientSocket::send(const std::string& _message)
{
	//std::string encryptedMessage = rot13Encryption(_message);
	// ^ rot 13 encryption call


	int bytes = ::send(m_socket, _message.c_str(), _message.length(), 0);
	if (bytes <= 0)
	{
		throw std::runtime_error("Failed to send data");
	}
	return bytes;
}

SOCKET ClientSocket::getSocket()
{
	return m_socket;
}

bool ClientSocket::connectFunction(std::string _ipInput)
{
	std::cout << _ipInput << " : ip entered" << std::endl;
	sockaddr_in ClientService;
	ClientService.sin_family = AF_INET;
	ClientService.sin_addr.s_addr = inet_addr(_ipInput.c_str());
	ClientService.sin_port = htons(8080);

	//searches for the ip entered on the given port

	if (connect(m_socket, reinterpret_cast<SOCKADDR*>(&ClientService), sizeof(ClientService)) == SOCKET_ERROR)
	{
		std::cout << "Client: connect - Failed to connect: " << WSAGetLastError() << std::endl;
		fl_alert("Invalid IP");
		m_connected = false;
		return false;	//checks if connected then doesnt allow the connected loop to run for the client
	}
	else
	{
		std::cout << "Client: Connect is OK!" << std::endl;
		std::cout << "Client: Can start sending and receiving data..." << std::endl;

		nonBlocking();

		m_connected = true;	//allows the connected loop to run
		return true;

	}

}

void ClientSocket::setUsername(std::string _username)
{
	m_username = _username;
}

std::string ClientSocket::getUsername()
{
	return m_username;
}

void ClientSocket::setLegion(std::string _legion)
{
	m_legion = _legion;
}


std::string ClientSocket::getLegion()
{
	return m_legion;
}

//std::string ClientSocket::rot13Encryption(std::string _sendingMessage)
//{
//	std::string encrypted;
//	for (int i = 0; i < _sendingMessage.length(); i++)
//	{
//		char decryptedChar = int(_sendingMessage[i]) + 13;
//
//		if (decryptedChar > 90)
//		{
//			decryptedChar = 65 + (int(decryptedChar) - 90);
//		}
//
//		if (decryptedChar > 122)
//		{
//			decryptedChar = 97 + (int(decryptedChar) - 122);
//		}
//
//		if (decryptedChar == 167)
//		{
//			decryptedChar = 167;
//		}
//
//		encrypted = encrypted + decryptedChar;
//	}
//
//	std::cout<< "encrypted text: " << encrypted << std::endl;
//
//	return encrypted;
//}

// ^ attempt at rot13 encryption