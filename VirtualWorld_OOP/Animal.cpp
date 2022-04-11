#include "Animal.h"
#include "GameFunctions.h"
#include "World.h"
#include "Wolf.h"
Animal::Animal(World* world, char sign, int strength, int initiative, int lifeTime, COORDS coordinates,bool doneTurn): 
	Organism(world,sign,strength,initiative,lifeTime,coordinates,doneTurn)
{
}
void Animal::action(World* world)
{
		COORDS currentCoords = GetCoordinates();
		COORDS newCoords = RandomCoords(currentCoords);
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
							CreateLog(this, creaturesVec[i], KILL, world);
							creaturesVec.erase(creaturesVec.begin() + (i));
							world->SetCreaturesArray(creaturesVec);
							SetCoordinates(newCoords);
							UpdateLifeTime();
							return;
						}
					}
				}
				else
				{
					for (int i = 0; i < creaturesVec.size(); i++)
					{
						if (creaturesVec[i]->GetCoordinates() == currentCoords)
						{
							CreateLog(creaturesVec[i], this, KILL, world);
							creaturesVec.erase(creaturesVec.begin() + (i));
							world->SetCreaturesArray(creaturesVec);
							UpdateLifeTime();
							return;
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
			SetCoordinates(newCoords);
			UpdateLifeTime();
		}
	}




bool Animal::collision(char movingAnimal, char waitingAnimal,World* world,COORDS currentCoords, COORDS newCoords)
{
	if (movingAnimal != waitingAnimal)
	{
		vector<Organism*> temp = world->GetCreaturesArray();
		int initiativeA = 0;
		int initiativeB = 0;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i]->GetCoordinates() == currentCoords)
			{
				initiativeA = temp[i]->GetInitiative();
			}
			if (temp[i]->GetCoordinates() == newCoords)
			{
				initiativeB = temp[i]->GetInitiative();
			}
		}
		return initiativeA > initiativeB;
	}
	return 0;
		

}

char Animal::GetSign()const
{
	return sign;
}

int Animal::GetStrength()const
{
	return strength;
}

int Animal::GetInitiative()const
{
	return initiative;
}

int Animal::GetlifeTime()const
{
	return lifeTime;
}

COORDS Animal::GetCoordinates() const
{
	return coordinates;
}

bool Animal::GetTurn() const {
	return doneTurn;
}

Animal::~Animal()
{
}
