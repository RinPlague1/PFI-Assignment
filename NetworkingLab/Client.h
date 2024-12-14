#pragma once

#include "ServerSocket.h"
#include "ClientSocket.h"

#include<FL/fl_ask.H>

#include "Wsa.h"
#include "Window.h"
#include <iostream>
#include <stdexcept>

#include "ClientSocket.h"
#include <winsock2.h>

#include "Timer.h"

//https://medium.com/@tharunappu2004/creating-a-simple-tcp-server-in-c-using-winsock-b75dde86dd39

#ifndef _CLIENT_OBJ_
#define _CLIENT_OBJ_

class Window;

class Client: Timer
{
	friend class Window;
	ClientSocket m_clientSocket;
	bool socketConnect;

	Window* m_window;

public:
	Client(Window* _windowPtr);
	~Client();
	void on_tick();
	

};

#endif