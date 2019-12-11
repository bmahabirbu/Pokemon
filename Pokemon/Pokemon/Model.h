#pragma once
#include "Pokemon.h"
#include "View.h"
#include <list> 
#include <iterator>
using namespace std;

class Model
{
public:
	Model(); //constructor
	//Model(const Model &old_object); //copy contructor
	~Model(); //destructor

	Pokemon* GetPokemonPtr(int id); // 3 functions
	PokemonCenter* GetPokemonCenterPtr(int id);
	PokemonGym* GetPokemonGymPtr(int id);
	BattleArena* GetBattleArenaPtr(int id);
	Rival* GetRivalPtr(int id);

	bool Update(); //Update, View, Showstatus

	void Display(View &view);

	void ShowStatus();


private:

	//Model(const Model &old_object); //copy contructor
	int time; //variables
	
	list <GameObject*> object_ptrs;
	//int num_objects;
	
	list <Pokemon*> pokemon_ptrs;
	//int num_pokemon;
	
	list <PokemonCenter*> centers_ptrs;
		//int num_centers;

	list <PokemonGym*> gym_ptrs;
	//int num_gym;
	
	list <BattleArena*> battle_arena_ptrs;
	//int num_arenas;
	
	list <Rival*> rival_ptrs;
	//int num_rivals;

	list <GameObject*> active_ptrs;
	
};