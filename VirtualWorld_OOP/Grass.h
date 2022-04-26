#pragma once
#include "Plant.h"
class Grass : public Plant
{
public:
	Grass(int x, int y, World* world);
	Grass(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout);
	~Grass()override;
	void Spread()override;
};



