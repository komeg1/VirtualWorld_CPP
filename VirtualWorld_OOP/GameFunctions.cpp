#include "GameFunctions.h"
#include "World.h"
#include <Windows.h>
#include "Wolf.h"
#include "Fox.h"
#include "Sheep.h"
#include <conio.h>
#include "Human.h"
#include <sstream>
#include "Grass.h"
using namespace std;


void GameFunctions::StartGame()
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

void GameFunctions::CreateGame() {
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

World* GameFunctions::PrepareWorld(int wolfAmount, int sheepAmount, int foxAmount,int worldSizeX, int worldSizeY) {
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
    for (int i = 0; i < 5; i++)
    {
        do {
            x = rand() % worldSizeX;
            y = rand() % worldSizeY;

        } while (world->worldBoard[y][x] != FIELD);

        Grass* fox = new Grass(x, y, world);
    }
    do {
        x = rand() % worldSizeX;
        y = rand() % worldSizeY;

    } while (world->worldBoard[y][x] != FIELD);
    Human* human = new Human(x, y, world);
    return world;
}

void GameFunctions::StartSimulation(World* world)
{
    int c = 0;
    system("CLS");
    NAME;
    world->UpdateBoard();
    while (1)
    {
        world->NextTurn();
    }
}










