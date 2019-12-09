#pragma once
#ifndef _Vector2D_h
#define _Vector2D_h
#include <iostream>
#include "Point2D.h"
using namespace std;

class Vector2D
{
	public:
		double x;
		double y;
		Vector2D();
		Vector2D(double in_x, double in_y); 
};

Vector2D operator*(Vector2D v1, double d);

Vector2D operator/(Vector2D v1, double d);

ostream& operator<<(ostream & out, Vector2D v1);

#endif