#pragma once
#include "Animal.h"
class Fox : public Animal
{
public:
	Fox(int x, int y, World* world);
	void Action() override;
	void CreateChild(COORDS newCoords, Organism* other)override;
	bool IsStronger(COORDS a, COORDS b, World* world);
	vector<COORDS> CheckSurrounding(COORDS coords,int action)override;
	~Fox() override;
};

