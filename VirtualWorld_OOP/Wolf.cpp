#include "Wolf.h"
#include "World.h"
Wolf::Wolf(int x, int y, World* world) : Animal(world, 'W', 9, 5, make_pair(x, y))
{
	AddToWorld(this);
}

Wolf::Wolf(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout) :
	Animal(world, sign, strength, initiative, coordinates, lifetime, breedingTimeout) {
	AddToWorld(this);
}

void Wolf::CreateChild(COORDS newCreatureCoords, Organism* other) {
	Wolf* child = new Wolf(newCreatureCoords.first, newCreatureCoords.second, world);
	this->SetbreedingTimeout();
	other->SetbreedingTimeout();
	child->SetbreedingTimeout();
}


Wolf::~Wolf()
{
}
