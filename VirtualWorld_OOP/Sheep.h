#pragma once
#include "Animal.h"
class Sheep : public Animal
{
public:
	Sheep(int x, int y, World* world);
	
	bool breeding(World* world,Organism* other)override;

	~Sheep() override;
};

