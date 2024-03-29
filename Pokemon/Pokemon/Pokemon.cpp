#include "Pokemon.h"
#include <ctime>
#include<cstdlib>

Pokemon::Pokemon()
{
	speed = 5;
	cout << "Pokemon default contructed" << endl;
	destination = Point2D(0.0, 0.0);
	stamina = 20;
	is_in_gym = false;
	is_in_center = false; //fixed pa3
	is_in_arena = false;
	current_arena = nullptr;
	current_center = nullptr;
	current_gym = nullptr;
	experience_points = 0;
	pokemon_dollars = 0;
	training_units_to_buy = 0;
	stamina_points_to_buy = 0;
	state = STOPPED;
}

Pokemon::~Pokemon()
{
	cout << "Pokemon destructed" << endl;
}

Pokemon::Pokemon(char in_code)
{
	speed = 5;
	stamina = 20;
	is_in_gym = false;
	is_in_center = false; //fixed pa3
	is_in_arena = false;
	current_arena = nullptr;
	current_center = nullptr;
	current_gym = nullptr;
	experience_points = 0;
	pokemon_dollars = 0;
	training_units_to_buy = 0;
	stamina_points_to_buy = 0;
	state = STOPPED;
	display_code = in_code;
	cout << "Pokemon contructed" << endl;
	destination = Point2D(0.0, 0.0);
}

Pokemon::Pokemon(string in_name, int in_id, 
	char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc,in_id,in_code)
{
	stamina = 20;
	is_in_gym = false;
	is_in_center = false; //fixed pa3
	is_in_arena = false;
	current_arena = nullptr;
	current_center = nullptr;
	current_gym = nullptr;
	experience_points = 0;
	pokemon_dollars = 0; 
	training_units_to_buy = 0;
	stamina_points_to_buy = 0;
	speed = in_speed;
	name = in_name;
	id_num = in_id;
	display_code = in_code;
	location = in_loc;
	state = STOPPED;
	cout << "Pokemon constructed" << endl;
	destination = Point2D(0.0, 0.0);
	//update constructor
	health = 20;
	store_health = health;
	physical_damage = 5;
	magical_damage = 4;
	defense = 15;
	is_in_arena = false;
}

void Pokemon::ShowStatus()
{
	cout << name << " status: " << endl;
	GameObject::ShowStatus();
	

	switch (state)//switch statement to print information about the value of the state
	{
	case STOPPED: cout << "\t stopped" << endl;
		break;

	case MOVING: cout << "\t moving at a speed of " << speed << " to destination " << destination
		<< " at each step of " << delta << endl;
		break;

	case EXHAUSTED: cout << "\t exhausted" << endl;
		break;

	case MOVING_TO_CENTER: cout << "\t heading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed <<
		" at each step of " << delta << endl;
		break;

	case MOVING_TO_GYM:  cout << "\t heading to Pokemon Gym " << current_gym->GetId() << " at a speed of " << speed <<
		" at each step of " << delta << endl;
		break;
		
	case MOVING_TO_ARENA: cout << "\t heading to Battle Arena " << current_arena->GetId() << " at a speed of " << speed <<
		" at each step of " << delta << endl; //new addition
		break;

	case IN_CENTER: cout << "\t inside Pokemon Center " << current_center->GetId() << endl;
		break;

	case IN_GYM: cout << "\t inside Pokemon Gym " << current_gym->GetId() << endl;
		break;
	
	case IN_ARENA: cout << "\t inside Battle Arena " << current_arena->GetId() << endl; //new addition
		break;
		
	case FAINTED: cout << "\t fainted" << endl; //new addition
		break;

	case TRAINING_IN_GYM: cout << "\t Training in Pokemon Gym " << current_gym->GetId() << endl;
		break;

	case RECOVERING_STAMINA: cout << "\t recovering stamina in Pokemon Center " << current_center->GetId() << endl;
		break;
		
	case BATTLE: cout << "\t In Battle with Rival" << endl; //new addition
		break;
		
	default:
		cout << "\t something went wrong with the state" << endl;
	}
	
	cout << "\t pokedollars " << pokemon_dollars << endl;
	cout << "\t experience " << experience_points << endl;
	cout << "\t stamina " << stamina << endl;
	cout << "\t Health: " << health << endl;
	cout << "\t Physical damage: " << physical_damage << endl;
	cout << "\t Magical damage: " << magical_damage << endl;
	cout << "\t defense: " << defense << endl;
}

