#pragma once
#include "Animal.h"
class Fox : public Animal
{
public:
	Fox(int x, int y, World* world);
	void action(World* world) override;
	COORDS FoxUpdateCoords(vector<COORDS>area);
	~Fox() override;
};

