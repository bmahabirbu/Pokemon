#include "Model.h"
#include  "Rival.h"
#include  "BattleArena.h"
#include <stdlib.h>
#include <list> 
#include <iterator>

Model::Model()
{
	time = -1;
	Pokemon* Pokemon1 = new Pokemon("Pikachu", 1, 'P', 2, Point2D(5, 1));
	Pokemon* Pokemon2 = new Pokemon("Bulbasaur", 2, 'P', 1, Point2D(10, 1));
	PokemonCenter* PokemonCenter_1 = new PokemonCenter(1, 1, 100, Point2D(1, 20));
	PokemonCenter* PokemonCenter_2 = new PokemonCenter(2, 2, 200, Point2D(10, 20));
	PokemonGym* PokemonGym_1 = new PokemonGym(10, 1, 2, 3, 1, Point2D(0,0));
	PokemonGym* PokemonGym_2 = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5, 5));
	//new objects rival and battlearena
	BattleArena* battle_arena = new BattleArena(5, 3, 4, 1, Point2D(15, 12));

	Rival* Rival1 = new Rival(*battle_arena,"Bubba", 5, 40, 5, 4, 15, 1, Point2D(15, 12));
	Rival* Rival2 = new Rival(*battle_arena,"kubba", 5, 10, 5, 4, 15, 1, Point2D(15, 12));
	Rival* Rival3 = new Rival(*battle_arena,"rubba", 5, 10, 5, 4, 15, 1, Point2D(15, 12));

	//add rival and Battle arena

	battle_arena_ptrs[0] = battle_arena;

	rival_ptrs[0] = Rival1;
	rival_ptrs[1] = Rival2;
	rival_ptrs[2] = Rival3;
	
	pokemon_ptrs[0] = Pokemon1; //sets Pointers to the array accordingly
	pokemon_ptrs[1] = Pokemon2;

	centers_ptrs[0] = PokemonCenter_1;
	centers_ptrs[1] = PokemonCenter_2;

	gym_ptrs[0] = PokemonGym_1;
	gym_ptrs[1] = PokemonGym_2;

	object_ptrs[0] = Pokemon1;
	object_ptrs[1] = Pokemon2;
	object_ptrs[2] = PokemonCenter_1;
	object_ptrs[3] = PokemonCenter_2;
	object_ptrs[4] = PokemonGym_1;
	object_ptrs[5] = PokemonGym_2;
	object_ptrs[6] = battle_arena;
	object_ptrs[7] = Rival1;
	object_ptrs[8] = Rival2;
	object_ptrs[9] = Rival3;

	num_objects = 10;
	num_pokemon = 2;
	num_centers = 2;
	num_gym = 2;
	num_rivals = 3;
	num_arenas = 1;

	cout << "Model default contructed" << endl;

}

Model::~Model()
{
	for (int i = 0; i < num_objects; i++)
	{
		delete object_ptrs[i];
	}
	
	cout << "Model destructed" << endl;
}

BattleArena* Model::GetBattleArenaPtr(int id)
{
	for (int i = 0; i < num_arenas; i++)
	{
		if (battle_arena_ptrs[i]->GetId() == id)
			return battle_arena_ptrs[i];
	}
}

Rival* Model::GetRivalPtr(int id)
{
	for (int i = 0; i < num_rivals; i++)
	{
		if (rival_ptrs[i]->GetId() == id)
			return rival_ptrs[i];
	}
}

Pokemon* Model::GetPokemonPtr(int id)
{
	for (int i = 0; i < num_pokemon; i++)
	{
		if (pokemon_ptrs[i]->GetId() == id)
			return pokemon_ptrs[i];
	}
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
	for (int i = 0; i < num_centers; i++)
	{
		if (centers_ptrs[i]->GetId() == id)
			return centers_ptrs[i];
	}
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
	for (int i = 0; i < num_gym; i++)
	{
		if (gym_ptrs[i]->GetId() == id)
			return gym_ptrs[i];
	}
}

bool Model::Update()
{
	time = time + 1;
	cout << "time " << time << endl;
	for (int i = 0; i < num_objects; i++)
	{
		
		if (object_ptrs[i]->Update() == true) //iterate and update, also check if update is true
			//and return true
		{
			return true;
		}
	
	}
	
	for (int i = 0; i < num_rivals; i++)
	{
		if (rival_ptrs[i]->IsAlive() == true)
		{
			battle_arena_ptrs[0]->RemoveOneRival();
		}
	}
	
	if (gym_ptrs[0]->IsBeaten() == true && gym_ptrs[1]->IsBeaten() == true)
	{
		cout << "You win! All Pokemon Gyms have been beatened!" << endl;
		exit(0);
	}

	if (pokemon_ptrs[0]->isExhausted() == true && pokemon_ptrs[1]->isExhausted() == true)
	{
		cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
		exit(0);
	}
		
}

void Model::Display(View &view)
{
	view.Clear();

	for (int i = 0; i < num_objects; i++)
	{
		if (object_ptrs[i]->ShouldBeVisible() == false)
		{
			continue;
		}

		view.Plot(object_ptrs[i]); //plot all objects from array of pointers
	}

	view.Draw();
}


void Model::ShowStatus()
{
	for (int i = 0; i < num_objects; i++)
	{
		object_ptrs[i]->ShowStatus();
	}
}


