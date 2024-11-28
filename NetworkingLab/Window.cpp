#include "Window.h"
#include <stdexcept>

Window::Window() :
	Fl_Window(640, 480, "Hello")
	, m_ServerButton(430, 440, 80, 20, "Server Mode")
	, m_ClientButton(530, 440, 80, 20, "Client Mode")
	, m_logoBox(0, 0, 215, 420)
	, m_textBox(215, 0, 425, 420)
	, m_buttonBox(0, 420, 640, 60)
	, m_steamIcon("steamIcon.png")
	, m_steamLogo("steamLogo.png")
	, m_menuBar(0,0,640,30)
	
	, m_titusSelfie("titusSelfie.png")
	, m_close(10, 10, 120, 30, "close")
	, m_img(100, 100, 100, 100, "Woah")

{
	Fl::scheme("gtk+");



	m_close.callback(closeOnClick, this);
	m_ServerButton.callback(createServerOnClick, this);
	m_ClientButton.callback(joinServerOnClick, this);


	m_img.box(FL_DOWN_BOX);
	m_img.color(fl_rgb_color(123, 45, 234));

	if (m_titusSelfie.fail())
	{
		throw std::runtime_error("Failed");
	}

	m_img.image(m_titusSelfie);
	
}

Window::~Window()
{

}

void Window::closeOnClick(Fl_Widget* _widget, void* _userData)
{
	Fl_Window* win = (Fl_Window*)_userData;
	win->hide();
}

void Window::createServerOnClick(Fl_Widget* _widget, void* _userData)
{

}

void Window::joinServerOnClick(Fl_Widget* _widget, void* _userData)
{

}
