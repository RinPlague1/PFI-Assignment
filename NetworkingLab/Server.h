#pragma once

#include "Timer.h"
#include "Wsa.h"
#include <iostream>
#include <vector>
#include "ServerSocket.h"


#ifndef _SERVER_OBJ_
#define _SERVER_OBJ_
class Server : Timer
{
	Wsa wsa;
	ServerSocket server;
	std::vector<std::shared_ptr<ClientSocket>> clients;
	Message m_newMessage;
public:
	Server();
	~Server();
	void on_tick();
	void sendServerVer(std::shared_ptr<ClientSocket> _client);
	void recievedMessage(std::string _latestMessage);
	void bounceToClients(std::string _message, size_t _ci);
	
};

#endif