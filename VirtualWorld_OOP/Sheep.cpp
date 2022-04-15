#include "Sheep.h"
#include "World.h"
Sheep::Sheep(int x, int y, World* world) : Animal(world, 'S', 4, 4, 0, make_pair(x, y),0)
{
	world->worldBoard[y][x] = sign;
	CREATURES temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
}
bool Sheep::breeding(World* world,Organism* other)
{
	if (this->GetBreedingTimeout() == 0 && other->GetBreedingTimeout() == 0)
	{
		vector<COORDS> area = PrepareArea(other);
		COORDS newCreatureCoords = RandomCoords(area, world);
		if (newCreatureCoords != make_pair(-1, -1))
		{
			Sheep* child = new Sheep(newCreatureCoords.first, newCreatureCoords.second, world);
			child->SetBreedingTimeout();
			this->SetBreedingTimeout();
			other->SetBreedingTimeout();
			return 1;
		}
	}
	return 0;
}

	Sheep::~Sheep()
	{
	}

