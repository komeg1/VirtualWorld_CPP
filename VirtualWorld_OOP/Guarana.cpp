#include "Guarana.h"
#include "World.h"
#include "Animal.h"
Guarana::Guarana(int x, int y, World* world) : Plant(world, '$', 0, make_pair(x, y)) {
	AddToWorld(this);
}


void Guarana::Spread() {
	COORDS currentCoords = GetCoordinates();
	vector<COORDS> temp = CheckSurrounding(currentCoords, 1);
	if (temp.size() > 0)
	{
		world->CreateLog(this, this, BREED, world);
		COORDS newCoords = RandomCoords(temp);
		Guarana* temp = new Guarana(newCoords.first, newCoords.second, this->world);
		temp->SetBreedingTimeout();
		this->SetBreedingTimeout();
	}
}

Guarana::~Guarana()
{
}

void Guarana::Collision(Organism* other)
{
		
		CREATURES temp = world->GetCreaturesArray();
		temp.erase(temp.begin() + this->GetIndex());
		world->SetCreaturesArray(temp);
		other->GuaranaBoost();
		world->CreateLog(other, this, BOOST, world);
		other->SetCoordinates(this->GetCoordinates());
		this->~Guarana();
}