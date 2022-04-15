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
#include "Turtle.h"
#include "Antelope.h"
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
    int turtleAmount = 0;
    int antelopeAmount = 0;
    int worldSizeX=0;
    int worldSizeY=0;
    cout << "Podaj X i Y swiata";
    cin >> worldSizeX>>worldSizeY;
    system("CLS");
    NAME;
    cout << "Podaj liczbê wilkow: ";
    cin >> wolfAmount;
    system("CLS");
    NAME;
    cout << "Podaj liczbê owiec: ";
    cin >> sheepAmount;
    system("CLS");
    NAME;
    cout << "Podaj liczbê lisow: ";
    cin >> foxAmount;
    system("CLS");
    NAME;
    cout << "Podaj liczbê zolwi: ";
    cin >> turtleAmount;
    system("CLS");
    NAME;
    cout << "Podaj liczbê antylop: ";
    cin >> antelopeAmount;
    StartSimulation(PrepareWorld(wolfAmount,sheepAmount,foxAmount,turtleAmount,antelopeAmount,worldSizeX,worldSizeY));
}

World* GameFunctions::PrepareWorld(int wolfAmount, int sheepAmount, int foxAmount,int turtleAmount,int antelopeAmount,int worldSizeX, int worldSizeY) {
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
    for (int i = 0; i < turtleAmount; i++)
    {
        do {
            x = rand() % worldSizeX;
            y = rand() % worldSizeY;

        } while (world->worldBoard[y][x] != FIELD);

        Turtle* fox = new Turtle(x, y, world);
    }
    for (int i = 0; i < antelopeAmount; i++)
    {
        do {
            x = rand() % worldSizeX;
            y = rand() % worldSizeY;

        } while (world->worldBoard[y][x] != FIELD);

        Antelope* fox = new Antelope(x, y, world);
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
    world->PrintConsole();
    Sleep(1500);
    system("CLS");
    while (1)
    {
        world->NextTurn();
    }
}










