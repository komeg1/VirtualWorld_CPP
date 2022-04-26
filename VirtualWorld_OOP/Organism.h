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
	int BreedingTimeout = 0;


public:
	Organism(World *world, char sign, int strength, int initative, COORDS coordinates);

	char GetSign()const;
	int GetStrength()const;
	int GetInitiative()const;
	int GetlifeTime()const;
	int GetIndex() const;
	int GetBreedingTimeout()const;
	virtual bool GetSkillIsActive()const;
	virtual int GetSkillTurnLeft()const;
	virtual int GetSkillTimeout()const;
	COORDS GetCoordinates()const;
	void GuaranaBoost();
	Organism* FindOrganism(COORDS coords);
	void AddToWorld(Organism* a);
	void SetBreedingTimeout();
	void SetCoordinates(pair<int, int> coordinates);
	void UpdateLifeTime();
	virtual void Kill(Organism* a,bool won)=0;
	COORDS RandomCoords(vector<COORDS> coords);
	virtual bool Block(Organism* other);
	virtual vector<COORDS> CheckSurrounding(COORDS coords,int action);
	virtual void Action() = 0;
	virtual void Collision(Organism* other)=0;
	virtual ~Organism();

};


