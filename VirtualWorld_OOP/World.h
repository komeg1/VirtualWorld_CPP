#pragma once

#include "Organism.h"
#include <map>
using namespace std;
class World
{
private:
	int world_x;
	int world_y;
	vector <Organism*> creaturesArray;
	vector <string> logs;
	int turn;
	
	
public:
	char** worldBoard;
	World(int x, int y);
	World();

	int GetTurn() const;
	int GetWorldX() const;
	int GetWorldY() const;
	vector<Organism*> GetCreaturesArray() const;
	vector<string> GetLogs()const;
	void SetCreaturesArray(vector<Organism*> creatures);
	void SortCreaturesArray();
	static bool comparator(const Organism* a, const Organism* b);
	void CreateLog(Organism* a, Organism* b, int log_type, World* world);
	void PrintLogs(World* world);
	void SetLogs(vector<string> logs);
	void NextTurn();
	void PrintConsole();
	void PrintHumanInformation();
	void Draw();
	void UpdateBoard();


	~World();
};

