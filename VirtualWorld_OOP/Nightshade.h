#pragma once
#include "Plant.h"
class Nightshade : public Plant
{
public:
	Nightshade(int x, int y, World* world);
	Nightshade(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout);
	void Spread()override;
	void Collision(Organism* other)override;
	~Nightshade();
};

