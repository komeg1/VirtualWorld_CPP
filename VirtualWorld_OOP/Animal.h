#pragma once
#include "Organism.h"
#include "GameFunctions.h"
class Animal : public Organism
{
public:
	Animal(World* world, char sign, int strength, int initative, COORDS coordinates);
	Animal(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout);
	bool CheckIfOrganism(COORDS coords);
	void Action() override;
	void Collision(Organism* other) override;
	void Kill(Organism* a, bool won)override;
	vector<COORDS> PrepareArea(Organism* other);
	
	virtual bool Breeding(Organism* other);
	virtual bool IsBlocked(Organism* other);
	virtual void CreateChild(COORDS newCoords, Organism* other) = 0;
	~Animal() override;
	

};

