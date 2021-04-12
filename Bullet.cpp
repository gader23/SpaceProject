#include "Bullet.h"
#include "graphics.h"

Bullet::Bullet(Vec2D InitBulletPosition)
	:position(Vec2D::Vec2D(InitBulletPosition.p_x,InitBulletPosition.p_y))
	
{
	
}

Bullet::~Bullet()
{
}

void Bullet::MoveBullet(float mov_x,float mov_y)
{
		position.p_x = position.p_x + mov_x *0.5;
		position.p_y = position.p_y + mov_y*0.5;
	
}

void Bullet::DrawBullet()
{
	DrawLine(position.p_x, position.p_y, position.p_x + 2, position.p_y + 2, GetRGB(255, 255, 255));
	
}
