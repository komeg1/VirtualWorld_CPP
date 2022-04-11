#include "Sheep.h"
#include "World.h"
Sheep::Sheep(int x, int y, World* world) : Animal(world, 'S', 4, 4, 0, make_pair(x, y), 0)
{
	world->worldBoard[y][x] = sign;
	vector<Organism*> temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
}

	Sheep::~Sheep()
	{
	}

