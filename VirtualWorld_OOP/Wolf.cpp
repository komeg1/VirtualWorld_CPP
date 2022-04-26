#include "Wolf.h"
#include "World.h"
Wolf::Wolf(int x, int y, World* world) : Animal(world, 'W', 9, 5, make_pair(x, y))
{
	AddToWorld(this);
}
void Wolf::CreateChild(COORDS newCreatureCoords, Organism* other) {
	Wolf* child = new Wolf(newCreatureCoords.first, newCreatureCoords.second, world);
	this->SetBreedingTimeout();
	other->SetBreedingTimeout();
	child->SetBreedingTimeout();
}


Wolf::~Wolf()
{
}
