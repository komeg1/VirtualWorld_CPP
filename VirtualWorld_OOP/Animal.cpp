#include "Animal.h"
#include "World.h"
#include "Wolf.h"

Animal::Animal(World* world, char sign, int strength, int initiative, int lifeTime, COORDS coordinates,int breedingTimeout): 
	Organism(world,sign,strength,initiative,lifeTime,coordinates,breedingTimeout)
{
}
void Animal::action(World* world)
{
		COORDS currentCoords = GetCoordinates();
		vector<COORDS> temp = CheckSurrounding(world, currentCoords, this->sign,0);
		COORDS newCoords = RandomCoords(temp,world);
		int x = newCoords.first;
		int y = newCoords.second;
		char nextField = world->worldBoard[y][x];
		char currentAnimal = GetSign();

		vector<Organism*> creaturesVec = world->GetCreaturesArray();
		//cout << "NOWE KOORDYNATY "<<currentAnimal<<" x: " << x << " y: " << y<< " ZNAK: " << nextField << endl;
		if (currentAnimal != nextField)
		{
			if (nextField != FIELD)
			{
				if (collision(currentAnimal, nextField, world, currentCoords, newCoords))
				{
					for (int i = 0; i < creaturesVec.size(); i++)
					{
						if (creaturesVec[i]->GetCoordinates() == newCoords)
						{
							world->CreateLog(this, creaturesVec[i], KILL, world);
							creaturesVec[i]->~Organism();
							creaturesVec.erase(creaturesVec.begin() + i);
							SetCoordinates(newCoords);
							UpdateLifeTime();
							world->SetCreaturesArray(creaturesVec);
							return;
						}
					}
				}
				else
				{
							for (int i = 0; i < creaturesVec.size(); i++)
							{
								if (creaturesVec[i]->GetCoordinates() == newCoords)
								{
									world->CreateLog(creaturesVec[i], this, KILL, world);
									world->worldBoard[currentCoords.first][currentCoords.second] = FIELD;
									creaturesVec.erase(creaturesVec.begin() + this->GetIndex());
									this->~Animal();
									world->SetCreaturesArray(creaturesVec);
								}
							}
							
							
				}
				}
			else
			{
				SetCoordinates(newCoords);
				UpdateLifeTime();
			}
		}
		else
		{
			Organism* temp = nullptr;
			for (int i = 0; i < creaturesVec.size(); i++)
				if (creaturesVec[i]->GetCoordinates() == newCoords)
					temp = creaturesVec[i];
			if (this->breedingTimeout == 0&& temp->GetBreedingTimeout() == 0)
			{
				
				if (breeding(world))
				{
					world->CreateLog(this, this, BREED, world);
					temp->SetBreedingTimeout();
					this->SetBreedingTimeout();
				}
			}
			world->SortCreaturesArray();
			UpdateLifeTime();
		}

		if (breedingTimeout > 0)
			breedingTimeout--;
	}

vector<COORDS> Animal::CheckSurrounding(World* world, COORDS coords, char thisAnimal,int action)
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
			else if (world->worldBoard[i][j] == FIELD)
				availableSurrounding.push_back(make_pair(j, i));
			else {
				if (action != 1)
					availableSurrounding.push_back(make_pair(j, i));
			}
		}


	return availableSurrounding;
}





bool Animal::collision(char movingAnimal, char waitingAnimal,World* world,COORDS currentCoords, COORDS newCoords)
{

		vector<Organism*> temp = world->GetCreaturesArray();
		if (movingAnimal != waitingAnimal)
		{
			int strengthB = 0;
			int lifeTimeB = 0;
			for (int i = 0; i < temp.size(); i++)
			{
				if (temp[i]->GetCoordinates() == newCoords)
				{
					strengthB = temp[i]->GetStrength();
					lifeTimeB = temp[i]->GetlifeTime();
				}
			}
			if (CheckIfBlocked())
			{
				if (this->strength == strengthB)
					return this->lifeTime > lifeTimeB;
				return this->strength > strengthB;
			}
		}
		else


		
	return 0;
		

}
bool Animal::breeding(World* world)
{
	return false;
}
Animal::~Animal()
{
}
