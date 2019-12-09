#include "PokemonCenter.h"

PokemonCenter::PokemonCenter()
{
	display_code = 'C';
	stamina_capacity = 100;
	id_num = 1;
	num_stamina_points_remaining = stamina_capacity;
	dollar_cost_per_stamina_point = 5;
	state = STAMINA_POINTS_AVAILABLE;
	cout << "PokemonCenter default contructed" << endl;
}

PokemonCenter::~PokemonCenter()
{
	cout << "PokemonCenter destructed" << endl;
}

PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc)
{
	id_num = in_id;
	dollar_cost_per_stamina_point = stamina_cost;
	stamina_capacity = stamina_cap;
	num_stamina_points_remaining = stamina_capacity;
	location = in_loc;
	display_code = 'C';
	state = STAMINA_POINTS_AVAILABLE;
	cout << "PokemonCenter contructed" << endl;
}

bool PokemonCenter::HasStaminaPoints()
{
	if (num_stamina_points_remaining > 0) //checks to see if stamina points is above 0
	{
		return true;
	}
	else
	{
		return false;
	}
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining()
{
	return num_stamina_points_remaining; //returns stamina points remaining
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
	if (budget >= (stamina_points*dollar_cost_per_stamina_point)) //gets the price sees if you have enough money
	{
		return true;
	}
	else
	{
		return false;
	}
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points)
{
	double price = stamina_points * dollar_cost_per_stamina_point; //returns the price
	return price;
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed)
{
	if (num_stamina_points_remaining >= points_needed)
	{
		num_stamina_points_remaining = num_stamina_points_remaining - points_needed;  //returns points needed and subtracts it from remaining stamina
		return points_needed;
	}
	if (num_stamina_points_remaining < points_needed)
	{
		int temp = num_stamina_points_remaining; //temp variable to return current remaining stamina
		num_stamina_points_remaining = 0; // sets the remaining stamina to 0 in the PokemonCenter
		return temp; //returns the current remaning stamina points
		
	}
	return 0;
}

bool PokemonCenter::Update()
{
	if (num_stamina_points_remaining == 0 && display_code == 'C')
	{
		state = NO_STAMINA_POINTS_AVAILABLE;
		display_code = 'c';
		cout << "PokemonCenter id number " << id_num << " has ran out of stamina points " << endl;
		return true;
	}
	if (num_stamina_points_remaining > 0 || display_code == 'c')
	{
		ShowStatus();
		return false;
	}
}

void PokemonCenter::ShowStatus()
{
	cout << "PokemonCenter Status: " << display_code << id_num << " located at " << location;
	Building::ShowStatus();
	cout << "\t Pokemon dollars per stamina point: " << dollar_cost_per_stamina_point << endl << " \t has "
		<< num_stamina_points_remaining << " stamina point(s) remaining" << endl;
}
