#include "Guarana.h"
#include "World.h"
#include "Animal.h"
Guarana::Guarana(int x, int y, World* world) : Plant(world, '$', 0, 0, make_pair(x, y)) {
	world->worldBoard[y][x] = sign;
	CREATURES temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
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

void Guarana::collision(Organism* other)
{
		world->CreateLog(other, this, BOOST, world);
		CREATURES temp = world->GetCreaturesArray();
		temp.erase(temp.begin() + this->GetIndex());
		world->SetCreaturesArray(temp);
		other->GuaranaBoost();
		other->SetCoordinates(this->GetCoordinates());
		this->~Guarana();
}