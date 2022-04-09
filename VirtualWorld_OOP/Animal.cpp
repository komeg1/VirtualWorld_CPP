#include "Animal.h"
#include "GameFunctions.h"
Animal::Animal(World* world, char sign, int strength, int initative, int lifeTime, pair<int, int> coordinates): 
	Organism(world,sign,strength,initiative,lifeTime,coordinates)
{
}
void Animal::action()
{
	SetCoordinates(Move());
}

void Animal::collision()
{
}

pair <int,int> Animal::Move()
{
	pair<int, int> coords = RandomCoords(GetCoordinates());
	cout << coords.first << " " << coords.second<<endl;
	return coords;
}

Animal::~Animal()
{
}
