#include "World.h"
#include <conio.h>
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

void World::nextTurn(World* world) {
	sort(world->creaturesArray.begin(), world->creaturesArray.end(),&comparator);
	//for (int i = 0; i < world->creaturesArray.size(); i++)
		//cout << world->creaturesArray[i]->GetSign() <<" x: "<<world->creaturesArray[i]->GetCoordinates().first<<" y: "<< world->creaturesArray[i]->GetCoordinates().second<<" Inicjatywa: "<<world->creaturesArray[i]->GetInitiative()<<" Lifetime: "<<world->creaturesArray[i]->GetlifeTime()<<  endl;
		//cout << endl;
	draw(world->worldBoard);
	for (int i = 0; i < world->creaturesArray.size(); i++)
	{
			world->creaturesArray[i]->action(world);
			updateBoard(world->worldBoard, world->creaturesArray);
			
	}
	
	
	
	
	for (int i = 0; i < world->creaturesArray.size(); i++)
		world->creaturesArray[i]->SetTurn(0);


}


void World::draw()
{
	//cout << "              Wirtualny Swiat\n              Tomasz Krezymon\n               Informatyka gr.2 189642";
	for (int i = 0; i <GetWorldX(); i++)
	{
		cout <<"            ";
		for (int j = 0; j < GetWorldY(); j++)
			cout<< worldBoard[i][j]<<" ";
		cout << endl;
	}
}

void World::updateBoard()
{
	for (int i = 0; i < GetWorldX(); i++)
		for (int j = 0; j < 20; j++)
			worldBoard[i][j] = '~';

	for (Organism* a : creaturesArray)
	{
		pair<int, int> x = a->GetCoordinates();
		worldBoard[x.second][x.first] = a->GetSign();
	}
}

World::~World()
{
}