#ifndef TEST_BULLET_H
#define TEST_BULLET_H
#include"Vec2D.h"

class Bullet
{
public:
	Bullet(Vec2D InitPosition);
	~Bullet();

	Vec2D position;
	void MoveBullet(float mov_x,float mov_y);
	void DrawBullet();
private:

};



#endif