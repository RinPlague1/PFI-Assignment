#include "Window.h"
#include <stdexcept>

Fl_Text_Display::Style_Table_Entry styleTable[19] = {
	{fl_rgb_color(0, 0, 0)},
	{fl_rgb_color(0, 64, 31)},
	{fl_rgb_color(244, 175, 205)},
	{fl_rgb_color(131, 133, 142)},
	{fl_rgb_color(140, 159, 161)},
	{fl_rgb_color(113, 155, 183)},
	{fl_rgb_color(255, 242, 0)},
	{fl_rgb_color(37, 40, 80)},
	{fl_rgb_color(154, 17, 21)},
	{fl_rgb_color(168, 176, 178)},
	{fl_rgb_color(106, 0, 1)},
	{fl_rgb_color(13, 64, 127)},
	{fl_rgb_color(132, 198, 102)},
	{fl_rgb_color(24, 171, 204)},
	{fl_rgb_color(35, 31, 32)},
	{fl_rgb_color(90, 26, 42)},
	{fl_rgb_color(82, 178, 68)},
	{fl_rgb_color(36, 36, 36)},
	{fl_rgb_color(0, 169, 156)}
};

Window::Window() :
	Fl_Window(1920, 1080, "Legion Chat")
	, m_currentState(menu)
	, m_menuBar(0,0,1920,50)
	, m_terraBG("images/Imperial_Palace_Terra2(1).png")
	, m_terraBGBox(0, 0, 1920, 1080)
	, m_ServerButton(230, 240, 200, 200, "Host")
	, m_ClientButton(530, 240, 200, 200, "Join")
	, m_pickDA(291, 153, 50, 35, "<-Pick")
	, m_pickEC(1299, 153, 50, 35, "Pick->")
	, m_pickIW(1299, 304, 50, 35, "Pick->")
	, m_pickWS(291, 304, 50, 35, "<-Pick")
	, m_pickSW(291, 455, 50, 35, "<-Pick")
	, m_pickIF(291, 606, 50, 35, "<-Pick")
	, m_pickNL(1299, 455, 50, 35, "Pick->")
	, m_pickBA(541, 153, 50, 35, "<-Pick")
	, m_pickIH(541, 304, 50, 35, "<-Pick")
	, m_pickWE(1299, 606, 50, 35, "Pick->")
	, m_pickUM(541, 455, 50, 35, "<-Pick")
	, m_pickDG(1299, 757, 50, 35, "Pick->")
	, m_pickTS(1549, 153, 50, 35, "Pick->")
	, m_pickBL(1549, 304, 50, 35, "Pick->")
	, m_pickWB(1549, 455, 50, 35, "Pick->")
	, m_pickS(541, 606, 50, 35, "<-Pick")
	, m_pickRG(541, 757, 50, 35, "<-Pick")
	, m_pickAL(1549, 606, 50, 35, "Pick->")
	, m_logoBox(0, 0, 215, 420)
	, m_IpDisplayBox(885, 250, 150, 25)
	, m_IpTextBuffer()
	, m_buttonBox(0, 420, 640, 60)
	, m_chatLog(725, 100, 434, 650)
	, m_chatBuffer()
	, m_chatStyleBuffer()
	, m_message(725, 750, 434, 100)
	, m_Server(nullptr)
	, m_Client(nullptr)
	, m_darkAngels("images/Interrogator_Chaplain-750x563.png")
	, m_emperorsChildren("images/Noise_Marine.png")
	, m_ironWarriors("images/IronWarrior-750x563.png")
	, m_whiteScars("images/WhiteScar_Inceptor-750x563.png")
	, m_spaceWolves("images/Wulfen-750x563.png")
	, m_imperialFists("images/Imperial_Fist-750x563.png")
	, m_nightLords("images/NL_Raptor-750x669.png")
	, m_bloodAngels("images/BloodAngel-750x563.png")
	, m_ironHands("images/iron_Hands-750x643.png")
	, m_worldEaters("images/Berserker-750x673.png")
	, m_ultramarines("images/Primaris_LT_Ultra-750x508.png")
	, m_deathGuard("images/PlagueMarine-750x566.png")
	, m_thousandSons("images/Scarab_Occult_terminator-1024x850.png")
	, m_blackLegion("images/BlackLegionTerminator-750x606.png")
	, m_wordBearers("images/WB_Possessed-750x563.png")
	, m_salamanders("images/Salamanders_Eradicator-750x563.png")
	, m_ravenguard("images/RavenGuard_Reiver-750x563.png")
	, m_alphaLegion("images/Alpha_Legion.png")
	/*, m_windowIcon("images/titusSelfie.png")*/
	, m_DA(100, 100, 181, 141)
	, m_EC(1359, 100, 181, 141)
	, m_IW(1359, 251, 181, 141)
	, m_WS(100, 251, 181, 141)
	, m_SW(100, 402, 181, 141)
	, m_IF(100, 553, 181, 141)
	, m_NL(1359, 402, 181, 141)
	, m_BA(350, 100, 181, 141)
	, m_IH(350, 251, 181, 141)
	, m_WE(1359, 553, 181, 141)
	, m_UM(350, 402, 181, 141)
	, m_DG(1359, 704, 181, 141)
	, m_TS(1609, 100, 181, 141)
	, m_BL(1609, 251, 181, 141)
	, m_WB(1609, 402, 181, 141)
	, m_S(350, 553, 181, 141)
	, m_RG(350, 704, 181, 141)
	, m_AL(1609 ,553, 181, 141)
	, m_usernameInput(885, 200, 150, 50, "Username: ")
	, m_ipInput(885,400,150,50,"IP Address: ")
	, m_incomingMessage("","","")
	, msgCount(0)
	
