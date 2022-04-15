#include "Plant.h"

Plant::Plant(World* world, char sign, int strength, int initiative, int lifeTime, COORDS coordinates, int breedingTimeout):
Organism(world, sign, strength, initiative, lifeTime, coordinates, breedingTimeout) {
}

void Plant::action(World* world)
{

	//25% chance
	Spread(world);
}

bool Plant::SpreadProbability()
{
	return rand() & 1;
}

Plant::~Plant()
{
}
