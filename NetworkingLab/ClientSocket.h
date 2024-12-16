#pragma once
#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <winsock2.h>
#include <iostream>
#include <FL/fl_ask.H>
#include "Message.h"; 

struct ServerSocket;
class Client;
struct Message;

struct ClientSocket
{
	ClientSocket();
	~ClientSocket();
	bool receive(std::string& _message);
	int send(const std::string& _message);
	SOCKET getSocket();
	bool m_closed;
	bool connectFunction(std::string _ipInput);

	void setUsername(std::string _username);
	void setLegion(std::string _legion);

	std::string getUsername();
	std::string getLegion();


private:
	friend struct ServerSocket;
	friend class Client;
	friend struct Message;

	SOCKET m_socket;
	std::string m_username;
	std::string m_legion;
	bool m_connected;


	void nonBlocking();
	ClientSocket(const ClientSocket& _copy);
	ClientSocket& operator=(const ClientSocket& _assign);


	
};

#endif // !CLIENT_SOCKET_H

