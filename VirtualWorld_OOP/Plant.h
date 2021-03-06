#pragma once
#include "Organism.h"

class Plant : public Organism {
public:
	Plant(World* world, char sign, int strength, COORDS coordinates);
	Plant(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout);
	void Action() override;
	void Kill(Organism* a, bool won)override;
	void Collision(Organism* other) override;
	virtual void Spread() = 0;
	bool SpreadProbability();
	~Plant()override;

};