#pragma once
#include "Plant.h"
class Guarana : public Plant
{
public:
	Guarana(int x, int y, World* world);
	Guarana(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout);
	void Spread()override;
	void Collision(Organism* other)override;
	~Guarana();
};

