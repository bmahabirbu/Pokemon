#include "BattleArena.h"



BattleArena::BattleArena()
{
	max_num_rivals = 
}

BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int
	in_id, Point2D in_loc) : Building('A', in_id, in_loc)
{
	
}

unsigned int BattleArena::GetNumRivalsRemaining()
{
	return 0;
}

bool BattleArena::HasEnoughRivals()
{
	return false;
}

double BattleArena::GetDollarCost()
{
	return 0.0;
}

unsigned int BattleArena::GetStaminaCost()
{
	return 0;
}

bool BattleArena::IsAbleToFight(double budget, unsigned int stamina)
{
	return false;
}

bool BattleArena::Update()
{
	return false;
}

bool BattleArena::IsBeaten()
{
	return false;
}

void BattleArena::ShowStatus()
{
}
