#pragma once
#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <winsock2.h>
#include <iostream>

struct ServerSocket;

struct ClientSocket
{
	ClientSocket();
	~ClientSocket();
	bool receive(std::string& _message);
	int send(const std::string& _message);

	bool m_closed;

private:
	friend struct ServerSocket;

	

	SOCKET m_socket;

	ClientSocket(const ClientSocket& _copy);
	ClientSocket& operator=(const ClientSocket& _assign);
};

#endif // !CLIENT_SOCKET_H



