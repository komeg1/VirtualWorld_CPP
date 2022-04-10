#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <utility>
#include "GameFunctions.h"
#define COORDS pair<int,int>
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
	bool doneTurn;
	pair <int, int> coordinates;

public:
	Organism(World *world, char sign, int strength, int initative, int lifeTime, COORDS coordinates, bool doneTurn);
	virtual char GetSign() const =0;
	virtual int GetStrength() const=0;
	virtual int GetInitiative() const=0;
	virtual int GetlifeTime() const=0;
	virtual bool GetTurn() const = 0;
	virtual COORDS GetCoordinates() const=0;

	void SetCoordinates(pair<int, int> coordinates);
	void SetTurn(bool a);
	void UpdateLifeTime();


	virtual void action(World *world) = 0;
	virtual bool collision(char moving, char waiting,World* world,COORDS a,COORDS b) = 0;
	virtual ~Organism();

};


