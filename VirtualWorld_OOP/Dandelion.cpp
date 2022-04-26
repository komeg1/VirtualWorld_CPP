#include "Dandelion.h"
#include "World.h"
Dandelion::Dandelion(int x, int y, World* world) : Plant(world, '&', 0, make_pair(x, y)) {
	AddToWorld(this);
}
Dandelion::Dandelion(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout) :
	Plant(world, sign, strength, initiative, coordinates, lifetime, breedingTimeout) {
	AddToWorld(this);
}
Dandelion::~Dandelion(){}

void Dandelion::Action() {
	
	for (int i = 0; i < 3; i++)
	{
		if (SpreadProbability() && this->GetbreedingTimeout() == 0)
		{
			this->Spread();
			return;
		}
	}
		if (this->GetbreedingTimeout() > 0)
			this->breedingTimeout--;

	
}

void Dandelion::Spread() {
	COORDS currentCoords = GetCoordinates();
	vector<COORDS> temp = CheckSurrounding(currentCoords, 1);
	if (temp.size() > 0)
	{
		world->CreateLog(this, this, BREED, world);
		COORDS newCoords = RandomCoords(temp);
		Dandelion* temp = new Dandelion(newCoords.first, newCoords.second, this->world);
		temp->SetbreedingTimeout();
		this->SetbreedingTimeout();
	}
}