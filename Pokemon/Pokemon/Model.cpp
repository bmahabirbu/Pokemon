#include "Model.h"
#include  "Rival.h"
#include  "BattleArena.h"
#include <stdlib.h>
#include <list> 
#include <iterator>
#include "Input_Handling.h"
using namespace std;

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

	Rival* Rival1 = new Rival(*battle_arena,"BigBubba", 5, 40, 5, 4, 15, 1, Point2D(15, 12));
	Rival* Rival2 = new Rival(*battle_arena,"Gun", 5, 10, 5, 4, 15, 2, Point2D(15, 12));
	Rival* Rival3 = new Rival(*battle_arena,"Monish", 5, 10, 5, 4, 15, 3, Point2D(15, 12));
	
	//add rival and Battle arena

/*
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
*/
	object_ptrs.push_back(Pokemon1);
	pokemon_ptrs.push_back(Pokemon1);

	object_ptrs.push_back(Pokemon2);
	pokemon_ptrs.push_back(Pokemon2);

	object_ptrs.push_back(PokemonCenter_1);
	centers_ptrs.push_back(PokemonCenter_1);

	object_ptrs.push_back(PokemonCenter_2);
	centers_ptrs.push_back(PokemonCenter_2);

	object_ptrs.push_back(PokemonGym_1);
	gym_ptrs.push_back(PokemonGym_1);

	object_ptrs.push_back(PokemonGym_2);
	gym_ptrs.push_back(PokemonGym_2);

	object_ptrs.push_back(battle_arena);
	battle_arena_ptrs.push_back(battle_arena);

	object_ptrs.push_back(Rival1);
	rival_ptrs.push_back(Rival1);
	
	object_ptrs.push_back(Rival2);
	rival_ptrs.push_back(Rival2);
	
	object_ptrs.push_back(Rival3);
	rival_ptrs.push_back(Rival3);

	active_ptrs = object_ptrs;
	cout << "Model default constructed" << endl;

}

Model::~Model()
{
	for (auto it=object_ptrs.begin(); it != object_ptrs.end(); ++it)
	{
		delete *it;
	}
	
	cout << "Model destructed" << endl;
}


BattleArena* Model::GetBattleArenaPtr(int id)
{
	for (auto it = battle_arena_ptrs.begin(); it != battle_arena_ptrs.end(); ++it)
	{
		if ((*it)->GetId() == id)
		{
			return *it;
		}
	}
}

Rival* Model::GetRivalPtr(int id)
{
	for (auto it = rival_ptrs.begin(); it != rival_ptrs.end(); ++it)
	{
		if ((*it)->GetId() == id)
			return *it;
	}
}

Pokemon* Model::GetPokemonPtr(int id)
{
	for (auto it = pokemon_ptrs.begin(); it != pokemon_ptrs.end(); ++it)
	{
		if ((*it)->GetId() == id)
			return *it;
	}
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
	for (auto it = centers_ptrs.begin(); it != centers_ptrs.end(); ++it)
	{
		if ((*it)->GetId() == id)
			return *it;
	}
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
	for (auto it = gym_ptrs.begin(); it != gym_ptrs.end(); ++it)
	{
		if ((*it)->GetId() == id)
			return *it;
	}
}

bool updatetrue = false;

