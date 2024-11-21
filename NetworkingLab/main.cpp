#include "Wsa.h"
#include "ServerSocket.h"
#include <iostream>
#include <vector>

 


int main()
{
	Wsa wsa;
	printf("Initialized Winsock\n");

	ServerSocket server(8080);
	printf("Server listening on port 8080\n");
	
	std::vector<std::shared_ptr<ClientSocket>> clients;

	while (true)
	{
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
			}
			if (clients.at(ci)->m_closed)
			{
				printf("Client Disconnected\n");
				clients.erase(clients.begin() + ci);
				--ci;
			}
		}


		//printf("Tick...\n");
		Sleep(1000);
	}


	return 0;
}

/*
if (client)
{
	printf("Client Connected!\n");
	clients.push_back(client);
}

std::string message;
client->receive(message);
printf("Recieved: %s\n", message.c_str());

client->send("message from server");
printf("Sent our message\n");
*/