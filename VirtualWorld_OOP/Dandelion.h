#pragma once
#include "Plant.h"
class Dandelion : public Plant
{
public:
	Dandelion(int x, int y, World* world);
	void action()override;
	void Spread()override;
	~Dandelion();
};

