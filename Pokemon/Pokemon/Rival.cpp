#include "Rival.h"
#include "Point2D.h"
#include  "GameObject.h"
#include  "Building.h"
#include  "BattleArena.h"

Rival::Rival(BattleArena arena)
{
	health = 20;
	physical_damage = 5;
	magical_damage = 4;
	defense = 15;
	agility = 5;
	is_in_arena = true;
	current_arena = &arena;
	cout << "Rival default constructed" << endl;
}

Rival::Rival(BattleArena arena, string name, double speed, double hp, double phys_dmg, double
	magic_dmg, double def, int id, Point2D in_loc) : GameObject(in_loc, id, 'R') 
{
	tag = name;
	agility = speed;
	health = hp;
	physical_damage = phys_dmg;
	magical_damage = magic_dmg;
	defense = def;
	is_in_arena = true;
	current_arena = &arena;
	cout << "Rival constructed" << endl;
}

void Rival::TakeHit(double physical_damage, double magical_damage, double defense) //same as pokemon class
{
	double attack;
	int phy_or_mag = rand() % 2 + 1;
	if (phy_or_mag == 1)
	{
		attack = physical_damage;
		cout << "Rival took physical attack" << endl;
	}
	else
	{
		attack = magical_damage;
		cout << "Rival took magical attack" << endl;
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
	if (IsAlive() == true)
	{
		state = ALIVE_RIVAL;
		ShowStatus();
		return false;
	}
	else
	{
		state = FAINTED_RIVAL;
		current_arena->RemoveOneRival();
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
		cout << "\t Health: " << get_health() << endl;
		cout << "\t Physical damage: " << get_phys_dmg() << endl;
		cout << "\t Magical damage: " << get_magic_dmg() << endl;
		cout << "\t defense: " << get_defense() << endl;
		}
		break;
		
	case FAINTED_RIVAL:
		{
		cout << "Rival " << get_name() << " has fainted" << endl;
		cout << "\t Health: " << get_health() << endl;
		}
		break;

	default :
		cout << "Something went wrong" << endl;
	}
}

bool Rival::ShouldBeVisible()
{
	return true;
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



