#include "Fox.h"
#include "World.h"
Fox::Fox(int x, int y, World* world) : Animal(world, 'F', 3, 7, make_pair(x, y))
{
	AddToWorld(this);
}

void Fox::Action()
{
	COORDS currentCoords = GetCoordinates();
	COORDS newCoords = RandomCoords(CheckSurrounding(currentCoords, 0));
	if (newCoords!=make_pair(-1,-1)&&CheckIfOrganism(newCoords))
	{
		Organism* other = FindOrganism(newCoords);
		other->Collision(this);

	}
	else
	{
		if(newCoords!=make_pair(-1,-1))
			this->SetCoordinates(newCoords);
		this->UpdateLifeTime();
	}
	if (this->GetBreedingTimeout() > 0)
		this->BreedingTimeout--;
}
void Fox::CreateChild(COORDS newCreatureCoords, Organism* other) {
	Fox* child = new Fox(newCreatureCoords.first, newCreatureCoords.second, world);
	this->SetBreedingTimeout();
	other->SetBreedingTimeout();
	child->SetBreedingTimeout();
}



bool Fox::IsStronger(COORDS a, COORDS b, World* world)
{
	int strengthA = 0;
	int strengthB = 0;

	for (int i = 0; i < world->GetCreaturesArray().size(); i++)
	{
		if (world->GetCreaturesArray()[i]->GetCoordinates() == a)
			strengthA = world->GetCreaturesArray()[i]->GetStrength();
		if (world->GetCreaturesArray()[i]->GetCoordinates() == b)
			strengthB = world->GetCreaturesArray()[i]->GetStrength();
	}

	return strengthA > strengthB;
}

vector<COORDS> Fox::CheckSurrounding(COORDS coords, int action)
{
	int x1 = coords.first - 1,
		x2 = coords.first + 1,
		y1 = coords.second - 1,
		y2 = coords.second + 1;
	vector<COORDS> availableSurrounding;
	if (x1 < 0)
		x1 = 0;
	if (y1 < 0)
		y1 = 0;
	if (x2 == world->GetWorldX())
		x2--;
	if (y2 == world->GetWorldY())
		y2--;



	for (int i = y1; i <= y2; i++)
		for (int j = x1; j <= x2; j++)
		{
			if (world->worldBoard[i][j] == this->sign && make_pair(j, i) == coords)
				continue;
			else if (world->worldBoard[i][j] != FIELD&&world->worldBoard[i][j] != this->sign)
			{
				if (IsStronger(coords, make_pair(j, i), world))
					availableSurrounding.push_back(make_pair(j, i));
			}
			else if (world->worldBoard[i][j] == FIELD)
				availableSurrounding.push_back(make_pair(j, i));
			else if(action!=1)
			{
				availableSurrounding.push_back(make_pair(j, i));
			}
		}


	return availableSurrounding;
}


Fox::~Fox()
{
}