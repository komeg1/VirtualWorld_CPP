#pragma once
#include "Animal.h"
class Wolf : public Animal
{
public:
	Wolf(int x,int y, World* world);
	Wolf(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout);
	void CreateChild(COORDS newCoords, Organism* other)override;
	~Wolf() override;

};

