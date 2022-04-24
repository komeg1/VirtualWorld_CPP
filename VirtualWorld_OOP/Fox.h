#pragma once
#include "Animal.h"
class Fox : public Animal
{
public:
	Fox(int x, int y, World* world);
	void action() override;
	bool breeding(Organism* other)override;
	bool IsStronger(COORDS a, COORDS b, World* world);
	vector<COORDS> CheckSurrounding(COORDS coords,int action)override;
	~Fox() override;
};

