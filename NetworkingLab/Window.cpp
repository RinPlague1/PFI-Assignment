#include "Window.h"
#include <stdexcept>

Window::Window() :
	Fl_Window(1280, 720, "Legio Chat")
	, m_currentState(menu)
	, m_ServerButton(230, 240, 200, 200, "Host")
	, m_ClientButton(530, 240, 200, 200, "Join")
	, m_logoBox(0, 0, 215, 420)
	, m_textBox(215, 0, 425, 420)
	, m_buttonBox(0, 420, 640, 60)
	, m_menuBar(0,0,640,30)
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
	, m_alphaLegion("imagesAlpha_Legion.png")
	, m_DA(200, 200, 181, 141)

{
	Fl::scheme("gtk+");

	m_DA.box(FL_DOWN_BOX);
	if (m_darkAngels.fail())
	{
		throw std::runtime_error("Dark Angels Failed");
	}

	m_DA.image(m_darkAngels);

	m_ServerButton.callback(createServerOnClick, this);
	m_ClientButton.callback(joinServerOnClick, this);


	

	
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
}


void Window::changeState(windowState _State)
{
	switch (_State)
	{
	case menu:

		break;
	case hosting:

		break;
	case join:

		break;
	case room:

		break;
	default:
		break;
	}
}