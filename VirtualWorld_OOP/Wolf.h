#pragma once
#include "Animal.h"
class Wolf : public Animal
{
public:
	Wolf(int x,int y, World* world);
	bool breeding(World* world)override;
	~Wolf() override;

};

