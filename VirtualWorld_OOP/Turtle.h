#pragma once
#include "Animal.h"
class Turtle : public Animal
{
public:
	Turtle(int x,int y, World* world);
	Turtle(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout);
	void Action()override;
	void Collision(Organism* other)override;
	bool GenerateProbability();
	bool IsBlocked(Organism* other)override;
	void CreateChild(COORDS newCoords, Organism* other)override;
	~Turtle();
};

