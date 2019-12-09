#pragma once
#ifndef _Point2D_h
#define _Point2D_h
#include <iostream>
#include "Vector2D.h"
using namespace std;

class Point2D
{
public:
	double x;
	double y;
	Point2D();
	Point2D(double in_x, double in_y);  
};

ostream& operator<<(ostream & out, Point2D p);

Point2D operator+(Point2D p1, Point2D p2);

Vector2D operator-(Point2D p1, Point2D p2);

double GetDistanceBetween(Point2D p1, Point2D p2);

#endif