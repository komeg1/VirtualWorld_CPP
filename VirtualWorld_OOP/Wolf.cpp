#include "Wolf.h"
#include "World.h"
Wolf::Wolf(int x, int y, World* world): Animal(world,'@',5,9,0,make_pair(x,y),0)
{
	world->worldBoard[y][x] = sign;
	vector<Organism*> temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
}



char Wolf::GetSign()const
{
	return sign;
}

int Wolf::GetStrength()const
{
	return strength;
}

int Wolf::GetInitiative()const
{
	return initiative;
}

int Wolf::GetlifeTime()const
{
	return lifeTime;
}

COORDS Wolf::GetCoordinates() const
{
	return coordinates;
}

bool Wolf::GetTurn() const {
	return doneTurn;
}


Wolf::~Wolf()
{
}
