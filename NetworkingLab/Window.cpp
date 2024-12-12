#include "Window.h"
#include <stdexcept>

Window::Window() :
	Fl_Window(1920, 1080, "Legio Chat")
	, m_currentState(menu)
	, m_terraBG("images/Imperial_Palace_Terra2(1).png")
	, m_terraBGBox(0, 0, 1920, 1080)
	, m_ServerButton(230, 240, 200, 200, "Host")
	, m_ClientButton(530, 240, 200, 200, "Join")
	, m_logoBox(0, 0, 215, 420)
	, m_textBox(215, 0, 425, 420)
	, m_buttonBox(0, 420, 640, 60)
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
	, m_ipInput(885,200,150,50,"IP Address: ")
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
		throw std::runtime_error("Dark Angels Failed");
	}
	m_IW.box(FL_DOWN_BOX);
	if (m_ironWarriors.fail())
	{
		throw std::runtime_error("Dark Angels Failed");
	}
	m_NL.box(FL_DOWN_BOX);
	if (m_nightLords.fail())
	{
		throw std::runtime_error("Dark Angels Failed");
	}
	m_WE.box(FL_DOWN_BOX);
	if (m_worldEaters.fail())
	{
		throw std::runtime_error("Dark Angels Failed");
	}
	m_DG.box(FL_DOWN_BOX);
	if (m_deathGuard.fail())
	{
		throw std::runtime_error("Dark Angels Failed");
	}
	m_TS.box(FL_DOWN_BOX);
	if (m_thousandSons.fail())
	{
		throw std::runtime_error("Dark Angels Failed");
	}
	m_BL.box(FL_DOWN_BOX);
	if (m_blackLegion.fail())
	{
		throw std::runtime_error("Dark Angels Failed");
	}
	m_WB.box(FL_DOWN_BOX);
	if (m_wordBearers.fail())
	{
		throw std::runtime_error("Dark Angels Failed");
	}
	m_AL.box(FL_DOWN_BOX);
	if (m_alphaLegion.fail())
	{
		throw std::runtime_error("Dark Angels Failed");
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



	m_ServerButton.callback(createServerOnClick, this);
	m_ClientButton.callback(joinServerOnClick, this);

	m_ipInput.callback(enteredIpAddress, this);
	m_ipInput.when(FL_WHEN_ENTER_KEY);

	
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

}

void Window::joinServerOnClick(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	mainWindow->m_Client = new Client();

	mainWindow->m_currentState = join;
	mainWindow->changeState(mainWindow->m_currentState);
}


void Window::enteredIpAddress(Fl_Widget* _widget, void* _userData)
{
	Window* mainWindow = (Window*)_userData;
	

	try
	{
		std::string buffer;
		buffer = mainWindow->m_ipInput.value();
		bool validIp = mainWindow->m_Client->m_clientSocket.connectFunction(buffer);
		if (validIp == false)
		{
			mainWindow->m_ipInput.value("");
		}
	}
	catch (std::exception& _ex)
	{
		std::string connectMessage = _ex.what();
		fl_alert(connectMessage.c_str());
		
		
	}
}


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

		break;
	case hosting:

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

		m_ServerButton.hide();
		m_ClientButton.hide();

		break;
	case room:

		break;
	default:
		break;
	}
}