#include "Timer.h"

#include <FL/FL.h>

Timer::Timer(float _duration) : m_duration(_duration)
{
	
	Fl::add_timeout(_duration, tick, this);	// creates a timer that ticks every interval set - 60per second
}

Timer::~Timer()
{
	Fl::remove_timeout(tick, this);
}

void Timer::tick(void* _userdata)
{
	Timer* self = (Timer*)_userdata;
	
	self->on_tick();
	Fl::repeat_timeout(self->m_duration, tick, _userdata);	//calls on tick on each interval
}

void Timer::on_tick() {} //overridden by client and server