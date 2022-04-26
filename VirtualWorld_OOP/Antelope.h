#pragma once
#include "Animal.h"
class Antelope : public Animal
{
public:
	Antelope(int x,int y, World*world);
	Antelope(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout);
	void Collision(Organism* a)override;
	bool IsBlocked(Organism* other)override;
	vector<COORDS> CheckSurrounding(COORDS coords, int action)override;
	void CreateChild(COORDS newCoords, Organism* other)override;
	~Antelope();
};

