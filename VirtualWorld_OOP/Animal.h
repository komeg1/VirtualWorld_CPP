#pragma once
#include "Organism.h"
#include "GameFunctions.h"
class Animal : public Organism
{
public:
	Animal(World* world, char sign, int strength, int initative, int lifeTime, COORDS coordinates,int breedingTimeout);
	void action(World* world) override;
	vector<COORDS> CheckSurrounding(World* world, COORDS coords,int action)override;
	void collision(Organism* other) override;
	vector<COORDS> PrepareArea(Organism* other);
	bool CheckIfOrganism(COORDS coords, World* world);
	Organism* FindOrganism(COORDS coords, World* world);
	virtual bool breeding(World* world,Organism* other)=0;
	virtual bool IsBlocked(Organism* other);
	~Animal() override;
	

};

