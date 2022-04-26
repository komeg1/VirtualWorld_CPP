#pragma once
#include "Organism.h"
#include "GameFunctions.h"
class Animal : public Organism
{
public:
	Animal(World* world, char sign, int strength, int initative, COORDS coordinates);
	void Action() override;
	void Collision(Organism* other) override;
	virtual void CreateChild(COORDS newCoords, Organism* other) = 0;
	vector<COORDS> PrepareArea(Organism* other);
	bool CheckIfOrganism(COORDS coords);
	void Kill(Organism* a, bool won)override;
	
	virtual bool Breeding(Organism* other);
	virtual bool IsBlocked(Organism* other);
	~Animal() override;
	

};