bool Pokemon::UpdateLocation()
{ 
	if (stamina == 0)
	{
		state = EXHAUSTED;
		cout << "I am exhausted and cant move" << endl;
		return false;
	}

	 if (destination.x <= location.x && destination.y >= location.y) //if walking in x is negative and y is positive
	{
		if (destination.x >= location.x + delta.x && destination.y <= location.y + delta.y) //checks to see if destination
			//is within one step away, then puts it to destination
		{
			stamina -= 1; //reduce stamina by one
			location = destination;
			pokemon_dollars += GetRandomAmountOfPokemonDollars(); //gain dollars
			cout << "Arrived (- +)" << endl;
			return true;
		}
	}

	 if (destination.x >= location.x && destination.y <= location.y) //if walking in x is positive and y is negative
	{
		if (destination.x <= location.x + delta.x && destination.y >= location.y + delta.y) //checks to see if destination
			//is within one step away, then puts it to destination
		{
			location = destination;
			stamina -= 1; //reduce stamina by one
			pokemon_dollars += GetRandomAmountOfPokemonDollars(); //gain dollars
			cout << "Arrived (+ -)" << endl;
			return true;
		}
	}

	 if (destination.x <= location.x && destination.y <= location.y) //if walking in x and y is both negative
	{
		if (destination.x >= location.x + delta.x && destination.y >= location.y + delta.y) //checks to see if destination
			//is within one step away, then puts it to destination
		{
			location = destination;
			stamina -= 1; //reduce stamina by one
			pokemon_dollars += GetRandomAmountOfPokemonDollars(); //gain dollars
			cout << "Arrived (-)" << endl;
			return true;
		}
	}
	 if (destination.x >= location.x && destination.y >= location.y)// if walking in x and y is both positive
	{
		if (destination.x <= location.x + delta.x && destination.y <= location.y + delta.y) //checks to see if destination
			//is within one step away, then puts it to destination
		{
			location = destination;
			stamina -= 1; //reduce stamina by one
			pokemon_dollars += GetRandomAmountOfPokemonDollars(); //gain dollars
			cout << "Arrived (+)" << endl;
			return true;
		}
	}
	 if (location.x == destination.x && location.y == destination.y) //checks to see if destination = location
	{
		cout << display_code << id_num << ": I'm there!" << endl;
		return true;
	}
	else //move one step
	{
		location.x = location.x + delta.x; //move pokemon by one delta per step
		location.y = location.y + delta.y;
		stamina -= 1;
		pokemon_dollars += GetRandomAmountOfPokemonDollars();
		cout << display_code << id_num << ": step..." << endl;
		return false;
	}
}

void Pokemon::SetupDestination(Point2D dest)
{
	destination = dest;
	delta = (dest - location) * (speed / GetDistanceBetween(dest, location));
}

void Pokemon::StartMoving(Point2D dest)
{
	state = MOVING;
	SetupDestination(dest);
	if (dest.x == location.x && dest.y == location.y)
	{
		cout << display_code << id_num << ": I'm already there. See?" << endl;
	}
	else if (stamina == 0)
	{
		cout << display_code << id_num << ": I am exhausted. I may move but you cannot see me." << endl;
		state = EXHAUSTED;
	}
	else
	{
		cout << display_code << id_num << " On my way" << endl;
	}
}

void Pokemon::StartMovingToCenter(PokemonCenter* center)
{

	if (location.x == center->GetLocation().x && location.y == center->GetLocation().y)
	{
		cout << display_code << id_num << ": I'm already at the Pokemon Center!" << endl;
	}
	else if (stamina == 0)
	{
		cout << display_code << id_num << ": I am exhausted so I cant move to recover stamina..." << endl;
		state = EXHAUSTED;
	}
	else
	{
		cout << display_code << id_num << " On my way to the Pokemon Center" << endl;
		state = MOVING_TO_CENTER;
		SetupDestination(center->GetLocation());
		current_center = center; //sets the pokemon center location to the pokemons center destination pointer
	}
}

void Pokemon::StartMovingToGym(PokemonGym * gym)
{
	if (location.x == gym->GetLocation().x && location.y == gym->GetLocation().y)
	{
		cout << display_code << id_num << ": I'm already at the Pokemon Gym!" << endl;
	}
	else if (stamina == 0)
	{
		cout << display_code << id_num << ": I am exhausted so I shouldnt go to the gym" << endl;
		state = EXHAUSTED;
	}
	else
	{
		cout << display_code << id_num << " On my way to the Pokemon Gym" << endl;
		SetupDestination(gym->GetLocation());
		state = MOVING_TO_GYM;
		current_gym = gym; //sets pokemon gym to the pokemon gym destination pointer
	}
}

