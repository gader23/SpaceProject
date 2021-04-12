#include "Clock.h"
#include "graphics.h"
#include "time.h"
#include <math.h>


Clock::Clock(Vec2D pos,int size)
	:position(pos)
	,m_hr(Vec2D(0,0))
	,m_min(Vec2D(0, 0))
	,m_sec(Vec2D(0, 0))
	,m_size(size/2)
	,m_movx(1)
	,m_movy(1)
{
}

Clock::~Clock()
{
}

void Clock::DrawClock()
{
	DrawLine(position.p_x - m_size, position.p_y - m_size, position.p_x + m_size, position.p_y - m_size, GetRGB(255, 0, 0));
	DrawLine(position.p_x - m_size, position.p_y - m_size, position.p_x - m_size, position.p_y + m_size, GetRGB(255, 0, 0));
	DrawLine(position.p_x + m_size, position.p_y - m_size, position.p_x + m_size, position.p_y + m_size, GetRGB(255, 0, 0));
	DrawLine(position.p_x - m_size, position.p_y + m_size, position.p_x + m_size, position.p_y + m_size, GetRGB(255, 0, 0));
	DrawLine(position.p_x,position.p_y,position.p_x+m_hr.p_x,position.p_y+m_hr.p_y,GetRGB(255,255,255));
	DrawLine(position.p_x, position.p_y,position.p_x+m_min.p_x,position.p_y+m_min.p_y,GetRGB(0,255,0));
	DrawLine(position.p_x, position.p_y,position.p_x+m_sec.p_x,position.p_y+m_sec.p_y,GetRGB(0,0,255));
}

void Clock::MoveClock(static const float pi,int height, int width)
{
	int hr, minu, sec;
	GetTime(hr, minu, sec);
	m_hr.p_x = (m_size-(m_size/3))*cos((-90 + hr *360/12) * pi / 180);
	m_hr.p_y= (m_size - (m_size/3)) * sin((-90 + hr * 360/12) * pi / 180);
	m_min.p_x = (m_size - (m_size/2)) * cos((-90 + minu * 6) * pi / 180);
	m_min.p_y = (m_size - (m_size/2)) * sin((-90 + minu * 6) * pi / 180);
	m_sec.p_x = m_size  * cos((90 + sec * 6) * pi / 180);
	m_sec.p_y = m_size  * sin((90 + sec * 6) * pi / 180);
	if (position.p_x >=width-m_size || position.p_x<=m_size)
	{
		m_movx = m_movx * -1;
	}
	if (position.p_y >= height-m_size || position.p_y <= m_size)
	{
		m_movy = m_movy * -1;
	}
	position.p_x = position.p_x + m_movx;
	position.p_y = position.p_y + m_movy;
}

void Clock::CheckClockCollision(Clock OtherPosition)
{
 
	if (position.p_x+m_size>=OtherPosition.position.p_x-OtherPosition.m_size&&position.p_x-m_size<=OtherPosition.position.p_x+OtherPosition.m_size&&position.p_y+m_size>=OtherPosition.position.p_y-OtherPosition.m_size&&position.p_y-m_size<=OtherPosition.position.p_y+m_size)
	{
		m_movx = m_movx * -1;
		m_movy = m_movx * -1;
		OtherPosition.m_movx = OtherPosition.m_movx * -1;
		OtherPosition.m_movy = OtherPosition.m_movy * -1;
	}
}
