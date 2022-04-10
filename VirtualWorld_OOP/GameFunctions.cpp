#include "GameFunctions.h"
#include "World.h"
#include <Windows.h>
#include "Wolf.h"
#include "Sheep.h"
#include <conio.h>
#define worldX 19
#define worldY 19
#define NAME  cout << "                                    Tomasz Krezymon, ETI, Informatyka, 189642\n"
using namespace std;
enum directions{
    NORTH =1,
    EAST,
    SOUTH,
    WEST
};
pair<int, int> RandomCoords(COORDS coords)
{
    int randomNum = (rand() % 4) + 1;
    bool av_dir[5];
    bool flag = 0;
    CheckDir(av_dir, coords);
    while (flag == 0)
    {
        if (randomNum == NORTH && av_dir[NORTH] && coords.second!=0)
        {
            coords.second--;
            flag = 1;
        }
        else if (randomNum == EAST && av_dir[EAST] && coords.first != worldY)
        {
            coords.first++;
            flag = 1;
        }
        else if (randomNum == SOUTH && av_dir[SOUTH] && coords.second != worldX)
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

void CheckDir(bool dir[],COORDS coords) {
    if (coords.first != 0)
        dir[WEST] = true;
    else
        dir[WEST] = false;

    if (coords.first != worldX)
        dir[EAST] = true;
    else
        dir[EAST] = false;

    if (coords.second != 0)
        dir[NORTH] = true;
    else
        dir[NORTH] = false;

    if (coords.first != worldY)
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
    cout << "Podaj liczbê wilków: ";
    cin >> wolfAmount;
    system("CLS");
    NAME;
    cout << "Podaj liczbê owiec: ";
    cin >> sheepAmount;
    StartSimulation(PrepareWorld(wolfAmount,sheepAmount));
}

World* PrepareWorld(int wolfAmount, int sheepAmount) {
    World* world = new World();
    for (int i = 0; i < wolfAmount; i++)
    {
        Wolf* x = new Wolf(rand() % 20 + 1, rand() % 19 + 1, world);
    }
    for (int i = 0; i < sheepAmount; i++)
    {
        Sheep* x = new Sheep(rand() % 20 + 1, rand() % 19 + 1, world);
    }
    return world;
}

void StartSimulation(World* world)
{
    int c = 0;
    world->draw(world->worldBoard);
    while (1)
    {

        world->nextTurn(world);

        while (1)
        {
            c = _getch();

            if (c == 72)
            {

                system("CLS");
                NAME;
                break;
            }
        }
    }
}


