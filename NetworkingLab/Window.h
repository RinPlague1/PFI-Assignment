#pragma once

#ifndef WINDOW_CLASS
#define WINDOW_CLASS


#include "fltk/include/FL/Fl_Window.H"

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_PNG_Image.H>
#include <Fl/Fl_Menu_Bar.H>

class Window :
    public Fl_Window
{
private:
	Fl_Button m_close;
	Fl_Box m_img;
	Fl_PNG_Image m_titusSelfie;

	Fl_Button m_ServerButton;
	Fl_Button m_ClientButton;

	Fl_Box m_logoBox;
	Fl_Box m_textBox;
	Fl_Box m_buttonBox;

	Fl_PNG_Image m_steamLogo;
	Fl_PNG_Image m_steamIcon;

	Fl_Menu_Bar m_menuBar;

public:
	Window();
	~Window();

	static void closeOnClick(Fl_Widget* _widget, void* _userData);
	static void createServerOnClick(Fl_Widget* _widget, void* _userData);
	static void joinServerOnClick(Fl_Widget* _widget, void* _userData);

};



#endif // !WINDOW_CLASS

