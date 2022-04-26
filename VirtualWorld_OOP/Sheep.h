#pragma once
#include "Animal.h"
class Sheep : public Animal
{
public:
	Sheep(int x, int y, World* world);
	Sheep(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout);
	void CreateChild(COORDS newCoords, Organism* other)override;

	~Sheep() override;
};

