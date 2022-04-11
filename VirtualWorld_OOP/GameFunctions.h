#pragma once
#include <iostream>
#include "Definitions.h"
#include <utility>
#include <string>

class Organism;
#define COORDS pair<int,int>
class World;
using namespace std;
pair <int, int> RandomCoords(COORDS coords, World* world);

void CheckDir(bool dir[], COORDS coords, World* world);

bool comparator(const Organism* a, const Organism* b);

void StartGame();
void CreateGame();
World* PrepareWorld(int wolfAmount, int sheepAmount,int foxAmount,int worldSizeX,int worldSizeY);
void StartSimulation(World* world);
void CreateLog(Organism*a,Organism*b,int log_type,World* world);