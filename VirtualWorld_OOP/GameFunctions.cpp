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
        else if (randomNum == SOUTH && av_dir[SOUTH] && coords.second!= world->GetWorldX()-1)
        {
            coords.second++;
            flag = 1;
        }
        else  if (randomNum == WEST && av_dir[WEST] && coords.first!=0)
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

vector <COORDS> CheckSurrounding(World* world, COORDS coords, char thisAnimal){
    int x1 = coords.first - 1,
        x2 = coords.first+ 1,
        y1 = coords.second- 1,
        y2 = coords.second+ 1;
    vector<COORDS> availableSurrounding;
    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 == world->GetWorldX())
        x2--;
    if (y2 == world->GetWorldY())
        y2--;

    cout << endl;
    for (int i = y1; i <= y2; i++)
    {
        for (int j = x1; j <= x2; j++)
            cout << world->worldBoard[i][j];
        cout << endl;
    }
    Sleep(1);

    for(int i=y1;i<=y2;i++)
        for (int j = x1; j <= x2; j++)
        {
            if (world->worldBoard[i][j] == thisAnimal && make_pair(j, i) == coords)
                continue;
            else if (world->worldBoard[i][j] != FIELD)
            {
                if (IsStronger(coords, make_pair(j, i), world))
                    availableSurrounding.push_back(make_pair(j,i));
            }
            else
                availableSurrounding.push_back(make_pair(j, i));
        }
    
    for (int i = 0; i < availableSurrounding.size(); i++)
        cout << availableSurrounding[i].first << availableSurrounding[i].second << endl;
    Sleep(1);
    return availableSurrounding;
}

bool IsStronger(COORDS a, COORDS b,World*world)
{
    int strengthA=0;
    int strengthB=0;
    
    for (int i = 0; i < world->GetCreaturesArray().size(); i++)
    {
        if (world->GetCreaturesArray()[i]->GetCoordinates() == a)
            strengthA = world->GetCreaturesArray()[i]->GetStrength();
        if(world->GetCreaturesArray()[i]->GetCoordinates() == b)
            strengthB = world->GetCreaturesArray()[i]->GetStrength();
    }

    return strengthA > strengthB;
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
    int x=-1, y=-1;
    for (int i = 0; i < wolfAmount; i++)
    {
        do {
            x = rand() % worldSizeX;
            y = rand() % worldSizeY;

        } while (world->worldBoard[y][x]!=FIELD);
        
        Wolf* wolf = new Wolf(x , y , world);
    }
    for (int i = 0; i < sheepAmount; i++)
    {
        do {
            x = rand() % worldSizeX;
            y = rand() % worldSizeY;

        } while (world->worldBoard[y][x] != FIELD);
        Sheep* sheep = new Sheep(x , y , world);
    }
    for (int i = 0; i < foxAmount; i++)
    {
        do {
            x = rand() % worldSizeX;
            y = rand() % worldSizeY;

        } while (world->worldBoard[y][x] != FIELD);
        
        Fox* fox = new Fox(x , y , world);
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
        tmpmsg << "-ZABOJSTWO: '" << ac << "' zabil '" << bc <<
            "' na polu x: " << STR(b->GetCoordinates().second) << " y: " + STR(b->GetCoordinates().first);
        finalmsg = tmpmsg.str();
        break;
    }
  
    vector<string> tempLog = world->GetLogs();
    tempLog.push_back(finalmsg);
    world->SetLogs(tempLog);
}

void PrintLogs(World* world)
{
    vector<string> logs = world->GetLogs();
    cout << "========================ZDARZENIA================================\n";
    if (logs.size() < 6) {
        for (string log : logs)
            cout << log << "\n";
    }
    else
        for (int i = logs.size() - 6; i < logs.size(); i++)
            cout << logs[i] << "\n";
    cout << "=================================================================";
    cout << "\nILOSC ZWIERZAT:" << world->GetCreaturesArray().size();
    

}




