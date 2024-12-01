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

public:
	Server();
	~Server();
	void on_tick();
	void bounceToClients(std::string _message, size_t _ci);
};

#endif