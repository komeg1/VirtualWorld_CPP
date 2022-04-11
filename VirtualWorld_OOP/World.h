#pragma once

#include "Organism.h"
using namespace std;
class World
{
private:
	int world_x;
	int world_y;
	vector <Organism*> creaturesArray;
	vector <string> logs;
	
public:
	char** worldBoard;
	World(int x, int y);
	World();

	int GetWorldX() const;
	int GetWorldY() const;
	vector<Organism*> GetCreaturesArray() const;
	vector<string> GetLogs()const;
	void SetCreaturesArray(vector<Organism*> creatures);
	void SetLogs(vector<string> logs);
	void nextTurn();
	void draw();
	void updateBoard();


	~World();
};

