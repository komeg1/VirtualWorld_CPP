#include "Fox.h"
#include "World.h"
Fox::Fox(int x, int y, World* world) : Animal(world, 'F', 3, 7, 0, make_pair(x, y),0)
{
	world->worldBoard[y][x] = sign;
	CREATURES temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
}

void Fox::action(World* world)
{
	COORDS currentCoords = GetCoordinates();
	CREATURES creaturesVec = world->GetCreaturesArray();
	vector<COORDS> area = CheckSurrounding(world,currentCoords,this->GetSign(),0);
	if (area.size() == 0)
		return;
	else
	{
		COORDS newCoords = FoxUpdateCoords(area);
		if (world->worldBoard[newCoords.second][newCoords.first] != 'F')
			SetCoordinates(newCoords);
		else 
		{
			if (this->GetBreedingTimeout() == 0)
			{
				breeding(world);
				world->CreateLog(this, this, BREED, world);
				this->SetBreedingTimeout();
				for (int i = 0; i < creaturesVec.size(); i++)
					if (creaturesVec[i]->GetCoordinates() == newCoords)
						creaturesVec[i]->SetBreedingTimeout();
			}
		}
		UpdateLifeTime();
		if (breedingTimeout > 0)
			breedingTimeout--;
	}
}
COORDS Fox::FoxUpdateCoords(vector<COORDS> area)
{
	
	int randVal = rand() % area.size();
	return area[randVal];
	
		
}
bool Fox::breeding(World* world)
{
	COORDS newCreatureCoords = RandomCoords(CheckSurrounding(world, coordinates, this->sign, 1), world);
	if (newCreatureCoords != make_pair(-1, -1))
	{
		Fox* child = new Fox(newCreatureCoords.first, newCreatureCoords.second, world);
		child->breedingTimeout = BREEDING_CNTDOWN;
		return 1;
	}
	return 0;
	}



bool Fox::IsStronger(COORDS a, COORDS b, World* world)
{
	int strengthA = 0;
	int strengthB = 0;

	for (int i = 0; i < world->GetCreaturesArray().size(); i++)
	{
		if (world->GetCreaturesArray()[i]->GetCoordinates() == a)
			strengthA = world->GetCreaturesArray()[i]->GetStrength();
		if (world->GetCreaturesArray()[i]->GetCoordinates() == b)
			strengthB = world->GetCreaturesArray()[i]->GetStrength();
	}

	return strengthA > strengthB;
}

vector<COORDS> Fox::CheckSurrounding(World* world, COORDS coords, char thisAnimal, int action)
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
			if (world->worldBoard[i][j] == thisAnimal && make_pair(j, i) == coords)
				continue;
			else if (world->worldBoard[i][j] != FIELD&&world->worldBoard[i][j] != this->sign)
			{
				if (IsStronger(coords, make_pair(j, i), world))
					availableSurrounding.push_back(make_pair(j, i));
			}
			else if (world->worldBoard[i][j] == FIELD)
				availableSurrounding.push_back(make_pair(j, i));
			else if(action!=1)
			{
				availableSurrounding.push_back(make_pair(j, i));
			}
		}


	return availableSurrounding;
}


Fox::~Fox()
{
}