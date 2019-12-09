#pragma once
#ifndef _Building_h
#define _Building_h
#include "GameObject.h"
#include <iostream>
using namespace std;

class Building : public GameObject //inhertis from gameobject
{
private: // create pokemon count and contructor in private 
	unsigned int pokemon_count; 
public:
	Building();
	Building(char in_code, int in_Id, Point2D in_loc);
	void AddOnePokemon();
	void RemoveOnePokemon();
	void ShowStatus();
	bool ShouldBeVisible();
};
#endif