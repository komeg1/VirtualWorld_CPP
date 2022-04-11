#include "Organism.h"
#include "World.h"


Organism::Organism(World* world, char sign, int strength, int initiative, int lifeTime, COORDS coordinates, bool doneTurn):
	world(world), sign(sign), strength(strength), initiative(initiative), lifeTime(lifeTime), coordinates(coordinates), doneTurn(doneTurn)
{

}


void Organism::SetCoordinates(pair<int, int> coordinates)
{
	this->coordinates = coordinates;
}

void Organism::SetTurn(bool a)
{
	this->doneTurn = a;
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

COORDS Organism::GetCoordinates()const
{
	return coordinates;
}

bool Organism::GetTurn() const {
	return doneTurn;
}

void Organism::SetIterator(World* world)
{

	
	for (int i = 0; i < world->GetCreaturesArray().size(); i++)
	{
		if (world->GetCreaturesArray()[i]->GetCoordinates() == coordinates)
			this->it = (world->GetCreaturesArray().begin() + i);

	}
}



Organism::~Organism()
{
}


