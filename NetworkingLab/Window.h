#pragma once

#ifndef WINDOW_CLASS
#define WINDOW_CLASS


#include "fltk/include/FL/Fl_Window.H"

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_PNG_Image.H>
#include <Fl/Fl_Menu_Bar.H>

#include <vector>

#include "Server.h"
#include "Client.h"

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


	//Fl_Box m_img;

	Fl_Button m_ServerButton;
	Fl_Button m_ClientButton;

	Fl_Box m_logoBox;
	Fl_Box m_textBox;
	Fl_Box m_buttonBox;

	Server* m_Server;
	Client* m_Client;

	//images
	Fl_PNG_Image m_darkAngels;
	Fl_PNG_Image m_emperorsChildren;
	Fl_PNG_Image m_ironWarriors;
	Fl_PNG_Image m_whiteScars;
	Fl_PNG_Image m_spaceWolves;
	Fl_PNG_Image m_imperialFists;
	Fl_PNG_Image m_nightLords;
	Fl_PNG_Image m_bloodAngels;
	Fl_PNG_Image m_ironHands;
	Fl_PNG_Image m_worldEaters;
	Fl_PNG_Image m_ultramarines;
	Fl_PNG_Image m_deathGuard;
	Fl_PNG_Image m_thousandSons;
	Fl_PNG_Image m_blackLegion;
	Fl_PNG_Image m_wordBearers;
	Fl_PNG_Image m_salamanders;
	Fl_PNG_Image m_ravenguard;
	Fl_PNG_Image m_alphaLegion;



	Fl_Menu_Bar m_menuBar;

public:
	Window();
	~Window();

	static void createServerOnClick(Fl_Widget* _widget, void* _userData);
	static void joinServerOnClick(Fl_Widget* _widget, void* _userData);

	void changeState(windowState _State);

};



#endif // !WINDOW_CLASS


