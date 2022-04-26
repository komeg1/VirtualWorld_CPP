#pragma once
#include "Animal.h"
class Antelope : public Animal
{
public:
	Antelope(int x,int y, World*world);
	void Collision(Organism* a)override;
	bool IsBlocked(Organism* other)override;
	vector<COORDS> CheckSurrounding(COORDS coords, int action)override;
	void CreateChild(COORDS newCoords, Organism* other)override;
	~Antelope();
};

