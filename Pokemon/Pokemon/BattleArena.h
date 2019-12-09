#pragma once
#include "Building.h"

enum BattleArenaStates {
	RIVALS_AVAILABLE = 0,
	NO_RIVALS_AVAILABLE = 1
};


class BattleArena : Building
{
public:
	
	BattleArena();

	BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int
		in_id, Point2D in_loc);


	
private:
	unsigned int max_num_rivals;
	//maximun number of rivals the battle arena can hold set to 3

	unsigned int num_rivals_remaining;
	//The number of rivals currently in this Battle Arena Initial value should be set to num_rivals

	double dollar_cost_per_fight;
	//The per fight cost in Pokemon Dollars

	unsigned int stamina_cost_per_fight;
	//Stamina cost for single battle in the arena

	unsigned int pokemon_count;
	//Number of pokemons inside the arena
};