#include "Timer.h"

#include <FL/FL.h>



Timer::Timer(float _duration) : m_duration(_duration)
{
	
	Fl::add_timeout(_duration, tick, this);
}
Timer::~Timer()
{
	Fl::remove_timeout(tick, this);
}


void Timer::tick(void* _userdata)
{
	Timer* self = (Timer*)_userdata;
	
	self->on_tick();
	Fl::repeat_timeout(self->m_duration, tick, _userdata);
}

void Timer::on_tick() {}