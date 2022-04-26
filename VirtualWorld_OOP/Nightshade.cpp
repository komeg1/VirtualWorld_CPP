#include "Nightshade.h"
#include "World.h"
Nightshade::Nightshade(int x, int y, World* world) : Plant(world, '!', 0, make_pair(x, y)) {
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
		temp->SetBreedingTimeout();
		this->SetBreedingTimeout();
	}
}

Nightshade::~Nightshade()
{
}

void Nightshade::Collision(Organism* other)
{

		Kill(other, 1);
		other->~Organism();
		this->~Nightshade();
		return;
}

void Nightshade::Kill(Organism* a, bool won)
{
	CREATURES temp;
		this->world->CreateLog(this, a, EAT, world);
		temp = world->GetCreaturesArray();
		temp.erase(temp.begin() + a->GetIndex());
		temp.erase(temp.begin() + this->GetIndex());
		world->SetCreaturesArray(temp);
		return;



}

	