#include "World.h"
#include <conio.h>

World::World(int x, int y) : world_x(x), world_y(y)
{
	worldBoard = new char* [x];
	for (int i = 0; i < x; i++)
		worldBoard[i] = new char[y];
	updateBoard();

}

World::World(): world_x(20), world_y(20)
{

	worldBoard = new char* [world_x];
	for (int i = 0; i < world_y; i++)
		worldBoard[i] = new char[world_y];
	updateBoard();
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

vector<string> World::GetLogs() const
{
	return logs;
}



void World::SetCreaturesArray(vector<Organism*> creatures)
{
	this->creaturesArray = creatures;
}

void World::SetLogs(vector<string> logs)
{
	this->logs = logs;
}

void World::nextTurn() {
	sort(creaturesArray.begin(), creaturesArray.end(),&comparator);
	//for (int i = 0; i < world->creaturesArray.size(); i++)
		//cout << world->creaturesArray[i]->GetSign() <<" x: "<<world->creaturesArray[i]->GetCoordinates().first<<" y: "<< world->creaturesArray[i]->GetCoordinates().second<<" Inicjatywa: "<<world->creaturesArray[i]->GetInitiative()<<" Lifetime: "<<world->creaturesArray[i]->GetlifeTime()<<  endl;
		//cout << endl;
	
	for (int i = 0; i < creaturesArray.size(); i++)
	{
			creaturesArray[i]->action(this);
			updateBoard();
			
	}
	draw();
	for (int i = 0; i < logs.size(); i++)
	{
		cout << i + 1 << ". " << logs[i] << "\n";
	}
	logs.clear();
	
	
	
	


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
		for (int j = 0; j < GetWorldY(); j++)
			worldBoard[i][j] = FIELD;

	for (Organism* a : creaturesArray)
	{
		pair<int, int> x = a->GetCoordinates();
		worldBoard[x.second][x.first] = a->GetSign();
	}
}

World::~World()
{
}