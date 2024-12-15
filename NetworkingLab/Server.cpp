#include "Server.h"

Server::Server():
			Timer(0.0167f)
	, server(8080)
	, m_newMessage("","","")
{

}

Server::~Server()
{

}

void Server::on_tick()
{
	/*;
	printf("Initialized Winsock\n");

	ServerSocket server(8080);
	printf("Server listening on port 8080\n");*/

	
	//std::cout << "tick";
	std::shared_ptr<ClientSocket> client = server.accept();
	if (client)
	{
		printf("Client Connected!\n");
		sendServerVer(client);
		clients.push_back(client);
	}


	// Handle all clients
	for (size_t ci = 0; ci < clients.size(); ++ci)
	{
		std::string message;
		while (clients.at(ci)->receive(message))
		{
			printf("Message recived: %s\n", message.c_str());

			recievedMessage(message);

			std::cout << "bounce to clients from: " << ci;

			bounceToClients(message, ci);
		}
		if (clients.at(ci)->m_closed)
		{
			printf("Client Disconnected\n");
			clients.erase(clients.begin() + ci);
			--ci;
		}
	}
}

void Server::sendServerVer(std::shared_ptr<ClientSocket> _client)
{
		
	_client->send("Server Version: V8.601.1");
}

void Server::recievedMessage(std::string _latestMessage)
{
	std::string nullKey("§");
	std::size_t usernameSection = _latestMessage.find(nullKey);
	std::size_t legionSection = _latestMessage.find(nullKey, usernameSection + 1);

	std::cout << "whole message: " << _latestMessage << std::endl;

	std::string usernameData;

	for (int i = 0; i < usernameSection; i++)
	{
		usernameData = usernameData + _latestMessage[i];
	}
	std::cout << "UserData: " << usernameData << std::endl;

	
	std::string legionData;
	
	for (int i = usernameSection + 1; i < legionSection; i++)
	{
		legionData = legionData + _latestMessage[i];
	}
	std::cout << "LegionData: " << legionData << std::endl;


	std::string messageData;

	for (int i = legionSection + 1; i < _latestMessage.length(); i++)
	{
		messageData = messageData + _latestMessage[i];
	}
	std::cout << "MessageData: " << messageData << std::endl;

	m_newMessage.rewriteMessage(usernameData, legionData, messageData);


}


void Server::bounceToClients(std::string _message, size_t _ci)
{

	for (size_t ci = 0; ci < clients.size(); ++ci)
	{
		std::cout << "bouncing to client " << ci << "from " << _ci << std::endl;
		
		clients.at(ci)->send(_message);
		
	
	}

}