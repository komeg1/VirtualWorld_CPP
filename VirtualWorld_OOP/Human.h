#pragma once
#include "Animal.h"
class Human : public Animal
{
public:
	Human(int x, int y, World* world);
	void Action()override;
	bool Breeding(Organism* other)override;
	void CreateChild(COORDS newCoords, Organism* other)override;

};

