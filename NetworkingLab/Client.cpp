#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "Client.h"


Client::Client(Window* _windowPtr) :
	Timer(0.0167f), m_clientSocket()
	, m_window(nullptr)
{
	m_window = _windowPtr;

}

Client::~Client()
{

}



void Client::on_tick()
{
	if (m_clientSocket.m_connected == true)
	{
		//std::cout << "ahhhh";
		std::string receiveBuffer;
		if (m_clientSocket.receive(receiveBuffer))
		{
			std::cout << receiveBuffer << std::endl;
			m_window->addToLog(receiveBuffer);
		}

	}
	
}