#pragma once

#ifndef WINDOW_CLASS
#define WINDOW_CLASS


#include "fltk/include/FL/Fl_Window.H"

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_PNG_Image.H>
#include <Fl/Fl_Menu_Bar.H>
#include <Fl/Fl_Input.H>
#include <FL/Fl_Text_Display.H>

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

	Fl_PNG_Image m_terraBG;
	Fl_Box m_terraBGBox;

	Fl_Button m_ServerButton;
	Fl_Button m_ClientButton;

	Fl_Box m_logoBox;
	Fl_Text_Display m_IpDisplayBox;
	Fl_Text_Buffer m_IpTextBuffer;
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

	//img boxes
	Fl_Box m_DA;
	Fl_Box m_EC;
	Fl_Box m_IW;
	Fl_Box m_WS;
	Fl_Box m_SW;
	Fl_Box m_IF;
	Fl_Box m_NL;
	Fl_Box m_BA;
	Fl_Box m_IH;
	Fl_Box m_WE;
	Fl_Box m_UM;
	Fl_Box m_DG;
	Fl_Box m_TS;
	Fl_Box m_BL;
	Fl_Box m_WB;
	Fl_Box m_S;
	Fl_Box m_RG;
	Fl_Box m_AL;

	Fl_Input m_ipInput;


public:
	Window();
	~Window();

	static void createServerOnClick(Fl_Widget* _widget, void* _userData);
	static void joinServerOnClick(Fl_Widget* _widget, void* _userData);

	static void enteredIpAddress(Fl_Widget* _widget, void* _userData);

	void changeState(windowState _State);

};



#endif // !WINDOW_CLASS