{
	Fl::scheme("gtk+");
	
	m_menuBar.add("&File/Return To Menu", "^o", returnToMenu, this);

	m_terraBGBox.box(FL_DOWN_BOX);
	if (m_terraBG.fail())
	{
		throw std::runtime_error("terra Failed");
	}

	m_terraBGBox.image(m_terraBG);

	m_DA.box(FL_DOWN_BOX);
	if (m_darkAngels.fail())
	{
		throw std::runtime_error("Dark Angels Failed");
	}
	m_WS.box(FL_DOWN_BOX);
	if (m_whiteScars.fail())
	{
		throw std::runtime_error("white scars Failed");
	}
	m_SW.box(FL_DOWN_BOX);
	if (m_spaceWolves.fail())
	{
		throw std::runtime_error("space wolves Failed");
	}
	m_IF.box(FL_DOWN_BOX);
	if (m_imperialFists.fail())
	{
		throw std::runtime_error("imperial fists Failed");
	}
	m_BA.box(FL_DOWN_BOX);
	if (m_bloodAngels.fail())
	{
		throw std::runtime_error("blood angels Failed");
	}
	m_IH.box(FL_DOWN_BOX);
	if (m_imperialFists.fail())
	{
		throw std::runtime_error("iron hands Failed");
	}
	m_UM.box(FL_DOWN_BOX);
	if (m_ultramarines.fail())
	{
		throw std::runtime_error("ultramarines Failed");
	}
	m_S.box(FL_DOWN_BOX);
	if (m_salamanders.fail())
	{
		throw std::runtime_error("salamanders Failed");
	}
	m_RG.box(FL_DOWN_BOX);
	if (m_ravenguard.fail())
	{
		throw std::runtime_error("raven gurad Failed");
	}


	m_EC.box(FL_DOWN_BOX);
	if (m_emperorsChildren.fail())
	{
		throw std::runtime_error("emperors children Failed");
	}
	m_IW.box(FL_DOWN_BOX);
	if (m_ironWarriors.fail())
	{
		throw std::runtime_error("Iron Warriors Failed");
	}
	m_NL.box(FL_DOWN_BOX);
	if (m_nightLords.fail())
	{
		throw std::runtime_error("Night Lords Failed");
	}
	m_WE.box(FL_DOWN_BOX);
	if (m_worldEaters.fail())
	{
		throw std::runtime_error("World Eaters Failed");
	}
	m_DG.box(FL_DOWN_BOX);
	if (m_deathGuard.fail())
	{
		throw std::runtime_error("Death Guard Failed");
	}
	m_TS.box(FL_DOWN_BOX);
	if (m_thousandSons.fail())
	{
		throw std::runtime_error("Thousand Sons Failed");
	}
	m_BL.box(FL_DOWN_BOX);
	if (m_blackLegion.fail())
	{
		throw std::runtime_error("Black Legion Failed");
	}
	m_WB.box(FL_DOWN_BOX);
	if (m_wordBearers.fail())
	{
		throw std::runtime_error("Word Bearers Failed");
	}
	m_AL.box(FL_DOWN_BOX);
	if (m_alphaLegion.fail())
	{
		throw std::runtime_error("Alpha Legion Failed");
	}

	m_DA.image(m_darkAngels);
	m_WS.image(m_whiteScars);
	m_SW.image(m_spaceWolves);
	m_IF.image(m_imperialFists);
    m_BA.image(m_bloodAngels);
    m_IH.image(m_ironHands);
    m_UM.image(m_ultramarines);
	m_S.image(m_salamanders);
	m_RG.image(m_ravenguard);

	m_EC.image(m_emperorsChildren);
	m_IW.image(m_ironWarriors);
	m_NL.image(m_nightLords);
	m_WE.image(m_worldEaters);
	m_DG.image(m_deathGuard);
	m_TS.image(m_thousandSons);
	m_BL.image(m_blackLegion);
	m_WB.image(m_wordBearers);
	m_AL.image(m_alphaLegion);


	m_IpTextBuffer.text("IP address: 127.0.0.1");
	m_IpDisplayBox.buffer(m_IpTextBuffer);
	
	m_ServerButton.callback(staticCreateServer, this);
	m_ClientButton.callback(StaticCreateClient, this);

	 m_pickDA.callback(legionDA, this);
	 m_pickEC.callback(legionEC, this);
	 m_pickIW.callback(legionIW, this);
	 m_pickWS.callback(legionWS, this);
	 m_pickSW.callback(legionSW, this);
	 m_pickIF.callback(legionIF, this);
	 m_pickNL.callback(legionNL, this);
	 m_pickBA.callback(legionBA, this);
	 m_pickIH.callback(legionIH, this);
	 m_pickWE.callback(legionWE, this);
	 m_pickUM.callback(legionUM, this);
	 m_pickDG.callback(legionDG, this);
	 m_pickTS.callback(legionTS, this);
	 m_pickBL.callback(legionBL, this);
	 m_pickWB.callback(legionWB, this);
	 m_pickS.callback(legionS, this);
	 m_pickRG.callback(legionRG, this);
	 m_pickAL.callback(legionAL, this);


	m_ipInput.callback(enteredIpAddress, this);
	m_ipInput.when(FL_WHEN_ENTER_KEY);

	m_message.callback(sendMessage, this);
	m_message.when(FL_WHEN_ENTER_KEY);
	
	m_usernameInput.callback(usernameInput, this);
	m_usernameInput.when(FL_WHEN_ENTER_KEY);


	this->changeState(m_currentState);
	
}

