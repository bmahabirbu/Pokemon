#include "GameCommand.h"

void DoMoveCommand(Model &model, int pokemon_id, Point2D p1)
{
	while (pokemon_id <= 0 || pokemon_id > 2)
	{
		cout <<  "Error: please enter a valid pokemon id!" << endl;
		cin >> pokemon_id;

	}
	
		Pokemon* Poke1 = model.GetPokemonPtr(pokemon_id); //for readability set the pointer to a name
		cout << "Moving " << Poke1->GetName() << " to location " << p1 << endl;
		Poke1->StartMoving(p1);
	
	
}

void DoMoveToCenterCommand(Model & model, int pokemon_id, int center_id)
{
	while (pokemon_id <= 0 || pokemon_id > 2)
	{
		cout << "Error: please enter a valid pokemon id!" << endl;
		cin >> pokemon_id;

	}

	Pokemon* Poke1 = model.GetPokemonPtr(pokemon_id);

	while (center_id <= 0 || center_id > 2)
	{
		cout << "Error: please enter a valid center id!" << endl;
		cin >> center_id;

	}

	PokemonCenter* PokeC1 = model.GetPokemonCenterPtr(center_id);//for readability set pointer to a name

	cout << " Moving " << Poke1->GetName() << " to center " << PokeC1->GetId() << endl;
	Poke1->StartMovingToCenter(PokeC1); //start moving
	
}

void DoMoveToGymCommand(Model & model, int pokemon_id, int gym_id)
{
	while (pokemon_id <= 0 || pokemon_id > 2)
	{
		cout <<  "Error: please enter a valid pokemon id!" << endl;
		cin >> pokemon_id;

	}

	Pokemon* Poke1 = model.GetPokemonPtr(pokemon_id);

	while (gym_id <= 0 || gym_id > 2)
	{
		cout << "Error: please enter a valid gym id!" << endl;
		cin >> gym_id;

	}

	PokemonGym* PokeG1 = model.GetPokemonGymPtr(gym_id);

	cout << " Moving " << Poke1->GetName() << " to gym " << PokeG1->GetId() << endl;
	Poke1->StartMovingToGym(PokeG1); //start moving to gym
	
}

void DoStopCommand(Model & model, int pokemon_id)
{
	while (pokemon_id <= 0 || pokemon_id > 2)
	{
		cout <<  "Error: please enter a valid pokemon id!" << endl;
		cin >> pokemon_id;

	}

	Pokemon* Poke1 = model.GetPokemonPtr(pokemon_id);

	cout << "Stopping " << Poke1->GetName() << endl;
	Poke1->Stop();

}

void DoTrainInGymCommand(Model & model, int pokemon_id, unsigned int training_units)
{
	while (pokemon_id <= 0 || pokemon_id > 2)
	{
		cout <<  "Error: please enter a valid pokemon id!" << endl;
		cin >> pokemon_id;

	}

	Pokemon* Poke1 = model.GetPokemonPtr(pokemon_id);

	cout << "Training " << Poke1->GetName() << endl;
	Poke1->StartTraining(training_units);

}

void DoRecoverInCenterCommand(Model & model, int pokemon_id, unsigned int stamina_points)
{
	while (pokemon_id <= 0 || pokemon_id > 2)
	{
		cout <<  "Error: please enter a valid pokemon id!" << endl;
		cin >> pokemon_id;

	}
	Pokemon* Poke1 = model.GetPokemonPtr(pokemon_id);

	cout << "Recovering " << Poke1->GetName() << "'s stamina" << endl;
	Poke1->StartRecoveringStamina(stamina_points);
	
}

void DoGoCommand(Model & model, View & view)
{
	cout << "Advancing to next event" << endl; 
	model.Update();
	model.Display(view);
}

void DoRunCommand(Model & model, View & view)
{
	for (int i = 0; i < 5; i++) //loop until 5 or update return true and display
	{
		if (model.Update() == true)
		{
			model.Display(view);
			break;
		}
	}
	model.Display(view);
}


