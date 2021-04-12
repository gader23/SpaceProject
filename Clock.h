#ifndef TEST_CLOCK_H
#define TEST_CLOCK_H
#include "Vec2D.h"


class Clock
{
public:
	Clock(Vec2D pos,int size);
	~Clock();

	Vec2D position;

	void DrawClock();
	void MoveClock(static const float pi, int height, int width);
	void CheckClockCollision(Clock OtherPosition);
private:
	Vec2D m_hr, m_min,m_sec;
public:
	int m_size;
	int m_movx, m_movy;
};



#endif