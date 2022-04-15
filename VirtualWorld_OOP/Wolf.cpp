#include "Wolf.h"
#include "World.h"
Wolf::Wolf(int x, int y, World* world) : Animal(world, 'W', 9, 5, 0, make_pair(x, y),0)
{
	world->worldBoard[y][x] = sign;
	CREATURES temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
}

bool Wolf::breeding(World* world)
{
	COORDS newCreatureCoords = RandomCoords(CheckSurrounding(world, coordinates, this->sign,1),world);
	if (newCreatureCoords != make_pair(-1, -1))
	{
		Wolf* child = new Wolf(newCreatureCoords.first, newCreatureCoords.second, world);
		child->breedingTimeout = BREEDING_CNTDOWN;
		return 1;
	}
	return 0;
}

Wolf::~Wolf()
{
}
