#include "Borscht.h"
Borscht::Borscht(int x, int y, World* world) : Plant(world, '#', 10, make_pair(x, y)) {
	AddToWorld(this);
}

void Borscht::KillAnimalsAround(vector<COORDS> area) {
	CREATURES temp = this->world->GetCreaturesArray();
	for (int i = 0; i < area.size(); i++)
	{
		Organism* organismTemp = FindOrganism(area[i]);
		if (organismTemp != nullptr && organismTemp->GetSign() != this->GetSign())
		{
			temp.erase(temp.begin() + organismTemp->GetIndex());
			world->SetCreaturesArray(temp);
			organismTemp->~Organism();
		}

	}
	


}

vector<COORDS> Borscht::CheckSurrounding(COORDS coords, int action)
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
			if (action == 1)
			{
				if (this->world->worldBoard[i][j] == FIELD)
					availableSurrounding.push_back(make_pair(j, i));
			}

			else if (action == 0)
			{
				if (this->world->worldBoard[i][j] != FIELD && this->world->worldBoard[i][j] != this->GetSign())
					availableSurrounding.push_back(make_pair(j, i));
			}
			
		}


	return availableSurrounding;
}

void Borscht::Spread() {
	COORDS currentCoords = GetCoordinates();
	vector<COORDS> temp = CheckSurrounding(currentCoords, 1);
	if (temp.size() > 0)
	{
		world->CreateLog(this, this, BREED, world);
		COORDS newCoords = RandomCoords(temp);
		Borscht* temp = new Borscht(newCoords.first, newCoords.second, this->world);
		temp->SetBreedingTimeout();
		this->SetBreedingTimeout();
	}
}

void Borscht::Action() {
	vector<COORDS> area = CheckSurrounding(this->GetCoordinates(), 0);
	KillAnimalsAround(area);
	if (SpreadProbability() && this->GetBreedingTimeout() == 0)
	{
		this->Spread();
		return;
	}
	if (this->GetBreedingTimeout() > 0)
		this->BreedingTimeout--;
}
void Borscht::Collision(Organism* other) {
	Kill(other, 1);
	CREATURES temp = world->GetCreaturesArray();
	temp.erase(temp.begin() + this->GetIndex());
	world->SetCreaturesArray(temp);
	other->~Organism();
	this->~Borscht();
	
}
Borscht::~Borscht() {
}