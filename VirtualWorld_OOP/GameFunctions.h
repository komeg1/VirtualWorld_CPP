#pragma once
#include <iostream>
#include <utility>
class Organism;
#define COORDS pair<int,int>
class World;
using namespace std;
pair <int, int> RandomCoords(COORDS coords);

void CheckDir(bool dir[], COORDS coords);

bool comparator(const Organism* a, const Organism* b);

void StartGame();
void CreateGame();
World* PrepareWorld(int wolfAmount, int sheepAmount);
void StartSimulation(World* world);