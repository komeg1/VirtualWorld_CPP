#pragma once
#include "Animal.h"
class Sheep : public Animal
{
public:
	Sheep(int x, int y, World* world);
	
	void CreateChild(COORDS newCoords, Organism* other)override;

	~Sheep() override;
};

