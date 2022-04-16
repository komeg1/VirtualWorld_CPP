#include "Guarana.h"
#include "World.h"

Guarana::Guarana(int x, int y, World* world) : Plant(world, '$', 0, 0, 0, make_pair(x, y), 0) {
	world->worldBoard[y][x] = sign;
	CREATURES temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
}

Guarana::~Guarana();

void Guarana::Spread() {
	COORDS currentCoords = GetCoordinates();
	vector<COORDS> temp = CheckSurrounding(world, currentCoords, 1);
	if (temp.size() > 0)
	{
		world->CreateLog(this, this, BREED, world);
		COORDS newCoords = RandomCoords(temp, world);
		Guarana* temp = new Guarana(newCoords.first, newCoords.second, this->world);
		temp->SetBreedingTimeout();
		this->SetBreedingTimeout();
	}
}

void Guarana::collision(Organism* other)
{
	
	 if (this->GetStrength() < other->GetStrength())
	{
		COORDS newCoordinates = this->GetCoordinates();
		Kill(other, 0);
		this->~Plant();
		other->GuaranaBoost();
		other->SetCoordinates(newCoordinates);
	}

	return;
}