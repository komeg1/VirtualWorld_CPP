#pragma once
#include <iostream>
#include "Definitions.h"
#include <utility>
#include <string>
#include <vector>
class Organism;
class World;
using namespace std;

class GameFunctions {
public:
	void StartGame();
	void CreateGame();
	void CreateRandomGame();
	World* PrepareWorld(int wolfAmount, int sheepAmount, int foxAmount, int turtleAmount,int antelopeAmount, int worldSizeX, int worldSizeY);
	void StartSimulation(World* world);
};