#include "Dandelion.h"
#include "World.h"
Dandelion::Dandelion(int x, int y, World* world) : Plant(world, '&', 0, 0, 0, make_pair(x, y), 0) {
	world->worldBoard[y][x] = sign;
	CREATURES temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
}

Dandelion::~Dandelion(){}

void Dandelion::action(World* world) {
	
	for (int i = 0; i < 3; i++)
	{
		if (SpreadProbability() && this->GetBreedingTimeout() == 0)
		{
			this->Spread();
			return;
		}
	}
		if (this->GetBreedingTimeout() > 0)
			this->breedingTimeout--;

	
}

void Dandelion::Spread() {
	COORDS currentCoords = GetCoordinates();
	vector<COORDS> temp = CheckSurrounding(world, currentCoords, 1);
	if (temp.size() > 0)
	{
		world->CreateLog(this, this, BREED, world);
		COORDS newCoords = RandomCoords(temp, world);
		Dandelion* temp = new Dandelion(newCoords.first, newCoords.second, this->world);
		temp->SetBreedingTimeout();
		this->SetBreedingTimeout();
	}
}