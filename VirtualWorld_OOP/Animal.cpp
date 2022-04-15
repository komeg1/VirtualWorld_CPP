#include "Animal.h"
#include "World.h"
#include "Wolf.h"

Animal::Animal(World* world, char sign, int strength, int initiative, int lifeTime, COORDS coordinates,int breedingTimeout): 
	Organism(world,sign,strength,initiative,lifeTime,coordinates,breedingTimeout)
{
}
bool Animal::CheckIfOrganism(COORDS newCoords, World* world) {
	if (world->worldBoard[newCoords.second][newCoords.first] == FIELD)
		return 0;
	return 1;
}

vector<COORDS> Animal::PrepareArea(Organism* other) {
	vector<COORDS> thisArea = CheckSurrounding(world, coordinates, 1),
		otherArea = CheckSurrounding(world, other->GetCoordinates(), 1);

	for (int i = 0; i < otherArea.size(); i++)
		thisArea.push_back(otherArea[i]);
	return thisArea;

}

Organism* Animal ::FindOrganism(COORDS newCoords, World* world) {
	for (Organism* a : world->GetCreaturesArray())
	{
		if (a->GetCoordinates() == newCoords)
			return a;
	}
	return nullptr;
}
void Animal::action(World* world)
{
		COORDS currentCoords = GetCoordinates();
		COORDS newCoords = RandomCoords(CheckSurrounding(world, currentCoords, 0),world);
		if (CheckIfOrganism(newCoords,world))
		{
			Organism* other = FindOrganism(newCoords,world);
			other->collision(this);

		}
		else
		{
			this->SetCoordinates(newCoords);
			this->UpdateLifeTime();
		}
		if (this->GetBreedingTimeout() > 0)
			this->breedingTimeout--;


		
	}


void Animal::collision(Organism* attackingOrganism)
{
	if (this->GetSign() == attackingOrganism->GetSign())
	{
		if (breeding(world, this))
			world->CreateLog(this, this, BREED, world);
		else
			world->CreateLog(this, this, BREEDTIME, world);
		return;
	}

	if (this->GetStrength() == attackingOrganism->GetStrength())
	{
		if (this->GetlifeTime() > attackingOrganism->GetlifeTime())
		{
			Kill(attackingOrganism, 1);
			attackingOrganism->~Organism();
			
		}
		else
		{
			COORDS newCoordinates = this->GetCoordinates();
			Kill(attackingOrganism, 0);
			this->~Animal();
			attackingOrganism->SetCoordinates(newCoordinates);
		}
		return;

	}
	else if (this->GetStrength() > attackingOrganism->GetStrength())
	{

		Kill(attackingOrganism, 1);
		attackingOrganism->~Organism();
	}
	else if (this->GetStrength() < attackingOrganism->GetStrength())
	{
		COORDS newCoordinates = this->GetCoordinates();
		Kill(attackingOrganism, 0);
		this->~Animal();
		attackingOrganism->SetCoordinates(newCoordinates);
	}

	return;




}

vector<COORDS> Animal::CheckSurrounding(World* world, COORDS coords,int action)
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
			if (world->worldBoard[i][j] == this->GetSign() && make_pair(j, i) == coords)
				continue;
			else if (world->worldBoard[i][j] == FIELD)
				availableSurrounding.push_back(make_pair(j, i));
			else {
				if (action != 1)
					availableSurrounding.push_back(make_pair(j, i));
			}
		}


	return availableSurrounding;
}






bool Animal::IsBlocked(Organism* other)
{
	return false;
}

Animal::~Animal()
{
}
