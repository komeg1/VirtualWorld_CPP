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





Organism::~Organism()
{
}


