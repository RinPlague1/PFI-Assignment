#include "Server.h"

Server::Server():
			Timer(0.0167f)	//sets the on tick rate
	, server(8080)
	, m_newMessage("","","")	//stores the sent message as a blank for now
{

}

Server::~Server()
{

}

void Server::on_tick()
{

	std::shared_ptr<ClientSocket> client = server.accept();
	if (client)
	{
		printf("Client Connected!\n");
		sendServerVer(client);
		clients.push_back(client);	//checks for client connect then adds client to the client vector when connected
	}


	// Handle all clients
	for (size_t ci = 0; ci < clients.size(); ++ci)	//checks all clients for a recieved message
	{
		std::string message;
		while (clients.at(ci)->receive(message))
		{
			printf("Message recived: %s\n", message.c_str());

			recievedMessage(message);	// splits the message out in to the 3 componants

			std::cout << "bounce to clients from: " << ci;

			bounceToClients(message, ci);	//sends back to all clients
		}
		if (clients.at(ci)->m_closed)	//handles client disconnect
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
	std::string nullKey("§");	//assigns the symbol for sections
	std::size_t usernameSection = _latestMessage.find(nullKey);
	std::size_t legionSection = _latestMessage.find(nullKey, usernameSection + 1);	//find the location of the sections

	std::cout << "whole message: " << _latestMessage << std::endl;

	std::string usernameData;

	for (int i = 0; i < usernameSection; i++)	// adds the username data to a string
	{
		usernameData = usernameData + _latestMessage[i];
	}
	std::cout << "UserData: " << usernameData << std::endl;

	
	std::string legionData;
	
	for (int i = usernameSection + 1; i < legionSection; i++) // adds the legion data to a string
	{
		legionData = legionData + _latestMessage[i];
	}
	std::cout << "LegionData: " << legionData << std::endl;


	std::string messageData;

	for (int i = legionSection + 1; i < _latestMessage.length(); i++) // adds the actual message to a string
	{
		messageData = messageData + _latestMessage[i];
	}
	std::cout << "MessageData: " << messageData << std::endl;

	m_newMessage.rewriteMessage(usernameData, legionData, messageData);	// puts it in to the server message object


}


void Server::bounceToClients(std::string _message, size_t _ci)
{

	for (size_t ci = 0; ci < clients.size(); ++ci)	// goes through the client array and sends the message to clients
	{
		std::cout << "bouncing to client " << ci << "from " << _ci << std::endl;
		
		clients.at(ci)->send(_message);
		
	
	}

}