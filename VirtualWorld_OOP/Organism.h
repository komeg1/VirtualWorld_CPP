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
	int lifeTime;
	COORDS coordinates;
	int breedingTimeout;


public:
	Organism(World *world, char sign, int strength, int initative, int lifeTime, COORDS coordinates,int breedingTimeout);

	char GetSign()const;
	int GetStrength()const;
	int GetInitiative()const;
	int GetlifeTime()const;
	int GetIndex() const;
	int GetBreedingTimeout()const;
	COORDS GetCoordinates()const;

	void SetBreedingTimeout();
	void SetCoordinates(pair<int, int> coordinates);
	void UpdateLifeTime();

	virtual void Kill(Organism* a,bool won);
	COORDS RandomCoords(vector<COORDS> coords, World* world);
	virtual bool Block(Organism* other);
	virtual vector<COORDS> CheckSurrounding(World* world, COORDS coords,int action)=0;
	virtual void action(World *world) = 0;
	virtual void collision(Organism* other)=0;
	virtual ~Organism();

};