bool Model::Update()
{
	time = time + 1;
	cout << "time " << time << endl;
	
	for (auto it = active_ptrs.begin(); it != active_ptrs.end(); it++)
	{
		if ((*it)->Update() == true)
		{
			updatetrue = true;;
		}
		
		if ((*it)->GetState() == 1 || (*it)->GetState() == 12) //iterate and update, also check if update is true	//and return true
		{

			//if ((it) == active_ptrs.end())
			//{
				//active_ptrs.pop_back();
				//cout << "yay" << endl;
				//break;
			//}
			
			it = active_ptrs.erase(it);	
			cout << "removed dead object" << endl;
		}
		
	
	}
	
	//for (auto it = rival_ptrs.begin(); it != rival_ptrs.end(); ++it)
	//{
		//if ((*it)->IsAlive() == false)
		//{
			//battle_arena_ptrs.front()->RemoveOneRival();
		//}
	//}

	unsigned int temp2 = 0;
	
	for (auto it = gym_ptrs.begin(); it != gym_ptrs.end(); ++it)
	{
		if((*it)->IsBeaten() == true)
		{
			temp2 += 1;
		}

		if(temp2 == gym_ptrs.size())
		{
			cout << "You win! All Pokemon Gyms have been beatened!" << endl;
			exit(0);
		}
		
	}

	unsigned int temp = 0;
	
	for (auto it = pokemon_ptrs.begin(); it != pokemon_ptrs.end(); ++it)
	{
		if((*it)->isExhausted() == true)
		{
			temp += 1;
		}
		
		if( temp == pokemon_ptrs.size())
		{
			cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
			exit(0);
		}
		
	}
	return updatetrue;
}

void Model::Display(View &view)
{
	view.Clear();

	for (auto it = object_ptrs.begin(); it != object_ptrs.end(); ++it)
	{
		if ((*it)->ShouldBeVisible() == false)
		{
			continue;
		}

		view.Plot((*it)); //plot all objects from array of pointers
	}
	view.Draw();
	//ShowStatus(); fix later
}


void Model::ShowStatus()
{
	for (auto it = object_ptrs.begin(); it != object_ptrs.end(); ++it)
	{
		(*it)->ShowStatus();
	}
}

void Model::ObjectMake(char type, int id, double x, double y)
{

		cout << "objects with default values" << endl;

		if (type == 'g' || type == 'G')
		{
			if (gym_ptrs.size() >= id)
			{
				throw Invalid_Input("Gym with this ID num already exists, even if not active");
			}

			if (id > 9 || id <= 0)
			{
				throw Invalid_Input("Do not enter an ID greater than 9 or 0/below");
			}

			PokemonGym* g1 = new PokemonGym(10, 1, 1.5, 3.3, id, Point2D(x, y));
			object_ptrs.push_back(g1);
			active_ptrs.push_back(g1);
			gym_ptrs.push_back(g1);
		}
		else if (type == 'c' || type == 'C')
		{
			if (centers_ptrs.size() >= id)
			{
				throw Invalid_Input("Center with this ID num already exists, even if not active");
			}

			if (id > 9 || id <= 0)
			{
				throw Invalid_Input("Do not enter an ID greater than 9 or 0/below");
			}

			PokemonCenter* c1 = new PokemonCenter(id, 2, 100, Point2D(x, y));
			object_ptrs.push_back(c1);
			active_ptrs.push_back(c1);
			centers_ptrs.push_back(c1);
		}

		else if (type == 'p' || type == 'p')
		{
			if (pokemon_ptrs.size() >= id)
			{
				throw Invalid_Input("Pokemon with this ID num already exists, even if not active");
			}

			if (id > 9 || id <= 0)
			{
				throw Invalid_Input("Do not enter an ID greater than 9 or 0/below");
			}

			Pokemon* p1 = new Pokemon("Default Pokemon", id, 'P', 2, Point2D(x, y));
			object_ptrs.push_back(p1);
			active_ptrs.push_back(p1);
			pokemon_ptrs.push_back(p1);

		}

		else if (type == 'r' || type == 'R')
		{
			cout << "This rival will merely be put into the Battle Arena, not to the specified location" << endl;

			if (id < rival_ptrs.size())
			{
				throw Invalid_Input("Rival with ID num already exists, even if not active");
			}

			if (id > 9 || id <= 0)
			{
				throw Invalid_Input("Do not enter an ID greater than 9 or 0/below");
			}

			// code only works for 1 battle arena
			Rival* rnew = new Rival(*battle_arena_ptrs.front(), "BigBubba", 5, 40, 5, 4, 15, 1, Point2D(15, 12));
			(battle_arena_ptrs.front())->AddOneRival();
			object_ptrs.push_back(rnew);
			active_ptrs.push_back(rnew);
			rival_ptrs.push_back(rnew);
		}

}


