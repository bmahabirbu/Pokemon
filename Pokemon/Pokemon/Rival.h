#pragma once
#include "Point2D.h"
#include "GameObject.h"
#include "BattleArena.h"
#include  <string>

enum RivalStates //create states for rival
{
	ALIVE_RIVAL = 0,
	FAINTED_RIVAL = 1
};

class Rival : public GameObject
{
	
public:

	Rival(BattleArena arena);
	
	Rival(BattleArena arena, string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc);

	//functions

	void TakeHit(double physical_damage, double magical_damage, double defense);

	double get_phys_dmg();

	double get_magic_dmg();

	double get_defense();

	string get_name();
	
	double get_health();

	bool Update();

	void ShowStatus();

	bool ShouldBeVisible();

	bool IsAlive(); //sees if rival is alive

	
protected:

	double health;
	//value 20;

	double physical_damage;
	//value 5

	double magical_damage;
	//value 4

	double defense;
	//It will parry percentage of the attack that Rival received.

	bool is_in_arena;
	//Returns true if the rival inside the arena

	BattleArena* current_arena;
	//Holds the current arena

	string tag;

	double agility;

};