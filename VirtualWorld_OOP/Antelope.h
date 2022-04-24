#pragma once
#include "Animal.h"
class Antelope : public Animal
{
public:
	Antelope(int x,int y, World*world);
	void collision(Organism* a)override;
	bool IsBlocked(Organism* other)override;
	vector<COORDS> CheckSurrounding(COORDS coords, int action)override;
	bool breeding(Organism* other);
	~Antelope();
};

