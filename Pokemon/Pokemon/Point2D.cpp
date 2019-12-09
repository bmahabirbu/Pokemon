#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include <cmath>
using namespace std;

Point2D::Point2D()
{
	x = 0;
	y = 0;
}

Point2D::Point2D(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

ostream& operator<<(ostream & out, Point2D p)
{
	return out << p.x  << " " << p.y << endl;
}

Point2D operator+(Point2D p1, Point2D p2)
{
	Point2D p3;
	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	return p3;

}

Vector2D operator-(Point2D p1, Point2D p2)
{
	Vector2D v;
	v.x = p1.x - p2.x;
	v.y = p1.y - p2.y;
	return v;
}

double GetDistanceBetween(Point2D p1, Point2D p2)
{
	double xd = p2.x - p1.x;
	double yd = p2.y - p1.y;
	double distance = sqrt((pow(xd, 2) + pow(yd, 2)));
	return distance;
}