#pragma once

#include "GameObject.h"
#include "BattleArena.h"
#include <string>

enum RivalStates //create states for rival
{
	ALIVE_RIVAL = 0,
	FAINTED_RIVAL = 1
};

class Rival : GameObject
{
public:

	Rival();
	
	Rival(string name, double speed, double hp, double phys_dmg, double
		magic_dmg, double def, int id, Point2D in_loc);

	//functions

	void TakeHit(double physical_damage, double magical_damage, double defense);

	double get_phys_dmg();

	double get_magic_dmg();

	double get_defense();

	string get_name();

	string namu;
	
	double get_health();

	bool Update();

	void ShowStatus();

	bool IsAlive();
	
	
protected:

	double health;
	//value 20;

	double physical_damage;
	//value 5

	double magical_damage;
	//value 4

	double defense;
	//It will parry percentage of the attack that Rival received.

	double stamina_cost_per_fight;
	//per fight cost in stamina

	bool is_in_arena;
	//Returns true if the rival inside the arena

	BattleArena* current_arena;
	//Holds the current arena

	string tag;

	double agility;

	
};