void Pokemon::StartTraining(unsigned int num_training_units)
{
	bool error = false; //error variable so it can iterate through the multiple error checks 

	if (current_gym == NULL)//error variable so it can iterate through the multiple error checks
	{
		cout << "You havent selected to start moving to a gym yet" << endl;
		error = true;
	}

	if (error == false && stamina == 0) //print only when training unit is zero
	{
		state = EXHAUSTED;
		cout << display_code << id_num << " I am exhausted so no more training for me..." << endl;
		error = true;
	}

	if (error == false && state != IN_GYM) //checks if pokemon is in gym
	{
		cout << display_code << id_num << " I can only train in a Pokemon Gym! " << endl;
		error = true; 
	}

	if (error == false && current_gym->IsAbleToTrain(num_training_units, pokemon_dollars, stamina) == false) //print only when stamina and or dollars are less than required
	{
		cout << display_code << id_num << " Not enough stamina and/or money for training " << endl;
		error = true;
	}

	if (error == false && current_gym->GetState() == BEATEN)
	{
		cout << display_code << id_num << " Cannot train! This Pokemon Gym is already beaten! " << endl;
		error = true;
	}
	
	if (error == false)
	{
		state = TRAINING_IN_GYM;
		cout << display_code << id_num << " Started Training at Pokemon Gym: " << current_gym->GetId() << " with "
			<< num_training_units << " training units " << endl;
		training_units_to_buy = num_training_units;
	}
	

}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)
{
	bool error = false; //error variable so it can iterate through the multiple error checks 

	if (current_center == NULL) //checks to see if there is a current center pointer
	{
		cout << "You haven't selected to start moving to a Pokemon center yet" << endl;
		error = true;
	}
	
	if (error == false && current_center->CanAffordStaminaPoints(num_stamina_points, pokemon_dollars) == false) //checks if pokemon can afford stamina recovering
	{
		cout << display_code << id_num << " Not enough money to recover stamina" << endl;
		error = true;
	}
	
	if (error == false && current_center->GetState() == NO_STAMINA_POINTS_AVAILABLE) //checks if pokemon center has stamina points
	{
		cout << display_code << id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center" << endl;
		error = true;
	}

	if (error == false && state != IN_CENTER) //checks if its in the center
	{
		cout << display_code << id_num << " I can only recover stamina in a Pokemon Center!" << endl;
		error = true;
	}

	if (error == false)
	{
		state = RECOVERING_STAMINA;
		cout << display_code << id_num << " Started recovering " << num_stamina_points << " stamina point(s) at Pokemon Center " <<
			current_center->GetId() << endl;
		stamina_points_to_buy = num_stamina_points;
	}
}
 
void Pokemon::Stop()
{
	state = STOPPED;
	destination = location; //stops pokemon since it will already be at destination
}

