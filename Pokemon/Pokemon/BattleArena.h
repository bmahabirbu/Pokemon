#pragma once
#include "Building.h"
#include "GameObject.h"
#include  "Point2D.h"

enum BattleArenaStates {
	RIVALS_AVAILABLE = 0,
	NO_RIVALS_AVAILABLE = 1
};


class BattleArena : public Building
{
public:
	
	BattleArena();

	BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int
		in_id, Point2D in_loc);

	unsigned int GetNumRivalsRemaining();
	//Returns the number of rivals remaining in this Battle Arena.

	bool HasEnoughRivals();
	//Returns true if this Battle Arena contains at least one rival.
	//Returns false otherwise.

	double GetDollarCost();
	//Returns the cost of one battle in the arena.

	unsigned int GetStaminaCost();
	//Returns the amount of stamina required for battle

	bool IsAbleToFight(double budget, unsigned int stamina);
	//Returns true if a Pokemon with a given budget and stamina can request to fight
	//Returns false otherwise

	bool Update();
	//Returns false if rivals still remain within the BattleArena.
	//This function shouldn�t keep returning true if the BattleArena has no rivals left. It
	//should return true ONLY at the time when the BattleArena has 0 rivals left, and
		//return false for later �Update()� function calls

	bool IsBeaten();
	//Returns true if num_rivals_remaining == 0

	void ShowStatus();

	void RemoveOneRival();

	void AddOneRival();
	

	
private:
	unsigned int max_num_rivals;
	//maximun number of rivals the battle arena can hold set to 3

	unsigned int num_rivals_remaining;
	//The number of rivals currently in this Battle Arena Initial value should be set to max_num_rivals

	double dollar_cost_per_fight;
	//The per fight cost in Pokemon Dollars

	unsigned int stamina_cost_per_fight;
	//Stamina cost for single battle in the arena

	unsigned int pokemon_count;
	//Number of pokemons inside the arena
};