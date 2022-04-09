#pragma once
#include "Organism.h"
#include "GameFunctions.h"
class Animal : public Organism
{
public:
	Animal(World* world, char sign, int strength, int initative, int lifeTime, pair<int, int> coordinates);
	virtual void action() override;
	void collision() override;
	pair <int,int> Move();
	~Animal() override;
	

};

