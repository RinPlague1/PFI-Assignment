#pragma once

#include <string>
#include <vector>
#include "pugixml.hpp"
#include <iostream>

#ifndef _MESSAGE_
#define _MESSAGE_

struct Message
{
private:
	std::string m_username;
	std::string m_legion;
	std::string m_message;
	pugi::xml_document m_newMessage;

public:
	Message(std::string _username, std::string _legion, std::string _message);
	~Message();
	std::string xmlToString();
	void rewriteMessage(std::string _username, std::string _legion, std::string _message);

	std::string getUsername();
	std::string getLegion();
	std::string getMessage();
};

#endif // message





