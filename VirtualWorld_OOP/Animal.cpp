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


void Animal::Kill(Organism* a, bool won)
{
	CREATURES temp;
	if (won)
	{
		this->world->CreateLog(this, a, KILL, world);
		temp = world->GetCreaturesArray();
		temp.erase(temp.begin() + a->GetIndex());
		world->SetCreaturesArray(temp);
		return;
	}
	else
	{
		this->world->CreateLog(a, this, KILL, world);
		temp = world->GetCreaturesArray();
		temp.erase(temp.begin() + this->GetIndex());
		world->SetCreaturesArray(temp);
		return;
	}

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








bool Animal::IsBlocked(Organism* other)
{
	return false;
}

Animal::~Animal()
{
}
