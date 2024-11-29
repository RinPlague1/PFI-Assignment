#pragma once

#ifndef WINDOW_CLASS
#define WINDOW_CLASS


#include "fltk/include/FL/Fl_Window.H"

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_PNG_Image.H>
#include <Fl/Fl_Menu_Bar.H>

#include "Server.h"

enum windowState
{
	menu = 0,
	hosting = 1,
	join = 2,
	room = 3,
	
};



class Window :
    public Fl_Window
{
private:
	windowState m_currentState;


	Fl_Box m_img;

	Fl_Button m_ServerButton;
	Fl_Button m_ClientButton;

	Fl_Box m_logoBox;
	Fl_Box m_textBox;
	Fl_Box m_buttonBox;

	Server* m_Server;
	

	Fl_Menu_Bar m_menuBar;

public:
	Window();
	~Window();

	static void createServerOnClick(Fl_Widget* _widget, void* _userData);
	static void joinServerOnClick(Fl_Widget* _widget, void* _userData);

};



#endif // !WINDOW_CLASS


