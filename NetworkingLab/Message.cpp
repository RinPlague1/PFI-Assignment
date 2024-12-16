#include "Message.h"

Message::Message(std::string _username, std::string _legion, std::string _message):
	m_username(_username)
	,m_legion(_legion)
	,m_message(_message)


{
	pugi::xml_node root = m_newMessage.append_child("userData");	//creates an xml doc of the sent message
	pugi::xml_node info = root.append_child("info");
	pugi::xml_node username = info.append_child("username");
	pugi::xml_node legion = info.append_child("legion");

	pugi::xml_node message = root.append_child("message");

	username.append_attribute("username").set_value(m_username.c_str());
	legion.append_attribute("id").set_value(m_legion.c_str());

	message.append_attribute("text").set_value(m_message.c_str());




}

Message::~Message()
{

}

std::string Message::xmlToString()
{

	m_newMessage.save_file("test.xml");	//saves the current sent message as a doc

	pugi::xml_node search = m_newMessage.child("userData");
	pugi::xml_node searchInfo = search.child("info");

	std::string outUsername;
	pugi::xml_node searchUsername = searchInfo.child("username");
	outUsername = searchUsername.attribute("username").value();
	std::cout << outUsername << " -> ";

	std::string outLegion;
	pugi::xml_node searchLegion = searchInfo.child("legion");
	outLegion = searchLegion.attribute("id").value();
	std::cout << outLegion << " -> ";

	std::string outMessage;
	pugi::xml_node searchMessage = search.child("message");
	outMessage = searchMessage.attribute("text").value();
	std::cout << outMessage << " -> end message" << std::endl;

	std::string message;
	message = outUsername + "§" + outLegion + "§" + outMessage;	//adds the separating characters

	return message;
}

void Message::rewriteMessage(std::string _username, std::string _legion, std::string _message)
{

	m_username = _username;
	m_legion = _legion;
	m_message = _message;

}

std::string Message::getUsername()
{
	return m_username;
}

std::string Message::getLegion()
{
	return m_legion;
}

std::string Message::getMessage()
{
	return m_message;
}