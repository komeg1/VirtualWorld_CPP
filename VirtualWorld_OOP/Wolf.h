#pragma once
#include "Animal.h"
class Wolf : public Animal
{
public:
	Wolf(int x,int y, World* world);
	void CreateChild(COORDS newCoords, Organism* other)override;
	~Wolf() override;

};

