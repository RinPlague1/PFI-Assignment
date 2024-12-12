#pragma once
#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <winsock2.h>
#include <iostream>
#include <FL/fl_ask.H>

struct ServerSocket;

struct ClientSocket
{
	ClientSocket();
	~ClientSocket();
	bool receive(std::string& _message);
	int send(const std::string& _message);
	SOCKET getSocket();
	bool m_closed;
	bool connectFunction(std::string _ipInput);


private:
	friend struct ServerSocket;

	SOCKET m_socket;
	
	void nonBlocking();
	ClientSocket(const ClientSocket& _copy);
	ClientSocket& operator=(const ClientSocket& _assign);
};

#endif // !CLIENT_SOCKET_H



