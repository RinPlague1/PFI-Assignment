#pragma once

#include "ServerSocket.h"
#include "ClientSocket.h"

#include "Wsa.h"
#include <iostream>

#include "ClientSocket.h"
#include <winsock2.h>

#include "Timer.h"

//https://medium.com/@tharunappu2004/creating-a-simple-tcp-server-in-c-using-winsock-b75dde86dd39

#ifndef _CLIENT_OBJ_
#define _CLIENT_OBJ_

class Client: Timer
{
	SOCKET m_clientSocket;
	sockaddr_in ClientService;
	bool socketConnect;

public:
	Client();
	~Client();
	void on_tick();

};

#endif