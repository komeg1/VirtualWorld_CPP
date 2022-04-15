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

void Grass::Spread(World* world)
{
	bool probability = SpreadProbability() & SpreadProbability();
	if (probability)
	{
		COORDS currentCoords = GetCoordinates();
		vector<COORDS> temp = CheckSurrounding(world, currentCoords, this->sign, 0);
		if (temp.size() > 0)
		{
			COORDS newCoords = RandomCoords(temp, world);
			Grass* temp = new Grass(newCoords.first, newCoords.second, world);
		}
	}
}
