#pragma once
#include "Organism.h"
#include "GameFunctions.h"
class Animal : public Organism
{
public:
	Animal(World* world, char sign, int strength, int initative, COORDS coordinates);
	void action() override;
	void collision(Organism* other) override;
	vector<COORDS> PrepareArea(Organism* other);
	bool CheckIfOrganism(COORDS coords);
	void Kill(Organism* a, bool won)override;
	Organism* FindOrganism(COORDS coords);
	virtual bool breeding(Organism* other)=0;
	virtual bool IsBlocked(Organism* other);
	~Animal() override;
	

};

