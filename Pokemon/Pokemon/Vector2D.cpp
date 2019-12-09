#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include <cmath>
using namespace std;

Vector2D::Vector2D()
{
	x = 0;
	y = 0;
}

Vector2D::Vector2D(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

Vector2D operator*(Vector2D v1, double d)
{
	Vector2D v2;
	v2.x = v1.x * d;
	v2.y = v1.y * d;
	return v2;
}

Vector2D operator/(Vector2D v1, double d)
{
	Vector2D v2;
	v2.x = v1.x / d;
	v2.y = v1.y / d;
	return v2;
}

ostream& operator<<(ostream & out, Vector2D v)
{
	return out << v.x  << " " << v.y << endl;
}