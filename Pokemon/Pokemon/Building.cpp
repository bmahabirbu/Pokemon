#include "Building.h"

Building::Building()
{
	pokemon_count = 0;
	display_code = 'B';
	id_num = 1;
	state = 0;
	cout << "Building default contructed" << endl;
}

Building::Building(char in_code, int in_Id, Point2D in_loc)
: GameObject(in_loc,in_Id,in_code)
//sets idnum displaycode and location
{
	pokemon_count = 0;
	id_num = in_Id;
	display_code = in_code;
	location = in_loc;
	cout << "Building  contructed" << endl;
}

void Building::AddOnePokemon()
{
	pokemon_count++;//increment pokemon count
}

void Building::RemoveOnePokemon()
{
	if(pokemon_count > 0)
	{
		pokemon_count--;//decrease pokemon count
	}
	
}

void Building::ShowStatus()
{
	cout <<  "\t" << pokemon_count << " pokemon is/are in this building" << endl; //printed statement with pokemon count
}

bool Building::ShouldBeVisible()
{
	return true; //alwyas return true 
}
