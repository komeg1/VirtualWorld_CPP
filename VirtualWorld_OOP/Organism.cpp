#include "Organism.h"
#include "World.h"

Organism::Organism(World* world, char sign, int strength, int initiative, int lifeTime, COORDS coordinates,int breedingTimeout) : 
	world(world), sign(sign), strength(strength), initiative(initiative), lifeTime(lifeTime), coordinates(coordinates), breedingTimeout(breedingTimeout)
{

}


void Organism::SetBreedingTimeout()
{
	breedingTimeout = BREEDING_CNTDOWN;
}

void Organism::SetCoordinates(pair<int, int> coordinates)
{
	this->coordinates = coordinates;
}


void Organism::UpdateLifeTime()
{
	this->lifeTime++;
}

COORDS Organism::RandomCoords(vector<COORDS> area, World* world)
{
		if (area.size() > 0)
		{
			int randVal = rand() % area.size();
			return area[randVal];
		}
		return make_pair(-1, -1);
	
}

bool Organism::Block(Organism* other)
{
	return false;
}


char Organism::GetSign()const
{
	return sign;
}

int Organism::GetStrength()const
{
	return strength;
}

int Organism::GetInitiative()const
{
	return initiative;
}

int Organism::GetlifeTime()const
{
	return lifeTime;
}

int Organism::GetIndex() const
{
	vector<Organism*> temp = world->GetCreaturesArray();
	for (int i = 0; i < temp.size(); i++)
		if (this->coordinates == temp[i]->coordinates)
			return i;
}

int Organism::GetBreedingTimeout() const
{
	return breedingTimeout;
}

COORDS Organism::GetCoordinates()const
{
	return coordinates;
}


void Organism::Kill(Organism* a, bool won)
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


Organism::~Organism()
{
	
}


