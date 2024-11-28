#include "Timer.h"

#include <FL/FL.h>

void Timer::tick(void* _userdata)
{
	printf("Tick!\n");
	Fl::repeat_timeout(1.0, on_tick, _userdata);
}
Timer::Timer(double _duration)
{
	Fl::add_timeout(_duration, on_tick, this);
}
Timer::~Timer()
{
	Fl::remove_timeout(on_tick, this);
}

void Timer::on_tick() {}