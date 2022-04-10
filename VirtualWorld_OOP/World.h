#pragma once

#include "Organism.h"
using namespace std;
class World
{
private:
	int world_x;
	int world_y;
	vector <Organism*> creaturesArray;
	
public:
	char** worldBoard;
	World(int x, int y);
	World();

	int GetWorldX() const;
	int GetWorldY() const;
	vector<Organism*> GetCreaturesArray() const;
	void SetCreaturesArray(vector<Organism*> creatures);
	void nextTurn(World* world);
	void draw(char* worldBoard[]);
	void updateBoard(char* worldBoard[], vector<Organism*> creaturesArray);


	~World();
};

