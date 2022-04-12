#include "Fox.h"
#include "World.h"
Fox::Fox(int x, int y, World* world) : Animal(world, 'F', 3, 7, 0, make_pair(x, y))
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
	vector<COORDS> area = CheckSurrounding(world,currentCoords,this->GetSign());
	if (area.size() == 0)
		return;
	else
	{
		COORDS newCoords = FoxUpdateCoords(area);
		SetCoordinates(newCoords);
		UpdateLifeTime();
	}
}
COORDS Fox::FoxUpdateCoords(vector<COORDS> area)
{
	
	int randVal = rand() % area.size();
	return area[randVal];
	
		
}
Fox::~Fox()
{
}