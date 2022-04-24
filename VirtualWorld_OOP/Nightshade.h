#pragma once
#include "Plant.h"
class Nightshade : public Plant
{
public:
	Nightshade(int x, int y, World* world);
	void Spread()override;
	void Kill(Organism* other, bool won)override;
	void collision(Organism* other)override;
	~Nightshade();
};

