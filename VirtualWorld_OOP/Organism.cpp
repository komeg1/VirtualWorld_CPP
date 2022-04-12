#include "Organism.h"
#include "World.h"

Organism::Organism(World* world, char sign, int strength, int initiative, int lifeTime, COORDS coordinates) : 
	world(world), sign(sign), strength(strength), initiative(initiative), lifeTime(lifeTime), coordinates(coordinates)
{

}


void Organism::SetCoordinates(pair<int, int> coordinates)
{
	this->coordinates = coordinates;
}


void Organism::UpdateLifeTime()
{
	this->lifeTime++;
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

COORDS Organism::GetCoordinates()const
{
	return coordinates;
}







Organism::~Organism()
{
}


