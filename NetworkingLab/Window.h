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
#include "Message.h"

enum windowState
{
	menu = 0,
	hosting = 1,
	join = 2,
	room = 3,
	
};



struct Message;

class Window :
    public Fl_Window
{
private:
	friend struct Message;

	windowState m_currentState;

	

	Fl_PNG_Image m_terraBG;
	Fl_Box m_terraBGBox;

	Fl_Menu_Bar m_menuBar;

	Fl_Button m_ServerButton;
	Fl_Button m_ClientButton;

	Fl_Button m_pickDA;
	Fl_Button m_pickEC;
	Fl_Button m_pickIW;
	Fl_Button m_pickWS;
	Fl_Button m_pickSW;
	Fl_Button m_pickIF;
	Fl_Button m_pickNL;
	Fl_Button m_pickBA;
	Fl_Button m_pickIH;
	Fl_Button m_pickWE;
	Fl_Button m_pickUM;
	Fl_Button m_pickDG;
	Fl_Button m_pickTS;
	Fl_Button m_pickBL;
	Fl_Button m_pickWB;
	Fl_Button m_pickS;
	Fl_Button m_pickRG;
	Fl_Button m_pickAL;




	Fl_Box m_logoBox;
	Fl_Text_Display m_IpDisplayBox;
	Fl_Text_Buffer m_IpTextBuffer;
	Fl_Box m_buttonBox;

	Fl_Text_Display m_chatLog;
	Fl_Text_Buffer m_chatBuffer;
	Fl_Text_Buffer m_chatStyleBuffer;

	Fl_Input m_message;

	Server* m_Server;
	std::shared_ptr<Client> m_Client;

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

	//Fl_PNG_Image m_windowIcon;

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

	Fl_Input m_usernameInput;
	
	Fl_Input m_ipInput;

	Message m_incomingMessage;
	int msgCount;


public:
	Window();
	~Window();

	static void staticCreateServer(Fl_Widget* _widget, void* _userData);
	void createServer();

	void createClient();
	static void StaticCreateClient(Fl_Widget* _widget, void* _userData);
	
	void interperateMessage(std::string _message);
	void setColour();
	
	void addToLog(std::string _buffer);

	static void enteredIpAddress(Fl_Widget* _widget, void* _userData);
	static void sendMessage(Fl_Widget* _widget, void* _userData);

	static void usernameInput(Fl_Widget* _widget, void* _userData);
	
	static void legionDA(Fl_Widget* _widget, void* _userData);
	static void legionEC(Fl_Widget* _widget, void* _userData);
	static void legionIW(Fl_Widget* _widget, void* _userData);
	static void legionWS(Fl_Widget* _widget, void* _userData);
	static void legionSW(Fl_Widget* _widget, void* _userData);
	static void legionIF(Fl_Widget* _widget, void* _userData);
	static void legionNL(Fl_Widget* _widget, void* _userData);
	static void legionBA(Fl_Widget* _widget, void* _userData);
	static void legionIH(Fl_Widget* _widget, void* _userData);
	static void legionWE(Fl_Widget* _widget, void* _userData);
	static void legionUM(Fl_Widget* _widget, void* _userData);
	static void legionDG(Fl_Widget* _widget, void* _userData);
	static void legionTS(Fl_Widget* _widget, void* _userData);
	static void legionBL(Fl_Widget* _widget, void* _userData);
	static void legionWB(Fl_Widget* _widget, void* _userData);
	static void legionS(Fl_Widget* _widget, void* _userData);
	static void legionRG(Fl_Widget* _widget, void* _userData);
	static void legionAL(Fl_Widget* _widget, void* _userData);

	static void returnToMenu(Fl_Widget* _widget, void* _userData);

	void changeState(windowState _State);

};



#endif // !WINDOW_CLASS


