#include "C_Application.h"
#include "graphics.h"
#include <math.h>
#include "time.h"



static const float k_PI = 3.1415926536f;


C_Application::C_Application(int screenWidth, int screenHeight)
	: m_ScreenWidth(screenWidth)
	, m_ScreenHeight(screenHeight)
	, m_PositionY(100)
	, m_InitPoint(m_ScreenWidth / 2, (m_ScreenHeight - m_PositionY) + 30)
	, m_point1(m_ScreenWidth / 2, m_ScreenHeight - m_PositionY)
	, m_point2(m_point1.p_x - 10, m_point1.p_y + 30)
	, m_point3(m_point1.p_x + 10, m_point1.p_y + 30)
	
	
{
	//Create two clocks
	Vec2D Clockpos = Vec2D(rand()%750 +50, rand()%400+50);
	Clock c1 = Clock(Clockpos,100);
	clocks.push_back(c1);
	Clockpos = Vec2D(rand() % 750 + 50, rand() % 400 + 50);
	Clock c2 = Clock(Clockpos, 100);
	clocks.push_back(c2);
}


C_Application::~C_Application()
{

}


void C_Application::Tick(T_PressedKey pressedKeys)
{
	// Sample tick

	// Clear screen on cannon position

	FillRect(0, 0, 800, 600, GetRGB(0, 0, 0));
	
	

	// Key processing

	if(pressedKeys & s_KeyLeft)
	{
		//m_CannonX = min(0, m_CannonX-4);
		Vec2D m_p1=rotation(m_point1.p_x, m_point1.p_y,-90);
		m_point1.p_x = m_p1.p_x;
		m_point1.p_y = min(m_point1.GetRotation(m_InitPoint,-90).p_y, m_p1.p_y);
		if (m_point1.p_y == m_point1.GetRotation(m_InitPoint, -90).p_y)
			{
				m_point1.p_x = m_point1.GetRotation(m_InitPoint, -90).p_x;
			}
		Vec2D m_p2= rotation(m_point2.p_x, m_point2.p_y, -90);
		m_point2.p_x = min(m_point2.GetRotation(m_InitPoint, -90).p_x, m_p2.p_x);
		m_point2.p_y = m_p2.p_y;
		if (m_point2.p_x == m_point2.GetRotation(m_InitPoint, -90).p_x)
			{
				m_point2.p_y = m_point2.GetRotation(m_InitPoint, -90).p_y;
			}
		
		Vec2D m_p3= rotation(m_point3.p_x, m_point3.p_y, -90);
		m_point3.p_x = max(m_point3.GetRotation(m_InitPoint, -90).p_x, m_p3.p_x);
		m_point3.p_y = m_p3.p_y;
		if (m_point3.p_x == m_point3.GetRotation(m_InitPoint, -90).p_x)
			{
				m_point3.p_y = m_point3.GetRotation(m_InitPoint, -90).p_y;
			}
		
	}

	if(pressedKeys & s_KeyRight)
	{
		//m_CannonX = max(m_ScreenWidth, m_CannonX+4);
	
		Vec2D m_p1 = rotation(m_point1.p_x, m_point1.p_y, 90);
		m_point1.p_x = m_p1.p_x;
		m_point1.p_y = min(m_point1.GetRotation(m_InitPoint,90).p_y, m_p1.p_y);
		if (m_point1.p_y == m_point1.GetRotation(m_InitPoint, 90).p_y)
		{
			m_point1.p_x = m_point1.GetRotation(m_InitPoint, 90).p_x;
		}
		Vec2D m_p2 = rotation(m_point2.p_x, m_point2.p_y, 90);
		m_point2.p_x = min(m_point2.GetRotation(m_InitPoint, 90).p_x, m_p2.p_x);
		m_point2.p_y = m_p2.p_y;
		if (m_point2.p_x == m_point2.GetRotation(m_InitPoint, 90).p_x)
		{
			m_point2.p_y = m_point2.GetRotation(m_InitPoint, 90).p_y;
		}
		Vec2D m_p3 = rotation(m_point3.p_x, m_point3.p_y, 90);
		m_point3.p_x = max(m_point3.GetRotation(m_InitPoint, 90).p_x, m_p3.p_x);
		m_point3.p_y = m_p3.p_y;
		if (m_point3.p_x == m_point3.GetRotation(m_InitPoint, 90).p_x)
		{
			m_point3.p_y = m_point3.GetRotation(m_InitPoint, 90).p_y;
		}
		
	}

	if(pressedKeys & s_KeyUp)
	{
		//m_CannonY = max(0, m_CannonY-4);
	}

	if(pressedKeys & s_KeyDown)
	{
		//m_CannonY = min(m_ScreenHeight, m_CannonY+4);
	}

	if(pressedKeys & s_KeySpace)
	{
			Bullet b=Bullet(m_point1);
			bullets.push_back(b);
		
	}

	// Draw cannon

	DrawLine(m_point1.p_x,   m_point1.p_y,   m_point2.p_x, m_point2.p_y, GetRGB(0, 255,   0));
	DrawLine(m_point1.p_x, m_point1.p_y,    m_point3.p_x, m_point3.p_y, GetRGB(  0, 255,   0));
	DrawLine(m_point2.p_x, m_point2.p_y, m_point3.p_x, m_point3.p_y, GetRGB(  0, 255,0));
	// Draw bullets
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].MoveBullet(bullets[i].position.init_p_x-m_point1.init_p_x, bullets[i].position.init_p_y- m_point1.GetRotation(m_InitPoint, 90).p_y);
		bullets[i].DrawBullet();
		if (bullets[i].position.p_x<0 || bullets[i].position.p_x>m_ScreenWidth || bullets[i].position.p_y < 0)
		{
			bullets.erase(bullets.begin() + i);
		}
	}
	//Check the collision
	CheckBulletCollision();
	CheckCollisionClock();
	//Draw Clock
	for (int i = 0; i < clocks.size(); i++) {
		
		clocks[i].MoveClock(k_PI,m_ScreenHeight,m_ScreenWidth);
		clocks[i].DrawClock();
	}
}

