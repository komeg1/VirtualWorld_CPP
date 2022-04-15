#pragma once
#include "Animal.h"
class Human : public Animal
{
public:
	Human(int x, int y, World* world);
	void action(World* world)override;

};

