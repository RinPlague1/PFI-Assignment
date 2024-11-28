#pragma once

#include "Timer.h"


#ifndef _SERVER_OBJ_
#define _SERVER_OBJ_
class Server : Timer
{
	Server();
	~Server();
	void on_tick();

};

#endif