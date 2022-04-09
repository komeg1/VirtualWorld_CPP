#include "Wolf.h"
#include "World.h"
Wolf::Wolf(int x, int y, World* world): Animal(world,'@',5,9,0,make_pair(x,y))
{
	world->worldBoard[x][y] = sign;
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

pair<int, int> Wolf::GetCoordinates() const
{
	return coordinates;
}

void Wolf::collision()
{
	printf("X");
}

Wolf::~Wolf()
{
}
