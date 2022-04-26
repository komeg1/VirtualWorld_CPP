#include "Sheep.h"
#include "World.h"
Sheep::Sheep(int x, int y, World* world) : Animal(world, 'S', 4, 4, make_pair(x, y))
{
	AddToWorld(this);
}
Sheep::Sheep(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout) :
	Animal(world, sign, strength, initiative, coordinates, lifetime, breedingTimeout) {
	AddToWorld(this);
}
void Sheep::CreateChild(COORDS newCreatureCoords, Organism* other) {
	Sheep* child = new Sheep(newCreatureCoords.first, newCreatureCoords.second, world);
	this->SetbreedingTimeout();
	other->SetbreedingTimeout();
	child->SetbreedingTimeout();
}

	Sheep::~Sheep()
	{
	}

