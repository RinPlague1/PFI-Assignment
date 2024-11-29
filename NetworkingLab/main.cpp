#include "Wsa.h"
#include "ServerSocket.h"
#include <iostream>
#include <vector>

#include "Window.h"
#include <FL/Fl.H>

 
void onClick(Fl_Widget* _widget, void* _userData)
{
	Fl_Window* win = (Fl_Window*)_userData;
	win->hide();
}

int main()
{


		Window mainWindow;

		mainWindow.show();


		return Fl::run();

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