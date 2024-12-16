#include "Wsa.h"
#include "ServerSocket.h"
#include <iostream>
#include <vector>

#include "Window.h"
#include <FL/Fl.H>

 
void onClick(Fl_Widget* _widget, void* _userData)
{
	Fl_Window* win = (Fl_Window*)_userData;	//hangles the close button on the window
	win->hide();
}

int main(int argc, char* argv[])
{
		Window mainWindow;
		mainWindow.show();
		FreeConsole();
		return Fl::run();

}
