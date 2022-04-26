#pragma once
#include "Plant.h"
#include "World.h"
class Borscht : public Plant
{
public:
	Borscht(int x, int y, World* world);
	Borscht(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout);
	void Action()override;
	void Collision(Organism* other)override;
	void KillAnimalsAround(vector < COORDS> area);
	void Spread()override;
	vector<COORDS> CheckSurrounding(COORDS coords, int action)override;
	~Borscht();
};

