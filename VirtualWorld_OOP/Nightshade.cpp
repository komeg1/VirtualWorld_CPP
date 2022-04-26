#include "Nightshade.h"
#include "World.h"
Nightshade::Nightshade(int x, int y, World* world) : Plant(world, '!', 0, make_pair(x, y)) {
	AddToWorld(this);
}
Nightshade::Nightshade(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout) :
	Plant(world, sign, strength, initiative, coordinates, lifetime, breedingTimeout) {
	AddToWorld(this);
}
void Nightshade::Spread() {
	COORDS currentCoords = GetCoordinates();
	vector<COORDS> temp = CheckSurrounding(currentCoords, 1);
	if (temp.size() > 0)
	{
		world->CreateLog(this, this, BREED, world);
		COORDS newCoords = RandomCoords(temp);
		Nightshade* temp = new Nightshade(newCoords.first, newCoords.second, this->world);
		temp->SetbreedingTimeout();
		this->SetbreedingTimeout();
	}
}

Nightshade::~Nightshade()
{
}

void Nightshade::Collision(Organism* other)
{

	Kill(other, 1);
	CREATURES temp = world->GetCreaturesArray();
	temp.erase(temp.begin() + this->GetIndex());
	world->SetCreaturesArray(temp);
	other->~Organism();
	this->~Nightshade();
}


	