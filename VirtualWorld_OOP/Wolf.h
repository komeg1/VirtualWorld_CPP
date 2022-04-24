#pragma once
#include "Animal.h"
class Wolf : public Animal
{
public:
	Wolf(int x,int y, World* world);
	bool breeding(Organism* other)override;
	~Wolf() override;

};