Vec2D C_Application::rotation(float &x, float &y,int angle)
{
	float x1=0,y1=0,x2=0,y2 = 0;
	float rot = ((k_PI * angle) / 180.f)*0.05;
		
	x1 = x - m_InitPoint.p_x;
	y1 = y - m_InitPoint.p_y;
	x2 = (x1 * cos(rot)) - (y1 * sin(rot));
	y2 = (x1 * sin(rot)) + (y1 * cos(rot));
	x2 = x2 + m_InitPoint.p_x;
	y2 = y2 + m_InitPoint.p_y;
	Vec2D r(x2, y2);
	return r;
}

void C_Application::CheckCollisionClock()
{
	for (int i = 0; i < clocks.size(); i++)
	{
		for (int j = 0; j < clocks.size(); j++)
		{
			if (i != j)
			{
				clocks[i].CheckClockCollision(clocks[j]);
			}
		}
	}
}

void C_Application::CheckBulletCollision()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < clocks.size(); j++)
		{
			if (bullets[i].position.p_x+3 >= clocks[j].position.p_x - clocks[j].m_size && bullets[i].position.p_x <= clocks[j].position.p_x + clocks[j].m_size && bullets[i].position.p_y+3 >= clocks[j].position.p_y - clocks[j].m_size && bullets[i].position.p_y <= clocks[j].position.p_y + clocks[j].m_size)
			{
				bulletsRemoved.push_back(i);
				clocksRemoved.push_back(j);

			}
		}
	}
	if (bulletsRemoved.size() > 0)
	{
	
		for (int i = 0; i < bulletsRemoved.size(); i++)
		{
			if(bulletsRemoved[i]<= bullets.size()-1)
			bullets.erase(bullets.begin() + bulletsRemoved[i]);
		}
		
	}
	bulletsRemoved.clear();
	if (clocksRemoved.size() > 0)
	{
		for (int i = 0; i < clocksRemoved.size(); i++)
		{
			if (clocksRemoved[i] <= bullets.size() - 1) {
				Vec2D Clockpos(clocks[clocksRemoved[i]].position);
				int size = clocks[clocksRemoved[i]].m_size;

				clocks.erase(clocks.begin() + clocksRemoved[i]);
				if (size >= 12) {
					Clock c1 = Clock(Clockpos, size / 2);
					c1.m_movx = c1.m_movx * -1;
					c1.m_movy = c1.m_movy * -1;
					clocks.push_back(c1);

					Clock c2 = Clock(Vec2D(Clockpos.p_x + (size / 2)+1, Clockpos.p_y), size / 2);
					clocks.push_back(c2);
				}
			}
		}
		clocksRemoved.clear();
	}
	if (clocks.size() == 0)
	{
		Vec2D Clockpos = Vec2D(rand() % 650 + 50, rand() % 300 + 50);
		Clock c1 = Clock(Clockpos, 100);
		clocks.push_back(c1);
		Clockpos = Vec2D(rand() % 650 + 50, rand() % 300 + 50);
		Clock c2 = Clock(Clockpos, 100);
		clocks.push_back(c2);
	}
	
}


