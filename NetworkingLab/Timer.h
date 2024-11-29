#pragma once

#ifndef _TIMER_
#define _TIMER_
struct Timer
{

	virtual void on_tick();
	Timer(float _duration);
	~Timer();
	

private:
	void* m_userdata;
	float m_duration;
	static void tick(void* _userdata);
};

#endif