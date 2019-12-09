#pragma once
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "BattleArena.h"
#include "Rival.h"
#include <string>
#include <ctime>

enum PokemonStates {
	STOPPED = 0,
	MOVING = 1,
	EXHAUSTED = 2,
	IN_GYM = 3,
	IN_CENTER = 4,
	MOVING_TO_GYM = 5,
	MOVING_TO_CENTER = 6,
	TRAINING_IN_GYM = 7,
	RECOVERING_STAMINA = 8,

	// new states
	
	IN_ARENA = 9,
	MOVING_TO_ARENA = 10,
	BATTLE = 11,
	FAINTED = 12,
};

class Pokemon : public GameObject
{
public: 
	Pokemon();
	~Pokemon();
	Pokemon(char in_code); // contructors
	Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed,
		Point2D in_loc);

	void ShowStatus(); //Show status function (most important)

	void StartMoving(Point2D dest); //Functions

	void StartMovingToCenter(PokemonCenter* center);

	void StartMovingToGym(PokemonGym* gym);

	void StartTraining(unsigned int num_training_units);

	void StartRecoveringStamina(unsigned int num_stamina_points);

	void Stop();

	bool isExhausted();

	string GetName();

	char GetDisplay_code();

	bool ShouldBeVisible();

	bool Update(); //update this function

	//new public members

	bool IsAlive();

	void TakeHit(double physical_damage, double magical_damage, double
		defense);
	void ReadyBattle(Rival *in_target);

	bool StartBattle();
	

protected:

	bool UpdateLocation();

	void SetupDestination(Point2D dest);//important for functions

	//new protected memebers

		double health;
		//Initial value is 20
	
		double store_health;
		//It will be same as health and will be used to restore health if pokemon wins the battle.
	
		double physical_damage;
		//Initial value is 5
	
		double magical_damage;
		//Initial value is 4
	
		double defense;
		//It will parry percentage of the attack that Pokemon received.
	
		Rival* target;
		//The rival that we will battle in the arena
	
		bool is_in_arena;
		//Returns true if the Pokemon inside the arena
	
		BattleArena* current_arena;
		//Holds the current arena

private:
	double speed;
	bool is_in_gym;
	bool is_in_center;
	unsigned int stamina;
	unsigned int experience_points;
	double pokemon_dollars;
	unsigned int training_units_to_buy;
	unsigned int stamina_points_to_buy;
	string name;
	PokemonCenter* current_center;
	PokemonGym* current_gym;
	Point2D destination;
	Vector2D delta;
};

double GetRandomAmountOfPokemonDollars();