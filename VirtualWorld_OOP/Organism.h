#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <utility>
#include "Definitions.h"
using namespace std;
class World;
class Organism
{
protected:
	World* world;
	char sign;
	int strength;
	int initiative;
	int lifeTime = 0;
	COORDS coordinates;
	int breedingTimeout = 0;


public:
	Organism(World *world, char sign, int strength, int initative, COORDS coordinates);

	char GetSign()const;
	int GetStrength()const;
	int GetInitiative()const;
	int GetlifeTime()const;
	int GetIndex() const;
	int GetBreedingTimeout()const;
	COORDS GetCoordinates()const;
	void GuaranaBoost();
	void SetBreedingTimeout();
	void SetCoordinates(pair<int, int> coordinates);
	void UpdateLifeTime();
	virtual void Kill(Organism* a,bool won)=0;
	COORDS RandomCoords(vector<COORDS> coords);
	virtual bool Block(Organism* other);
	virtual vector<COORDS> CheckSurrounding(COORDS coords,int action);
	virtual void action() = 0;
	virtual void collision(Organism* other)=0;
	virtual ~Organism();

};


