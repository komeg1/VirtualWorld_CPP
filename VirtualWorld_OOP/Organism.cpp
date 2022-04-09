#include "Organism.h"
#include "World.h"


Organism::Organism(World* world, char sign, int strength, int initiative, int lifeTime, pair<int, int> coordinates):
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



Organism::~Organism()
{
}



