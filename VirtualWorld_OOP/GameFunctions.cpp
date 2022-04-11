#include "GameFunctions.h"
#include "World.h"
#include <Windows.h>
#include "Wolf.h"
#include "Fox.h"
#include "Sheep.h"
#include <conio.h>
#include <sstream>
using namespace std;

COORDS RandomCoords(COORDS coords, World* world)
{
    int randomNum = (rand() % 4) + 1;
    bool av_dir[5];
    bool flag = 0;
    CheckDir(av_dir, coords, world);
    while (flag == 0)
    {
        if (randomNum == NORTH && av_dir[NORTH] && coords.second!=0)
        {
            coords.second--;
            flag = 1;
        }
        else if (randomNum == EAST && av_dir[EAST] && coords.first != world->GetWorldY()-1)
        {
            coords.first++;
            flag = 1;
        }
        else if (randomNum == SOUTH && av_dir[SOUTH] && coords.second != world->GetWorldX()-1)
        {
            coords.second++;
            flag = 1;
        }
        else  if (randomNum == WEST && av_dir[WEST] && coords.first !=0)
        {
            coords.first--;
            flag = 1;
        }

        randomNum = (rand() % 4) + 1;
    }


    return coords;
}

void CheckDir(bool dir[],COORDS coords, World* world) {
    if (coords.first != 0)
        dir[WEST] = true;
    else
        dir[WEST] = false;

    if (coords.first != world->GetWorldX())
        dir[EAST] = true;
    else
        dir[EAST] = false;

    if (coords.second != 0)
        dir[NORTH] = true;
    else
        dir[NORTH] = false;

    if (coords.first != world->GetWorldY())
        dir[SOUTH] = true;
    else
        dir[SOUTH] = false;
}

bool comparator(const Organism* a, const Organism* b)
{
    if (a->GetInitiative() == b->GetInitiative())
        return a->GetlifeTime() > b->GetlifeTime();
    return a->GetInitiative() > b->GetInitiative();
}

void StartGame()
{
    int n;
    cout <<"                                    Tomasz Krezymon, ETI, Informatyka, 189642\n                                           Projekt Wirtualnego Swiata";
    cout << "\n\n                               1. Podaj ilosc zwierzat i roslin";
    cout << "\n                               Podaj opcjê: ";
    cin >> n;
    switch (n) {
    case 1:
        CreateGame();
    }
                                               

}

void CreateGame() {
    system("CLS");
    NAME;
    
    int wolfAmount = 0;
    int sheepAmount = 0;
    int foxAmount = 0;
    int worldSizeX=0;
    int worldSizeY=0;
    cout << "Podaj X i Y swiata";
    cin >> worldSizeX>>worldSizeY;
    system("CLS");
    NAME;
    cout << "Podaj liczbê wilków: ";
    cin >> wolfAmount;
    system("CLS");
    NAME;
    cout << "Podaj liczbê owiec: ";
    cin >> sheepAmount;
    system("CLS");
    NAME;
    cout << "Podaj liczbê lisów: ";
    cin >> foxAmount;
    StartSimulation(PrepareWorld(wolfAmount,sheepAmount,foxAmount,worldSizeX,worldSizeY));
}

World* PrepareWorld(int wolfAmount, int sheepAmount, int foxAmount,int worldSizeX, int worldSizeY) {
    World* world = new World(worldSizeX,worldSizeY);
    for (int i = 0; i < wolfAmount; i++)
    {
        Wolf* x = new Wolf(rand() % worldSizeX , rand() % worldSizeY , world);
    }
    for (int i = 0; i < sheepAmount; i++)
    {
        Sheep* x = new Sheep(rand() % worldSizeX , rand() % worldSizeY , world);
    }
    for (int i = 0; i < foxAmount; i++)
    {
        Fox* x = new Fox(rand() % worldSizeX , rand() % worldSizeY , world);
    }
    return world;
}

void StartSimulation(World* world)
{
    int c = 0;
    system("CLS");
    NAME;
    world->draw();
    while (1)
    {
        world->nextTurn();
    }
}


void CreateLog(Organism* a, Organism* b, int log_type, World* world)
{
    ostringstream tmpmsg;
    string finalmsg;
    char ac = a->GetSign();
    char bc = b->GetSign();
    switch (log_type)
    {
    case KILL:
        tmpmsg << "ZABOJSTWO: '" << ac << "' zabil '" << bc <<
            "' na polu x: " << STR(b->GetCoordinates().second) << " y: " + STR(b->GetCoordinates().first);
        finalmsg = tmpmsg.str();
        break;
    }
  
    vector<string> tempLog = world->GetLogs();
    tempLog.push_back(finalmsg);
    world->SetLogs(tempLog);
}