bool Pokemon::isExhausted()
{
	if (stamina == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Pokemon::GetName()
{
	return name;
}

char Pokemon::GetDisplay_code()
{
	return display_code;
}

bool Pokemon::ShouldBeVisible()
{
	if (stamina > 0) //fixed should be visible points back
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Pokemon::Update()
{
	if(is_in_arena == false && current_arena != nullptr)
	{
		current_arena->RemoveOnePokemon();
	}
	
	if (is_in_center == false && current_center != nullptr)
	{
		current_center->RemoveOnePokemon();
	}
	
	if (is_in_gym == false && current_gym != nullptr)
	{
		current_gym->RemoveOnePokemon();
	}
	
	switch (state)//switch statement to print information about the value of the state
	{
	case STOPPED:
	{
		is_in_center = false;
		is_in_arena = false;
		is_in_gym = false;
		//ShowStatus();
		return false;
	}
		break;

	case EXHAUSTED:
	{
		is_in_center = false;
		is_in_arena = false;
		is_in_gym = false;
		//ShowStatus();
		return true;
	}

	case MOVING:
	{
		is_in_center = false;
		is_in_arena = false;
		is_in_gym = false;
		//ShowStatus();
		if (UpdateLocation() == true)
		{
			state = STOPPED;
			return true;
			//return false;
		}
		else return false;
	}
		break;

	case IN_GYM:
	{
		//ShowStatus();
		return false;
	}
		break;

	case IN_CENTER: 
	{
		//ShowStatus();
		return false;
	}
		break;
	case IN_ARENA:
	{
		//ShowStatus();
		return false;
	}
		break;
		
	case MOVING_TO_GYM: 
	{
		//ShowStatus();
		if (UpdateLocation() == true)
		{
			state = IN_GYM;
			current_gym->AddOnePokemon();//fixed pa3
			is_in_gym = true;
			return true;
			//return false;
		}
		else
		{
			is_in_center = false;
			return false;
		}
			
	}
		break;

	case MOVING_TO_CENTER: 
	{
		//ShowStatus();
		if (UpdateLocation() == true)
		{
			state = IN_CENTER;
			current_center->AddOnePokemon(); //fixed from pa3
			is_in_center = true;
			return true;
		}
		else
		{
			is_in_center = false;
			return false;
		}

	}
		break;

	case TRAINING_IN_GYM: 
	{
		//ShowStatus();
		stamina -= current_gym->GetStaminaCost(training_units_to_buy); //reduce stamina from stamina used for training units
		pokemon_dollars -= current_gym->GetDollarCost(training_units_to_buy); //reduce money from training units gotten
		experience_points += current_gym->TrainPokemon(training_units_to_buy); // gain exp from training units
		cout << "** " << name << " completed " << training_units_to_buy << " training unit(s)!**" << endl;
		cout << " pokemon dollars remaining " << pokemon_dollars << endl;
		state = IN_GYM;
		return true;
	}
		break;

	case RECOVERING_STAMINA: 
	{
		//ShowStatus();
		stamina += current_center->DistributeStamina(stamina_points_to_buy);
		pokemon_dollars -= current_center->GetDollarCost(stamina_points_to_buy);
		cout << "** " << name << " recovered " << current_center->DistributeStamina(stamina_points_to_buy) << " stamina point(s)!**" << endl;
		cout << " pokemon dollars remaining " << pokemon_dollars << endl;
		state = IN_CENTER;
		return true;
	}

		break;

		
	case MOVING_TO_ARENA:
		{
			//ShowStatus();
			if (UpdateLocation() == true)
			{
				state = IN_ARENA;
				current_arena->AddOnePokemon();
				is_in_arena = true;
				return true;
			}
			else
			{
				is_in_arena = false;
				return false;
			}
		}
		break;

	case BATTLE:
		{
			//ShowStatus();
			stamina -= current_arena->GetStaminaCost();
			pokemon_dollars -= current_arena->GetDollarCost();
			if (StartBattle() == true)
			{
				health = store_health;
				state = IN_ARENA;
				target->IsAlive();
				cout << name << " Won the battle" << endl;
				current_arena->RemoveOneRival(); // remove one rival only once
				return true;
				
			}
			else
			{
				state = FAINTED;
				target->IsAlive();
				cout << target->get_name() << " Won the battle " << endl;
				return true;
			}
		}
		
		break;
	case FAINTED:
		{
		is_in_center = false;
		is_in_arena = false;
		is_in_gym = false;
		//ShowStatus();
		return false;
		}
		break;
		
	default:
		cout << "something went wrong with the state machine" << endl;
		return false;
	}
}

bool Pokemon::IsAlive()
{
	if(state != FAINTED)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void Pokemon::TakeHit(double physical_damage, double magical_damage, double defense)
{
	double attack;
	
	int phy_or_mag = rand() % 2 + 1;
	
	if (phy_or_mag == 1)
	{
		attack = physical_damage;
		cout << name << " took " << attack << " physical attack" << endl;
	}
	else
	{
		attack = magical_damage;
		cout << name << " took " << attack << " Magical attack" << endl;
	}

	health -= (100.0 - defense) / 100 * attack;
	cout << name << " took " << (100.0 - defense) / 100 * attack << " damage" << endl;
}

void Pokemon::ReadyBattle(Rival * in_target)
{
	if (state == IN_ARENA && current_arena->IsAbleToFight(pokemon_dollars, stamina) == true && current_arena->IsBeaten() == false)
	{
		target = in_target;
		state = BATTLE;
		cout << name << " is ready to fight" << endl;
	}
	else
	{
		state = IN_ARENA;
		cout << name << " is not ready to fight" << endl;
	}
}

bool Pokemon::StartBattle()
{

	if (state == BATTLE)
	{
		while (health > 0 && target->get_health() > 0)
		{
			TakeHit(target->get_phys_dmg(), target->get_magic_dmg(), defense);
			target->TakeHit(physical_damage, magical_damage, target->get_defense());
			if (health <= 0 && target->get_health() >= 0)
			{
				//cout << name << " Lost the battle" << endl;
				return false;
			}
			if (health >= 0  && target->get_health() <= 0)
			{
				//cout << "Rival lost the battle" << endl;
				return true;
			}
		}	
	
	}
}

void Pokemon::StartMovingToArena(BattleArena * arena)
{
	if (location.x == arena->GetLocation().x && location.y == arena->GetLocation().y)
	{
		cout << display_code << id_num << ": I'm already at the Battle Arena!" << endl;
	}
	else if (stamina == 0)
	{
		cout << display_code << id_num << ": I am exhausted so I cant battle" << endl;
		state = EXHAUSTED;
	}
	else
	{
		cout << display_code << id_num << " On my way to the Battle Arena" << endl;
		state = MOVING_TO_ARENA;
		SetupDestination(arena->GetLocation());
		current_arena = arena; //sets the pokemon center location to the pokemons center destination pointer
	}
}

double GetRandomAmountOfPokemonDollars()
{
	return (rand() % (20000 - 0)) / 10000.0;
}