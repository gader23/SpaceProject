#ifndef TEST_C_APPLICATION_H
#define TEST_C_APPLICATION_H

#include "Vec2D.h"
#include "Bullet.h"
#include "Clock.h"
#include <vector>
class C_Application
{
public:
	
	typedef unsigned int T_PressedKey;

	C_Application(int screenWidth, int screenHeight);
	~C_Application();

	/// Tick is called on fix framerate (50fps)
	void Tick(T_PressedKey pressedKeys);

	static const T_PressedKey s_KeyLeft  = 0x01;
	static const T_PressedKey s_KeyUp    = 0x02;
	static const T_PressedKey s_KeyRight = 0x04;
	static const T_PressedKey s_KeyDown  = 0x08;
	static const T_PressedKey s_KeySpace = 0x10;

private:

	const int	m_ScreenWidth;
	const int	m_ScreenHeight;
	//Variable to change the init position Y of the cannon

	int m_PositionY;

	// Members for cannon
	Vec2D m_InitPoint;
	Vec2D m_point1;
	Vec2D m_point2;
	Vec2D m_point3;
	
	// Vector of bullets
	std::vector<Bullet>bullets;
	//Vector of clocks
	std::vector<Clock>clocks;
	//Vector of objects to destroy
	std::vector<int>bulletsRemoved;
	std::vector<int>clocksRemoved;
	//Function to rotate the cannon
	Vec2D rotation(float &x, float &y, int angle);
	//Function to check when clock collision with other
	void CheckCollisionClock();
	//Fucntion to chec if bullet collision with a clock
	void CheckBulletCollision();
	
};

#endif // #ifndef TEST_C_APPLICATION_H
