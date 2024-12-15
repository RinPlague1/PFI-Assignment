#include "Window.h"
#include <stdexcept>

Window::Window() :
	Fl_Window(1920, 1080, "Legion Chat")
	, m_currentState(menu)
	, m_terraBG("images/Imperial_Palace_Terra2(1).png")
	, m_terraBGBox(0, 0, 1920, 1080)
	, m_ServerButton(230, 240, 200, 200, "Host")
	, m_ClientButton(530, 240, 200, 200, "Join")
	, m_logoBox(0, 0, 215, 420)
	, m_IpDisplayBox(885, 250, 150, 25)
	, m_IpTextBuffer()
	, m_buttonBox(0, 420, 640, 60)
	, m_chatLog(725, 100, 434, 650)
	, m_chatBuffer()
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
	
	m_ServerButton.callback(createServerOnClick, this);
	m_ClientButton.callback(StaticCreateClient, this);

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


void Window::createServerOnClick(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Server = new Server();
	std::cout << "server created";

	mainWindow->m_currentState = hosting;
	mainWindow->changeState(mainWindow->m_currentState);
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
		setColour();

		m_chatBuffer.append(m_incomingMessage.getUsername().c_str());
		m_chatBuffer.append(": ");
		m_chatLog.buffer(m_chatBuffer);

		//fl_color(0, 0, 0);
		m_chatBuffer.append(m_incomingMessage.getMessage().c_str());
		m_chatLog.buffer(m_chatBuffer);

		m_chatBuffer.append("\n");
		m_chatLog.buffer(m_chatBuffer);
	} 
	else 
	{
		m_chatBuffer.append(_buffer.c_str());
		m_chatLog.buffer(m_chatBuffer);
		m_chatBuffer.append("\n");
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

//void Window::setColour()
//{
//	std::string colourId;
//	colourId = colourId + m_incomingMessage.getLegion();
//
//	if (colourId == "1")
//	{
//		fl_color(244, 175, 205);
//		
//	}
//
//	if (colourId == "2")
//	{
//		std::vector<int> emperorsChildren = { 244, 175, 205 };
//		
//	}
//
//	if (colourId == "3")
//	{
//		std::vector<int> ironWarriors = { 131, 133, 142 };
//		
//	}
//
//	if (colourId == "4")
//	{
//		std::vector<int> whiteScars = { 40, 159, 161 };
//		
//	}
//
//	if (colourId == "5")
//	{
//		std::vector<int> spaceWolves = { 113, 155, 183 };
//		
//	}
//
//	if (colourId == "6")
//	{
//		std::vector<int> imperialFists = { 255, 242, 0 };
//		
//	}
//
//	if (colourId == "7")
//	{
//		std::vector<int> nightLords = { 37, 40, 80 };
//		
//	}
//
//	if (colourId == "8")
//	{
//		std::vector<int> bloodAngels = { 154, 17, 21 };
//		
//	}
//
//	if (colourId == "9")
//	{
//		std::vector<int> ironHands = { 0, 64, 31 };
//		
//	}
//
//	if (colourId == "10")
//	{
//		std::vector<int> darkAngels = { 0, 64, 31 };
//		
//	}
//
//	if (colourId == "11")
//	{
//		std::vector<int> darkAngels = { 0, 64, 31 };
//		
//	}
//
//	if (colourId == "12")
//	{
//		std::vector<int> darkAngels = { 0, 64, 31 };
//		
//	}
//
//	if (colourId == "13")
//	{
//		std::vector<int> darkAngels = { 0, 64, 31 };
//		
//	}
//
//	if (colourId == "14")
//	{
//		std::vector<int> darkAngels = { 0, 64, 31 };
//		
//	}
//
//	if (colourId == "15")
//	{
//		std::vector<int> darkAngels = { 0, 64, 31 };
//		
//	}
//
//	if (colourId == "16")
//	{
//		std::vector<int> darkAngels = { 0, 64, 31 };
//		
//	}
//
//	if (colourId == "17")
//	{
//		std::vector<int> darkAngels = { 0, 64, 31 };
//		
//	}
//
//	if (colourId == "18")
//	{
//		std::vector<int> darkAngels = { 0, 64, 31 };
//		
//	}
//
//
//}

void Window::changeState(windowState _State)
{
	switch (_State)
	{
	case menu:
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

		m_ipInput.hide();
		m_usernameInput.hide();

		m_chatLog.show();
		m_message.show();

		break;
	default:
		break;
	}
}