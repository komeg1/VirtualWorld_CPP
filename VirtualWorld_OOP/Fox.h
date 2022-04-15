#pragma once
#include "Animal.h"
class Fox : public Animal
{
public:
	Fox(int x, int y, World* world);
	void action(World* world) override;
	bool breeding(World* world)override;
	bool IsStronger(COORDS a, COORDS b, World* world);
	vector<COORDS> CheckSurrounding(World* world, COORDS coords, char thisAnimal, int action)override;
	COORDS FoxUpdateCoords(vector<COORDS>area);
	~Fox() override;
};

