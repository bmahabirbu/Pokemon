/*
#include "Pokemon.h"
#include "GameObject.h"
#include <ctime>
#include<cstdlib>


int main(void)
{
	srand(time(NULL));
	Pokemon pikachu("pikachu", 32, 'P', 4, Point2D(10, 10));
	PokemonGym A(100, 2, 2, 6, 88, Point2D(1, 0));
	PokemonGym* B = &A;
	pikachu.ShowStatus();
	cout << B->GetId() << endl;
	pikachu.StartMovingToGym(B);
	pikachu.Update();
	pikachu.Update();
	pikachu.Update();
	pikachu.Update();
	pikachu.Update();
	cout << "moment of truth" << endl;
	pikachu.StartTraining(1);
	cout << "moment of truth" << endl;
	pikachu.Update();
	pikachu.Update();
	pikachu.Update();
	pikachu.Stop();
	pikachu.Update();
}

*/
