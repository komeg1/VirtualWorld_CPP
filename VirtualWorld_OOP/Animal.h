#pragma once
#include "Organism.h"
#include "GameFunctions.h"
class Animal : public Organism
{
public:
	Animal(World* world, char sign, int strength, int initative, int lifeTime, COORDS coordinates,bool doneTurn);
	virtual void action(World* world) override;
	bool collision(char movingAnimal, char waitingAnimal,World* world, COORDS a,COORDS b) override;
	~Animal() override;
	

};

