#pragma once
#include "Plant.h"
#include "World.h"
class Borscht : public Plant
{
public:
	Borscht(int x, int y, World* world);
	void Action()override;
	void Collision(Organism* other)override;
	void KillAnimalsAround(vector < COORDS> area);
	void Spread()override;
	vector<COORDS> CheckSurrounding(COORDS coords, int action)override;
	~Borscht();
};