Window::~Window()
{

}


void Window::staticCreateServer(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->createServer();
}

void Window::createServer()
{
	m_Server = new Server();
	std::cout << "server created";

	m_currentState = hosting;
	changeState(m_currentState);
}

void Window::StaticCreateClient(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->createClient();

	
}

void Window::createClient()
{
	m_Client = std::make_shared<Client>(this);
	m_currentState = join;
	changeState(m_currentState);
}

void Window::addToLog(std::string _buffer)
{
	if (msgCount > 0)
	{
		interperateMessage(_buffer);

		std::cout << m_incomingMessage.getLegion() << std::endl;
		


		m_chatBuffer.append(m_incomingMessage.getUsername().c_str());
		m_chatBuffer.append(": ");
		m_chatLog.buffer(m_chatBuffer);
		

		m_chatLog.highlight_data(&m_chatStyleBuffer, styleTable, 19, 'A', nullptr, nullptr);

		setColour();

		//fl_color(0, 0, 0);
		m_chatBuffer.append(m_incomingMessage.getMessage().c_str());
		m_chatLog.buffer(m_chatBuffer);
		

		for (int i = 0; i < m_incomingMessage.getMessage().length() + 1; i++)
		{
			m_chatStyleBuffer.append("A");
		}

		m_chatBuffer.append("\n");
		m_chatStyleBuffer.append("\n");

		

		m_chatLog.buffer(m_chatBuffer);

		
	} 
	else 
	{
		for (int i = 0; i < _buffer.length(); i++)
		{
			m_chatStyleBuffer.append("A");
		}

		m_chatBuffer.append(_buffer.c_str());
		m_chatLog.buffer(m_chatBuffer);
		m_chatBuffer.append("\n");
		m_chatStyleBuffer.append("\n");
		msgCount += 1;
	}
	
}


