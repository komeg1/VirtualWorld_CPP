#include "Fox.h"
#include "World.h"
Fox::Fox(int x, int y, World* world) : Animal(world, 'F', 7, 3, 0, make_pair(x, y), 0)
{
	world->worldBoard[y][x] = sign;
	vector<Organism*> temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
	SetIterator(world);
}

void Fox::action(World* world)
{
	COORDS currentCoords = GetCoordinates();
	COORDS newCoords = RandomCoords(currentCoords,world);
	int x = newCoords.first;
	int y = newCoords.second;
	char nextField = world->worldBoard[y][x];
	char currentAnimal = GetSign();
	vector<Organism*> creaturesVec = world->GetCreaturesArray();
	//cout << "NOWE KOORDYNATY "<<currentAnimal<<" x: " << x << " y: " << y<< " ZNAK: " << nextField << endl;
	if (nextField != FIELD)
	{
		for (int i = 0; i < creaturesVec.size(); i++)
		{
			if (creaturesVec[i]->GetCoordinates() == newCoords)
			{
				if (creaturesVec[i]->GetInitiative() < initiative)
				{
					CreateLog(this, creaturesVec[i], KILL, world);
					creaturesVec.erase(creaturesVec.begin() + (i));
					world->SetCreaturesArray(creaturesVec);
					SetCoordinates(newCoords);
					UpdateLifeTime();
					return;
				}
				else
					action(world);
			}
		}
	}
	else
	{
		SetCoordinates(newCoords);
		UpdateLifeTime();
	}
}
Fox::~Fox()
{
}