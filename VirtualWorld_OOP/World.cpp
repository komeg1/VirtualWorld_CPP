#include "World.h"

World::World(int x, int y) : world_x(x), world_y(y)
{
	worldBoard = new char* [x];
	for (int i = 0; i < x; i++)
		worldBoard[i] = new char[y];
	updateBoard(worldBoard, this->creaturesArray);
}

World::World(): world_x(20), world_y(20)
{

	worldBoard = new char* [world_x];
	for (int i = 0; i < world_y; i++)
		worldBoard[i] = new char[world_y];
	updateBoard(worldBoard,this->creaturesArray);
}

int World::GetWorldX() const
{
	return world_x;
}

int World::GetWorldY() const
{
	return world_y;
}

vector<Organism*> World::GetCreaturesArray() const
{
	return creaturesArray;
}

void World::SetCreaturesArray(vector<Organism*> creatures)
{
	this->creaturesArray = creatures;
}

void World::nextTurn(World* world,vector<Organism*>creaturesArray) {
	for (int i = 0; i < creaturesArray.size(); i++)
		creaturesArray[i]->action();
	updateBoard(world->worldBoard, creaturesArray);
	draw(world->worldBoard);


}

void World::draw(char* worldBoard[])
{
	cout << "              Wirtualny Swiat\n              Tomasz Krezymon\n               Informatyka gr.2 189642\n";
	for (int i = 0; i < 20; i++)
	{
		cout << "            ";
		for (int j = 0; j < 20; j++)
			cout<< worldBoard[i][j];
		cout << endl;
	}
}

void World::updateBoard(char* worldBoard[], vector<Organism*> creaturesArray)
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			worldBoard[i][j] = '.';

	for (Organism* a : creaturesArray)
	{
		pair<int, int> x = a->GetCoordinates();
		worldBoard[x.second][x.first] = a->GetSign();
	}
}

World::~World()
{
}