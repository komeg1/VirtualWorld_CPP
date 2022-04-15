#pragma once
#include "Animal.h"
class Turtle : public Animal
{
public:
	Turtle(int x,int y, World* world);
	void action(World* world)override;
	void collision(Organism* other)override;
	bool GenerateProbability();
	bool IsBlocked(Organism* other)override;
	bool breeding(World* world, Organism* other)override;
	~Turtle();
};

