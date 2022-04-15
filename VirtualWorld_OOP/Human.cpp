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
	if (CheckIfOrganism(newCoords, world))
	{
		Organism* other = FindOrganism(newCoords, world);
		other->collision(this);

	}
	else
	{
		this->SetCoordinates(newCoords);
		this->UpdateLifeTime();
	}
}

bool Human::breeding(World* world, Organism* other)
{
	return false;
}


