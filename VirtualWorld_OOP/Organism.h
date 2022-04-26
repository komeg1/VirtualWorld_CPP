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
	int breedingTimeout = 0;
	COORDS coordinates;
	

public:
	Organism(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout);
	Organism(World *world, char sign, int strength, int initative, COORDS coordinates);
	
	char GetSign()const;
	int GetStrength()const;
	int GetInitiative()const;
	int GetlifeTime()const;
	int GetIndex() const;
	int GetbreedingTimeout()const;
	
	Organism* FindOrganism(COORDS coords);
	COORDS GetCoordinates()const;
	void GuaranaBoost();
	void AddToWorld(Organism* a);
	void SetbreedingTimeout();
	void SetCoordinates(pair<int, int> coordinates);
	void UpdateLifeTime();
	COORDS RandomCoords(vector<COORDS> coords);

	virtual void Kill(Organism* a,bool won)=0;
	virtual bool GetSkillIsActive()const;
	virtual int GetSkillTurnLeft()const;
	virtual int GetSkillTimeout()const;
	virtual bool Block(Organism* other);
	virtual vector<COORDS> CheckSurrounding(COORDS coords,int action);
	virtual void Action() = 0;
	virtual void Collision(Organism* other)=0;
	
	virtual ~Organism();

};


