#pragma once
#include "Pokemon.h"
#include "View.h"

class Model
{
public:
	Model(); //constructor
	//Model(const Model &old_object); //copy contructor
	~Model(); //destructor

	Pokemon* GetPokemonPtr(int id); // 3 functions
	PokemonCenter* GetPokemonCenterPtr(int id);
	PokemonGym* GetPokemonGymPtr(int id);

	bool Update(); //Update, View, Showstatus

	void Display(View &view);

	void ShowStatus();

private:

	//Model(const Model &old_object); //copy contructor
	int time; //variables
	GameObject* object_ptrs[10];
	int num_objects;
	Pokemon* pokemon_ptrs[10];
	int num_pokemon;
	PokemonCenter* centers_ptrs[10];
	int num_centers;
	PokemonGym* gym_ptrs[10];
	int num_gym;
};