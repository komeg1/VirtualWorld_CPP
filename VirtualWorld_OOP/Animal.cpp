#include "Animal.h"
#include "World.h"
#include "Wolf.h"
Animal::Animal(World* world, char sign, int strength, int initiative, int lifeTime, COORDS coordinates): 
	Organism(world,sign,strength,initiative,lifeTime,coordinates)
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
									CreateLog(creaturesVec[i], this, KILL, world);
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
			SetCoordinates(newCoords);
			UpdateLifeTime();
		}
	}




bool Animal::collision(char movingAnimal, char waitingAnimal,World* world,COORDS currentCoords, COORDS newCoords)
{
		vector<Organism*> temp = world->GetCreaturesArray();
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
		if (this->strength == strengthB)
			return this->lifeTime > lifeTimeB;
		return this->strength > strengthB;
	return 0;
		

}
Animal::~Animal()
{
}
