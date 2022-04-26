#include "Animal.h"
#include "World.h"
#include "Wolf.h"

Animal::Animal(World* world, char sign, int strength, int initiative, COORDS coordinates) :
	Organism(world, sign, strength, initiative,  coordinates)
{
}
Animal::Animal(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout) :
	Organism(world, sign, strength, initiative, coordinates,lifetime,breedingTimeout) {
}



bool Animal::CheckIfOrganism(COORDS newCoords) {
	if (world->worldBoard[newCoords.second][newCoords.first] == FIELD)
		return 0;
	return 1;
}

vector<COORDS> Animal::PrepareArea(Organism* other) {
	vector<COORDS> thisArea = CheckSurrounding(coordinates, 1),
		otherArea = CheckSurrounding(other->GetCoordinates(), 1);

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


void Animal::Action()
{
		COORDS currentCoords = GetCoordinates();
		COORDS newCoords = RandomCoords(CheckSurrounding(currentCoords, 0));
		if (CheckIfOrganism(newCoords))
		{
			Organism* other = FindOrganism(newCoords);
			other->Collision(this);

		}
		else
		{
			this->SetCoordinates(newCoords);
			this->UpdateLifeTime();
		}
		if (this->GetbreedingTimeout() > 0)
			this->breedingTimeout--;



		
	}
bool Animal::Breeding(Organism* other)
{
	if (this->GetSign() == HUMAN)
		return 0;
	if (this->GetbreedingTimeout() == 0 && other->GetbreedingTimeout() == 0)
	{
		vector<COORDS> area = PrepareArea(other);
		COORDS newCreatureCoords = RandomCoords(area);
		if (newCreatureCoords != make_pair(-1, -1))
		{
			this->CreateChild(newCreatureCoords,other);
			return 1;
		}
	}
	return 0;
}

void Animal::Collision(Organism* attackingOrganism)
{
	if (this->GetSign() == attackingOrganism->GetSign())
	{
		if (Breeding(this))
			this->world->CreateLog(this, this, BREED, world);
		else
			this->world->CreateLog(this, this, BREEDTIME, world);
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
