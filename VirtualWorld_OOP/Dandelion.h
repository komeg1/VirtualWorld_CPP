#pragma once
#include "Plant.h"
class Dandelion : public Plant
{
public:
	Dandelion(int x, int y, World* world);
	Dandelion(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout);
	void Action()override;
	void Spread()override;
	~Dandelion();
};

