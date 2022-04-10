#pragma once
#include "Animal.h"
class Sheep : public Animal
{
public:
	Sheep(int x, int y, World* world);
	char GetSign() const override;
	bool GetTurn() const override;
	int GetStrength()const override;
	int GetInitiative() const override;
	int GetlifeTime() const override;
	COORDS GetCoordinates() const override;


	~Sheep() override;
};

