#include "Sheep.h"
#include "World.h"
Sheep::Sheep(int x, int y, World* world) : Animal(world, '$', 4, 4, 0, make_pair(x, y), 0)
{
	world->worldBoard[y][x] = sign;
	vector<Organism*> temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
}
	char Sheep::GetSign() const
	{
		return sign;
	}

	int Sheep::GetStrength()const
	{
		return strength;
	}

	int Sheep::GetInitiative()const
	{
		return initiative;
	}

	int Sheep::GetlifeTime()const
	{
		return lifeTime;
	}

	COORDS Sheep::GetCoordinates() const
	{
		return coordinates;
	}

	

	bool Sheep::GetTurn() const {
		return doneTurn;
	}


	Sheep::~Sheep()
	{
	}

