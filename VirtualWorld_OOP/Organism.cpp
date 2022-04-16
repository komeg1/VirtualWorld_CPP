#include "Organism.h"
#include "World.h"

Organism::Organism(World* world, char sign, int strength, int initiative, int lifeTime, COORDS coordinates,int breedingTimeout) : 
	world(world), sign(sign), strength(strength), initiative(initiative), lifeTime(lifeTime), coordinates(coordinates), breedingTimeout(breedingTimeout)
{

}


void Organism::SetBreedingTimeout()
{
	breedingTimeout = BREEDING_CNTDOWN;
}

void Organism::SetCoordinates(pair<int, int> coordinates)
{
	this->coordinates = coordinates;
}


void Organism::UpdateLifeTime()
{
	this->lifeTime++;
}

COORDS Organism::RandomCoords(vector<COORDS> area, World* world)
{
		if (area.size() > 0)
		{
			int randVal = rand() % area.size();
			return area[randVal];
		}
		return make_pair(-1, -1);
	
}

bool Organism::Block(Organism* other)
{
	return false;
}


char Organism::GetSign()const
{
	return sign;
}

int Organism::GetStrength()const
{
	return strength;
}

int Organism::GetInitiative()const
{
	return initiative;
}

int Organism::GetlifeTime()const
{
	return lifeTime;
}

int Organism::GetIndex() const
{
	vector<Organism*> temp = world->GetCreaturesArray();
	for (int i = 0; i < temp.size(); i++)
		if (this->coordinates == temp[i]->coordinates)
			return i;
}

int Organism::GetBreedingTimeout() const
{
	return breedingTimeout;
}

COORDS Organism::GetCoordinates()const
{
	return coordinates;
}






vector<COORDS> Organism::CheckSurrounding(World* world, COORDS coords, int action)
{
	int x1 = coords.first - 1,
		x2 = coords.first + 1,
		y1 = coords.second - 1,
		y2 = coords.second + 1;
	vector<COORDS> availableSurrounding;
	if (x1 < 0)
		x1 = 0;
	if (y1 < 0)
		y1 = 0;
	if (x2 == world->GetWorldX())
		x2--;
	if (y2 == world->GetWorldY())
		y2--;

	for (int i = y1; i <= y2; i++)
		for (int j = x1; j <= x2; j++)
		{
			if (world->worldBoard[i][j] == this->GetSign() && make_pair(j, i) == coords)
				continue;
			else if (world->worldBoard[i][j] == FIELD)
				availableSurrounding.push_back(make_pair(j, i));
			else {
				if (action != 1)
					availableSurrounding.push_back(make_pair(j, i));
			}
		}


	return availableSurrounding;
}

Organism::~Organism()
{
	
}


