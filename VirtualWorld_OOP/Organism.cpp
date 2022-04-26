#include "Organism.h"
#include "World.h"

Organism::Organism(World* world, char sign, int strength, int initiative, COORDS coordinates) : 
	world(world), sign(sign), strength(strength), initiative(initiative), coordinates(coordinates)
{

}

void Organism::GuaranaBoost()
{
		this->strength += 3;
}
Organism* Organism::FindOrganism(COORDS newCoords) {
	for (Organism* a : this->world->GetCreaturesArray())
	{
		if (a->GetCoordinates() == newCoords)
			return a;
	}
	return nullptr;
}
void Organism::AddToWorld(Organism* a)
{
	int x = a->GetCoordinates().first,
		y = a->GetCoordinates().second;
	world->worldBoard[y][x] = a->GetSign();
	CREATURES temp = world->GetCreaturesArray();
	temp.push_back(a);
	world->SetCreaturesArray(temp);
}

void Organism::SetBreedingTimeout()
{
	BreedingTimeout = BREEDING_CNTDOWN;
}

void Organism::SetCoordinates(pair<int, int> coordinates)
{
	this->coordinates = coordinates;
}


void Organism::UpdateLifeTime()
{
	this->lifeTime++;
}

COORDS Organism::RandomCoords(vector<COORDS> area)
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
	return BreedingTimeout;
}

COORDS Organism::GetCoordinates()const
{
	return coordinates;
}






vector<COORDS> Organism::CheckSurrounding(COORDS coords, int action)
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
	if (x2 == this->world->GetWorldX())
		x2--;
	if (y2 == this->world->GetWorldY())
		y2--;

	for (int i = y1; i <= y2; i++)
		for (int j = x1; j <= x2; j++)
		{
			if (this->world->worldBoard[i][j] == this->GetSign() && make_pair(j, i) == coords)
				continue;
			else if (this->world->worldBoard[i][j] == FIELD)
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