void Window::enteredIpAddress(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	
	if (mainWindow->m_Client->m_clientSocket.getUsername() == "§")
	{
		Window* mainWindow = (Window*)_userData;

		std::string usernameBuffer;
		usernameBuffer = mainWindow->m_usernameInput.value();
		std::cout << "username: " << usernameBuffer << std::endl;

		mainWindow->m_Client->m_clientSocket.setUsername(usernameBuffer);
		mainWindow->m_usernameInput.value("");

		if (mainWindow->m_Client->m_clientSocket.getUsername() == "")
		{
			mainWindow->m_Client->m_clientSocket.setUsername("Anonymous Client");
		}
	}

	std::string buffer;
	buffer = mainWindow->m_ipInput.value();
	bool validIp = mainWindow->m_Client->m_clientSocket.connectFunction(buffer);
	if (validIp == false)
	{
		mainWindow->m_ipInput.value("");
	}
	else
	{
		mainWindow->m_ipInput.value("");
		mainWindow->m_currentState = room;
		mainWindow->changeState(mainWindow->m_currentState);
	}

}

void Window::sendMessage(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;

	std::string msgBuffer;
	msgBuffer = mainWindow->m_message.value();

	Message* newMessage = new Message(mainWindow->m_Client->m_clientSocket.getUsername(), mainWindow->m_Client->m_clientSocket.getLegion(), msgBuffer);
	std::string messageSend = newMessage->xmlToString();

	std::cout << "message sending: " << newMessage << std::endl;
	mainWindow->m_Client->m_clientSocket.send(messageSend);
	mainWindow->m_message.value("");
	
}

void Window::usernameInput(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;

	std::string usernameBuffer;
	usernameBuffer = mainWindow->m_usernameInput.value();
	std::cout << "username: " << usernameBuffer << std::endl;

	mainWindow->m_Client->m_clientSocket.setUsername(usernameBuffer);
	mainWindow->m_usernameInput.value("");


}

void Window::interperateMessage(std::string _message)
{
	std::string nullKey("§");
	std::size_t usernameSection = _message.find(nullKey);
	std::size_t legionSection = _message.find(nullKey, usernameSection + 1);

	std::cout << "whole message: " << _message << std::endl;

	std::string usernameData;

	for (int i = 0; i < usernameSection; i++)
	{
		usernameData = usernameData + _message[i];
	}
	std::cout << "UserData: " << usernameData << std::endl;


	std::string legionData;

	for (int i = usernameSection + 1; i < legionSection; i++)
	{
		legionData = legionData + _message[i];
	}
	std::cout << "LegionData: " << legionData << std::endl;


	std::string messageData;

	for (int i = legionSection + 1; i < _message.length(); i++)
	{
		messageData = messageData + _message[i];
	}
	std::cout << "MessageData: " << messageData << std::endl;

	m_incomingMessage.rewriteMessage(usernameData, legionData, messageData);


}

void Window::setColour()
{
	std::string colourId;
	colourId = colourId + m_incomingMessage.getLegion();
	int usernameLength = 0;

	if (colourId == "1")
	{	

		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("B");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();

	}

	if (colourId == "2")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("C");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "3")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("D");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "4")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("E");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "5")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("F");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "6")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("G");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "7")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("H");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "8")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("I");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "9")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("J");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "10")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("K");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "11")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("L");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "12")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("M");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "13")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("N");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "14")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("O");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "15")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("P");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "16")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("Q");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "17")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("R");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}

	if (colourId == "18")
	{
		for (int i = 0; i < m_incomingMessage.getUsername().length() + 1; i++)
		{
			m_chatStyleBuffer.append("S");
		}

		std::cout << "style buffer: " << m_chatStyleBuffer.text() << std::endl;
		m_chatLog.redraw();
		
	}


}

void Window::legionDA(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("1");
}
void Window::legionEC(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("2");
}
void Window::legionIW(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("3");
}
void Window::legionWS(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("4");
}
void Window::legionSW(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("5");
}
void Window::legionIF(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("6");
}
void Window::legionNL(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("7");
}
void Window::legionBA(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("8");
}
void Window::legionIH(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("9");
}
void Window::legionWE(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("10");
}
void Window::legionUM(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("11");
}
void Window::legionDG(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("12");
}
void Window::legionTS(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("13");
}
void Window::legionBL(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("14");
}
void Window::legionWB(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("15");
}
void Window::legionS(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("16");
}
void Window::legionRG(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("17");
}
void Window::legionAL(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client->m_clientSocket.setLegion("18");
}

