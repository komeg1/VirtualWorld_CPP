#pragma once
#include "Plant.h"
class Guarana : public Plant
{
	Guarana(int x, int y, World* world);
	void Spread()override;
	~Guarana();
};

