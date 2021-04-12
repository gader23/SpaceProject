#include "Vec2D.h"
#include<math.h>

Vec2D::Vec2D(float x, float y)
	:p_x(x)
	,p_y(y)
{
	init_p_x = x;
	init_p_y = y;
}

Vec2D::~Vec2D()
{
}

Vec2D Vec2D::GetRotation(Vec2D point, float angle)
{
	Vec2D lineRotation(0, 0);
	if (angle > 0) {
		lineRotation.p_x = -(init_p_y - point.p_y) + point.p_x;
		lineRotation.p_y = (init_p_x - point.p_x) + point.p_y;
	}
	else
	{
		lineRotation.p_x = (init_p_y - point.p_y) + point.p_x;
		lineRotation.p_y = -(init_p_x - point.p_x) + point.p_y;
	}

	
	return lineRotation;
}


