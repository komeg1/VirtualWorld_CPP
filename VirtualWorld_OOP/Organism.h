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

public:
	Organism(World *world, char sign, int strength, int initative, int lifeTime, COORDS coordinates);

	char GetSign()const;
	int GetStrength()const;
	int GetInitiative()const;
	int GetlifeTime()const;
	int GetIndex() const;
	COORDS GetCoordinates()const;

	void SetCoordinates(pair<int, int> coordinates);
	void UpdateLifeTime();


	virtual void action(World *world) = 0;
	virtual bool collision(char moving, char waiting,World* world,COORDS a,COORDS b) = 0;
	virtual ~Organism();

};


