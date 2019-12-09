#pragma once
#include "Pokemon.h"

const int view_maxsize = 20;

class View
{
public:

	View(); //contructor

	void Clear(); //functions

	void Plot(GameObject* ptr);

	void Draw();


private:

	int size;
	double scale;
	Point2D origin;
	char grid[view_maxsize][view_maxsize][2];

	bool GetSubscripts(int &out_x, int &out_y, Point2D location);//private function

	
};