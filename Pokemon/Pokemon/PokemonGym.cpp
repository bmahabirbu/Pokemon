#include "PokemonGym.h"

PokemonGym::PokemonGym()
{
	display_code = 'G';
	id_num = 1;
	state = NOT_BEATEN;
	max_number_of_training_units = 10;
	num_training_units_remaining = max_number_of_training_units;
	stamina_cost_per_training_unit = 1;
	dollar_cost_per_training_unit = 1;
	experience_points_per_training_unit = 2;
	cout << "PokemonGym default contructed" << endl;
}

PokemonGym::~PokemonGym()
{
	cout << "PokemonGym destructed" << endl;
}

PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost,
	unsigned int exp_points_per_unit, int in_id, Point2D in_loc)
{
	state = NOT_BEATEN;
	display_code = 'G';
	id_num = in_id;
	max_number_of_training_units = max_training_units;
	stamina_cost_per_training_unit = stamina_cost;
	num_training_units_remaining = max_number_of_training_units;
	experience_points_per_training_unit = exp_points_per_unit;
	dollar_cost_per_training_unit = dollar_cost;
	location = in_loc;
	cout << "PokemonGym contructed" << endl;
}

double PokemonGym::GetDollarCost(unsigned int unit_qty)
{
	double cost = unit_qty * dollar_cost_per_training_unit; //get cost of purchasing training units
	return cost;
}

unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty)
{
	unsigned int cost = unit_qty * stamina_cost_per_training_unit; //get stamina cost per training unit
	return cost;
}

unsigned int PokemonGym::GetNumTrainingUnitsRemaining()
{
	return num_training_units_remaining; //return training units remaining
}

bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)
{
	double Scost = unit_qty * stamina_cost_per_training_unit; //get stamina cost
	double Tcost = unit_qty * dollar_cost_per_training_unit; //get dollar cost
	if (budget >= Tcost && stamina >= Scost)
	{
		return true;
	}
	else
	{
		return false;
	}
}

unsigned int PokemonGym::TrainPokemon(unsigned int training_units)
{
	if (num_training_units_remaining >= training_units)
	{
		num_training_units_remaining -= training_units; //minus units remaining from units asked
		int totalexp = training_units * (experience_points_per_training_unit); //get exp
		return totalexp; 
	}
	else
	{
		int totalT = num_training_units_remaining; //units remaining equals total training units
		int totalexp = totalT * (experience_points_per_training_unit); //get exp
		num_training_units_remaining = 0; //no more training units
		return totalexp;
	}
}

bool PokemonGym::Update()
{
	if (num_training_units_remaining == 0 && display_code == 'G')
	{
		display_code = 'g';
		state = BEATEN;
		cout << display_code << id_num << " has been beaten" << endl;
		return true;
	}
	else
	{
		ShowStatus();
		return false;
	}
}

bool PokemonGym::IsBeaten()
{
	if (num_training_units_remaining == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PokemonGym::ShowStatus()
{
	cout << "Pokemon Gym Status " << display_code << id_num << " located at " << location;
	Building::ShowStatus();
	cout << "\t Max number of training units: "  << max_number_of_training_units << endl;
	cout << "\t Stamina cost per training unit: " << stamina_cost_per_training_unit << endl;
	cout << "\t Pokemon dollar per training unit: " << dollar_cost_per_training_unit << endl;
	cout << "\t Experience points per training unit: " << experience_points_per_training_unit << endl;
	cout << " \t" << num_training_units_remaining  <<
		" training unit(s) is/are remaining for this gym" << endl;
}

