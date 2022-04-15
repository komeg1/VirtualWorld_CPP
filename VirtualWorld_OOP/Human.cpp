#include "Human.h"
#include "World.h"
#include <Windows.h>
#include <conio.h>
Human::Human(int x, int y, World* world) : Animal(world, 'H', 5, 4, 0, make_pair(x, y), 0) {
	world->worldBoard[y][x] = sign;
	CREATURES temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
}

void Human::action(World*world) {
	COORDS currentCoords = GetCoordinates();
	COORDS newCoords = currentCoords;
	int c = 0;
	while (c == 0)
	{
		world->PrintConsole();
		cout << "Podaj ruch czlowieka:";
		
		c = _getch();
		c = _getch();
		system("CLS");
	}

	if (c == KEY_UP)
		newCoords.second--;
	if (c == KEY_LEFT)
		newCoords.first--;
	if (c == KEY_RIGHT)
		newCoords.first++;
	if (c == KEY_DOWN)
		newCoords.second++;
	
	if (newCoords.first < 0)
	{
		newCoords.first = 0;
		return;
	}
	if (newCoords.first == world->GetWorldX())
	{
		newCoords.first--;
		return;
	}
	if (newCoords.second < 0)
	{
		newCoords.second = 0;
		return;
	}
	if (newCoords.second == world->GetWorldY())
	{
		newCoords.second--;
		return;
	}



	CREATURES creaturesVec = world->GetCreaturesArray();
	char nextField = world->worldBoard[newCoords.second][newCoords.first];
	if (nextField != FIELD)
	{
		if (collision(sign, nextField, world, currentCoords, newCoords))
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
					this->~Human();
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