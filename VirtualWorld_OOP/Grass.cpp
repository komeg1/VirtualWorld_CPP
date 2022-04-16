#include "Grass.h"
#include "World.h"


Grass::Grass(int x, int y, World* world) : Plant(world, '~', 0, 0, 0, make_pair(x, y), 0) {
	world->worldBoard[y][x] = sign;
	CREATURES temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
}


Grass::~Grass() {

}

void Grass::Spread()
{

		COORDS currentCoords = GetCoordinates();
		vector<COORDS> temp = CheckSurrounding(world, currentCoords, 1);
		if (temp.size() > 0)
		{
			world->CreateLog(this, this, BREED, world);
			COORDS newCoords = RandomCoords(temp, world);
			Grass* temp = new Grass(newCoords.first, newCoords.second, this->world);
			temp->SetBreedingTimeout();
			this->SetBreedingTimeout();
		}

}
