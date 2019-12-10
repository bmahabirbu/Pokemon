#include "Rival.h"
#include <iostream>
#include <string>
using namespace std;


Rival::Rival()
{
	health = 20;
	physical_damage = 5;
	magical_damage = 4;
	defense = 15;
	is_in_arena = true;
	//current arena
	cout << "Rival default constructed" << endl;
}

Rival::Rival(string name, double speed, double hp, double phys_dmg, double
	magic_dmg, double def, int id, Point2D in_loc) : GameObject(in_loc, id, 'R')
{
	tag = name;
	agility = speed;
	health = hp;
	physical_damage = phys_dmg;
	magical_damage = magic_dmg;
	defense = def;
	is_in_arena = true;

//not sure if to define this or not
	//id_num = id;
	//location = in_loc;
	//display_code = 'R';
	cout << "Rival constructed" << endl;
}

void Rival::TakeHit(double physical_damage, double magical_damage, double defense) //same as pokemon class
{
	double attack;
	int phy_or_mag = rand() % 2 + 1;
	if (phy_or_mag == 1)
	{
		attack = physical_damage;
	}
	else
	{
		attack = magical_damage;
	}

	health -= (100.0 - defense) / 100 * attack;
}

double Rival::get_phys_dmg()
{
	return physical_damage;
}

double Rival::get_magic_dmg()
{
	return magical_damage;
}

double Rival::get_defense()
{
	return defense;
}

string Rival::get_name()
{
	return tag;
}

double Rival::get_health()
{
	return health;
}

bool Rival::Update()
{
	if (health > 0)
	{
		state = ALIVE_RIVAL;
		ShowStatus();
		return false;
	}
	else
	{
		state = FAINTED_RIVAL;
		ShowStatus();
		return true;
	}
}

void Rival::ShowStatus()
{
	cout << "Rival status..." << endl;
	switch (state)
	{
	case ALIVE_RIVAL:
		{
		cout << "Rival " << get_name() << " is alive and well" << endl;
		}
		break;
		
	case FAINTED_RIVAL:
		{
		cout << "Rival " << get_name() << " has fainted" << endl;
		}
		break;

	default :
		cout << "Something went wrong" << endl;
	}
}

bool Rival::IsAlive()
{
	if (health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


