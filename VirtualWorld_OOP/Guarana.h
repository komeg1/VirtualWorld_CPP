#pragma once
#include "Plant.h"
class Guarana : public Plant
{
public:
	Guarana(int x, int y, World* world);
	void Spread()override;
	void collision(Organism* other)override;
	~Guarana();
};

