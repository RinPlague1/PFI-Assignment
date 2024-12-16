#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "Client.h"


Client::Client(Window* _windowPtr) :
	Timer(0.0167f), m_clientSocket()
	, m_window(nullptr)		// initialises the ontick timer, socket, window
{
	m_window = _windowPtr;	//allocates the main window to the pointer

}

Client::~Client()
{

}

void Client::on_tick()
{
	//std::cout << "tick";
	if (m_clientSocket.m_connected == true)
	{
		std::string receiveBuffer;
		if (m_clientSocket.receive(receiveBuffer))	//client socket recieves data run the recieve loop below
		{
			std::cout << receiveBuffer << std::endl;

					
//			std::string decryptedMessage = rot13Decryption(receiveBuffer);
			m_window->addToLog(receiveBuffer);	//sends message to window
						
		}

	}
	
}

//std::string Client::rot13Decryption(std::string _recievedMessage)
//{
//	std::string decrypted;
//	for (int i = 0; i < _recievedMessage.length(); i++)
//	{
//		char decryptedChar = int(_recievedMessage[i]) - 13;
//
//		if (decryptedChar < 65)
//		{
//			decryptedChar = 90 - (65 - int(decryptedChar));
//		}
//
//		if (decryptedChar < 97)
//		{
//			decryptedChar = 122 - (97 - int(decryptedChar));
//		}
//
//		if (decryptedChar == 167)
//		{
//			decryptedChar = 167;
//		}
//
//		decrypted = decrypted + decryptedChar;
//	}
//
//	std::cout << "decrypted text: " << decrypted << std::endl;
//
//	return decrypted;
//}

//^ attempted rot 13 encryption