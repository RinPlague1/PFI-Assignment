#pragma once



#ifndef _TIMER_
#define _TIMER_
struct Timer
{
	Timer(double _duration);
	~Timer();
	static void on_tick();

private:
	void* m_userdata;
	double m_duration;
	static void tick(void* _userdata);
};

#endif