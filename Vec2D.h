#ifndef TEST_VEC2D_H
#define TEST_VEC2D_H


class Vec2D
{
public:
	Vec2D(float x, float y);
	~Vec2D();

//Members of class
	float p_x;
	float p_y;

	Vec2D GetRotation(Vec2D point1, float angle);
	float init_p_x;
	float init_p_y;

};


#endif