void Window::returnToMenu(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	if (mainWindow->m_Server != nullptr)
	{
		mainWindow->m_Server->~Server();
	}
	mainWindow->m_Server = nullptr;

	if (mainWindow->m_Client != nullptr)
	{
		mainWindow->m_Client->~Client();
	}
	
	mainWindow->m_Client = nullptr;
	

	mainWindow->changeState(menu);
}

void Window::changeState(windowState _State)
{
	switch (_State)
	{
	case menu:
		m_ServerButton.show();
		m_ClientButton.show();

		m_DA.hide();
		m_EC.hide();
		m_IW.hide();
		m_WS.hide();
		m_SW.hide();
		m_IF.hide();
		m_NL.hide();
		m_BA.hide();
		m_IH.hide();
		m_WE.hide();
		m_UM.hide();
		m_DG.hide();
		m_TS.hide();
		m_BL.hide();
		m_WB.hide();
		m_S.hide();
		m_RG.hide();
		m_AL.hide();

		m_pickDA.hide();
		m_pickEC.hide();
		m_pickIW.hide();
		m_pickWS.hide();
		m_pickSW.hide();
		m_pickIF.hide();
		m_pickNL.hide();
		m_pickBA.hide();
		m_pickIH.hide();
		m_pickWE.hide();
		m_pickUM.hide();
		m_pickDG.hide();
		m_pickTS.hide();
		m_pickBL.hide();
		m_pickWB.hide();
		m_pickS.hide();
		m_pickRG.hide();
		m_pickAL.hide();

		m_ipInput.hide();
		m_usernameInput.hide();

		m_IpDisplayBox.hide();
		m_chatLog.hide();
		m_message.hide();

		break;
	
	case hosting:
		m_ServerButton.hide();
		m_ClientButton.hide();

		m_IpDisplayBox.show();

		break;
	
	case join:
		m_DA.show();
		m_EC.show();
		m_IW.show();
		m_WS.show();
		m_SW.show();
		m_IF.show();
		m_NL.show();
		m_BA.show();
		m_IH.show();
		m_WE.show();
		m_UM.show();
		m_DG.show();
		m_TS.show();
		m_BL.show();
		m_WB.show();
		m_S.show();
		m_RG.show();
		m_AL.show();

		m_pickDA.show();
		m_pickEC.show();
		m_pickIW.show();
		m_pickWS.show();
		m_pickSW.show();
		m_pickIF.show();
		m_pickNL.show();
		m_pickBA.show();
		m_pickIH.show();
		m_pickWE.show();
		m_pickUM.show();
		m_pickDG.show();
		m_pickTS.show();
		m_pickBL.show();
		m_pickWB.show();
		m_pickS.show();
		m_pickRG.show();
		m_pickAL.show();

		m_ipInput.show();
		m_usernameInput.show();

		m_ServerButton.hide();
		m_ClientButton.hide();

		break;
	case room:
		m_DA.hide();
		m_EC.hide();
		m_IW.hide();
		m_WS.hide();
		m_SW.hide();
		m_IF.hide();
		m_NL.hide();
		m_BA.hide();
		m_IH.hide();
		m_WE.hide();
		m_UM.hide();
		m_DG.hide();
		m_TS.hide();
		m_BL.hide();
		m_WB.hide();
		m_S.hide();
		m_RG.hide();
		m_AL.hide();

		m_pickDA.hide();
		m_pickEC.hide();
		m_pickIW.hide();
		m_pickWS.hide();
		m_pickSW.hide();
		m_pickIF.hide();
		m_pickNL.hide();
		m_pickBA.hide();
		m_pickIH.hide();
		m_pickWE.hide();
		m_pickUM.hide();
		m_pickDG.hide();
		m_pickTS.hide();
		m_pickBL.hide();
		m_pickWB.hide();
		m_pickS.hide();
		m_pickRG.hide();
		m_pickAL.hide();

		m_ipInput.hide();
		m_usernameInput.hide();

		m_chatLog.show();
		m_message.show();

		break;
	default:
		break;
	}
}