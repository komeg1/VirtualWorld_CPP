#pragma once
#include "Organism.h"

class Plant : public Organism {
public:
	Plant(World* world, char sign, int strength, int initative, int lifeTime, COORDS coordinates, int breedingTimeout);
	void action(World* world) override;
	bool SpreadProbability();

	virtual void Spread(World* world) = 0;
	~Plant()override;
};