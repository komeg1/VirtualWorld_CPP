#include "World.h"
#include <conio.h>
#include <Windows.h>
#include <sstream>
World::World(int x, int y) : world_x(x), world_y(y), turn(1)
{
	worldBoard = new char* [world_y];
	for (int i = 0; i < world_y; i++)
		worldBoard[i] = new char[world_x];
	UpdateBoard();

}

World::World(): world_x(20), world_y(20), turn(1)
{

	worldBoard = new char* [world_y];
	for (int i = 0; i < world_y; i++)
		worldBoard[i] = new char[world_x];
	UpdateBoard();
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
	sort(creaturesArray.begin(), creaturesArray.end(), &World::comparator);
}

bool World::comparator(const Organism* a, const Organism* b)
{
	if (a->GetInitiative() == b->GetInitiative())
		return a->GetlifeTime() > b->GetlifeTime();
	return a->GetInitiative() > b->GetInitiative();
}

void World::NextTurn() {
	SortCreaturesArray();	
	string turnLog = "Tura " + STR(turn) + ":";
	logs.push_back(turnLog);
	for (int i = 0; i < creaturesArray.size(); i++)
	{
			creaturesArray[i]->Action();
			UpdateBoard();
			
	}
	PrintConsole();
	
	

	
	turn++;
}

void World::PrintConsole() {
	system("CLS");
	NAME;
	Draw();
	PrintLogs(this);
	
}
void World::Draw()
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

void World::UpdateBoard()
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

void World::CreateLog(Organism* a, Organism* b, int log_type, World* world)
{
	ostringstream tmpmsg;
	string finalmsg;
	char ac = a->GetSign();
	char bc = b->GetSign();
	switch (log_type)
	{
	case KILL:
		tmpmsg << "-ZABOJSTWO: '" << ac << "' zabil '" << bc <<
			"' na polu x: " << STR(b->GetCoordinates().first+1) << " y: " + STR(b->GetCoordinates().second+1);
		finalmsg = tmpmsg.str();
		break;
	case BREED:
		tmpmsg << "-ROZMNOZENIE: '" << ac <<
			"' na polu x: " << STR(b->GetCoordinates().first+1) << " y: " << STR(b->GetCoordinates().second+1);
		finalmsg = tmpmsg.str();
		break;
	case BREEDTIME:
		tmpmsg << "-NIEUDANA PROBA ROZMNOZENIA: " << ac << " na polu x: " << STR(b->GetCoordinates().first + 1) << " y: " << STR(b->GetCoordinates().second + 1);
		finalmsg = tmpmsg.str();
		break;
	case BLOCK:
		tmpmsg<<"-BLOK: "<<ac<< " zablokowal atak "<<bc<< " na polu x: " << STR(b->GetCoordinates().first + 1) << " y: " << STR(b->GetCoordinates().second + 1);
		finalmsg = tmpmsg.str();
		break;
	case RUN:
		tmpmsg << "-UCIECZKA: " << ac << " ucieka przed atakiem" << bc << " na polu x: " << STR(b->GetCoordinates().first + 1) << " y: " << STR(b->GetCoordinates().second + 1);
		finalmsg = tmpmsg.str();
		break;
	case EAT:
		tmpmsg << "-JEDZENIE: " << ac << " zjadl " << bc << " na polu x: " << STR(b->GetCoordinates().first + 1) << " y: " << STR(b->GetCoordinates().second + 1);
		finalmsg = tmpmsg.str();
		break;
	case BOOST:
		tmpmsg << "-WZMOCNIENIE: " << ac << " zjadl guarane" << " na polu x: " << STR(b->GetCoordinates().first + 1) << " y: " << STR(b->GetCoordinates().second + 1)<<" SILA WYNOSI "<<a->GetStrength();
		finalmsg = tmpmsg.str();
		break;
	}

	vector<string> tempLog = world->GetLogs();
	tempLog.push_back(finalmsg);
	world->SetLogs(tempLog);
}

void World::PrintLogs(World* world)
{
	vector<string> logs = world->GetLogs();
	cout << "========================ZDARZENIA================================\n";
	if (logs.size() < 10) {
		for (string log : logs)
			cout << log << "\n";
	}
	else
		for (int i = logs.size() - 10; i < logs.size(); i++)
			cout << logs[i] << "\n";
	cout << "=================================================================";
	cout << "\nILOSC ZWIERZAT:" << world->GetCreaturesArray().size();


}