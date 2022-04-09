#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <utility>
#include "GameFunctions.h"
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
	pair <int, int> coordinates;

public:
	Organism(World *world, char sign, int strength, int initative, int lifeTime, pair<int,int> coordinates);
	virtual char GetSign() const =0;
	virtual int GetStrength() const=0;
	virtual int GetInitiative() const=0;
	virtual int GetlifeTime() const=0;
	virtual pair <int, int> GetCoordinates() const=0;

	void SetCoordinates(pair<int, int> coordinates);
	void UpdateLifeTime();


	virtual void action() = 0;
	virtual void collision() = 0;
	virtual ~Organism();
};

