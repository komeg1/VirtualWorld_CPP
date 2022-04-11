#include "Wolf.h"
#include "World.h"
Wolf::Wolf(int x, int y, World* world): Animal(world,'W',5,9,0,make_pair(x,y),0)
{
	world->worldBoard[y][x] = sign;
	vector<Organism*> temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
	SetIterator(world);

}

Wolf::~Wolf()
{
	world->GetCreaturesArray().erase(this->it);
}
