#pragma once
#include "Organism.h"
#include "GameFunctions.h"
class Animal : public Organism
{
public:
	Animal(World* world, char sign, int strength, int initative, int lifeTime, COORDS coordinates,int breedingTimeout);
	void action(World* world) override;
	vector<COORDS> CheckSurrounding(World* world, COORDS coords, char thisAnimal,int action)override;
	bool collision(char movingAnimal, char waitingAnimal,World* world, COORDS a,COORDS b) override;
	virtual bool breeding(World* world);
	~Animal() override;
	

};

