#include "Server.h"

Server::Server():
			Timer(0.0167f)
	, server(8080)
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
		clients.push_back(client);
	}


	// Handle all clients
	for (size_t ci = 0; ci < clients.size(); ++ci)
	{
		std::string message;
		while (clients.at(ci)->receive(message))
		{
			printf("Message recived: %s\n", message.c_str());

			respond();
		}
		if (clients.at(ci)->m_closed)
		{
			printf("Client Disconnected\n");
			clients.erase(clients.begin() + ci);
			--ci;
		}
	}
}

void Server::respond()
{
	char responseBuffer[300];
	std::cout << "respond to client" << std::endl;
	std::cin.getline(responseBuffer, 300);
	for (size_t ci = 0; ci < clients.size(); ++ci)
	{
		clients.at(ci)->send(responseBuffer);
	
	}

}