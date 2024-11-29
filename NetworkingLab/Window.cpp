#include "Window.h"
#include <stdexcept>

Window::Window() :
	Fl_Window(960, 640, "Hello")
	, m_currentState(menu)
	, m_ServerButton(430, 440, 80, 20, "Host")
	, m_ClientButton(530, 440, 80, 20, "Join")
	, m_logoBox(0, 0, 215, 420)
	, m_textBox(215, 0, 425, 420)
	, m_buttonBox(0, 420, 640, 60)
	, m_menuBar(0,0,640,30)
	, m_img(100, 100, 100, 100, "Woah")

{
	Fl::scheme("gtk+");

	m_ServerButton.callback(createServerOnClick, this);
	m_ClientButton.callback(joinServerOnClick, this);


	m_img.box(FL_DOWN_BOX);
	m_img.color(fl_rgb_color(123, 45, 234));

	


	
}

Window::~Window()
{

}


void Window::createServerOnClick(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Server = new Server();
	std::cout << "server created";

	mainWindow->m_currentState = hosting;

}

void Window::joinServerOnClick(Fl_Widget* _widget, void* _userData)
{

}
