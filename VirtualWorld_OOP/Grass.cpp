#include "Grass.h"
#include "World.h"


Grass::Grass(int x, int y, World* world) : Plant(world, '~', 0, make_pair(x, y)) {
	AddToWorld(this);
}
Grass::Grass(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout) :
	Plant(world, sign, strength, initiative, coordinates, lifetime, breedingTimeout) {
	AddToWorld(this);
}

Grass::~Grass() {

}

void Grass::Spread()
{

		COORDS currentCoords = GetCoordinates();
		vector<COORDS> temp = CheckSurrounding(currentCoords, 1);
		if (temp.size() > 0)
		{
			world->CreateLog(this, this, BREED, world);
			COORDS newCoords = RandomCoords(temp);
			Grass* temp = new Grass(newCoords.first, newCoords.second, this->world);
			temp->SetbreedingTimeout();
			this->SetbreedingTimeout();
		}

}
