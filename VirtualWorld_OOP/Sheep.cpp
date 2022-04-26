#include "Sheep.h"
#include "World.h"
Sheep::Sheep(int x, int y, World* world) : Animal(world, 'S', 4, 4, make_pair(x, y))
{
	AddToWorld(this);
}
void Sheep::CreateChild(COORDS newCreatureCoords, Organism* other) {
	Sheep* child = new Sheep(newCreatureCoords.first, newCreatureCoords.second, world);
	this->SetBreedingTimeout();
	other->SetBreedingTimeout();
	child->SetBreedingTimeout();
}

	Sheep::~Sheep()
	{
	}

