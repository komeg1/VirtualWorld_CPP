#include "World.h"
#include <conio.h>
#include <Windows.h>
#include "GameFunctions.h"
World::World(int x, int y) : world_x(x), world_y(y), turn(1)
{
	worldBoard = new char* [world_y];
	for (int i = 0; i < world_y; i++)
		worldBoard[i] = new char[world_x];
	updateBoard();

}

World::World(): world_x(20), world_y(20), turn(1)
{

	worldBoard = new char* [world_y];
	for (int i = 0; i < world_y; i++)
		worldBoard[i] = new char[world_x];
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
int World::GetTurn() const {
	return turn;
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

//Sortowanie organizmów po inicjatywie/długosci życia
void World::SortCreaturesArray() {
	sort(creaturesArray.begin(), creaturesArray.end(), &comparator);
}



void World::nextTurn() {
	SortCreaturesArray();
	
	string turnLog = "Tura " + STR(turn) + ":";
	logs.push_back(turnLog);
	for (int i = 0; i < creaturesArray.size(); i++)
	{
			creaturesArray[i]->action(this);
			updateBoard();
			system("CLS");
			for (int i = 0; i < creaturesArray.size(); i++)
			{
				cout << creaturesArray[i]->GetSign() << " X: " << creaturesArray[i]->GetCoordinates().first << " Y: " << creaturesArray[i]->GetCoordinates().second << endl;
			}
			draw();
			
			PrintLogs(this);
			Sleep(1500);

	}
	turn++;

	
	
	
	


}


void World::draw()
{
	//cout << "              Wirtualny Swiat\n              Tomasz Krezymon\n               Informatyka gr.2 189642";
	for (int i = 0; i <GetWorldY(); i++)
	{
		cout <<"            ";
		for (int j = 0; j < GetWorldX(); j++)
			cout<< worldBoard[i][j]<<" ";
		cout << endl;
	}
}

void World::updateBoard()
{
	for (int i = 0; i < GetWorldY(); i++)
		for (int j = 0; j < GetWorldX(); j++)
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