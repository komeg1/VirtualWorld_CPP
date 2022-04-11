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
		COORDS newCoords = RandomCoords(currentCoords,world);
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
							creaturesVec[i]->~Organism();
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
						if (creaturesVec[i]->GetCoordinates() == this->coordinates)
						{
							creaturesVec[i]->~Organism();
							for (int j = 0; j < creaturesVec.size(); j++)
							{
								if (creaturesVec[i]->GetCoordinates() == newCoords)
								{
									CreateLog(creaturesVec[i], this, KILL, world);
									return;
								}
							}
							
							
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
Animal::~Animal()
{
}
