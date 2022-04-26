#include "GameFunctions.h"
#include "World.h"
#include <Windows.h>
#include "Wolf.h"
#include "Fox.h"
#include "Organism.h"
#include "Sheep.h"
#include <conio.h>
#include "Human.h"
#include <sstream>
#include "Grass.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Borscht.h"
#include "Nightshade.h"
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
        break;
    case 2:
        CreateRandomGame();
        break;
    case 3:
        ReadGameFromFile();
    }


}
void GameFunctions::CreateRandomGame() {
    system("CLS");
    NAME;
    int worldSizeX = 0;
    int worldSizeY = 0;
    cout << "Podaj X i Y swiata";
    cin >> worldSizeX >> worldSizeY;
    StartSimulation(PrepareWorld(2,2,2,2,2, worldSizeX, worldSizeY));
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
    for (int i = 0; i < 2; i++)
    {
        do {
            x = rand() % worldSizeX;
            y = rand() % worldSizeY;

        } while (world->worldBoard[y][x] != FIELD);

        Borscht* wolf = new Borscht(x, y, world);
    }
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
  
    for (int i = 0; i < 5; i++)
    {
        do {
            x = rand() % worldSizeX;
            y = rand() % worldSizeY;

        } while (world->worldBoard[y][x] != FIELD);

        Grass* fox = new Grass(x, y, world);
    }
    for (int i = 0; i <2; i++)
    {
        do {
            x = rand() % worldSizeX;
            y = rand() % worldSizeY;

        } while (world->worldBoard[y][x] != FIELD);

        Dandelion* fox = new Dandelion(x, y, world);
    }
    for (int i = 0; i < 2; i++)
    {
        do {
            x = rand() % worldSizeX;
            y = rand() % worldSizeY;

        } while (world->worldBoard[y][x] != FIELD);

        Guarana* fox = new Guarana(x, y, world);
    }
     for (int i = 0; i < 2; i++)
    {
        do {
            x = rand() % worldSizeX;
            y = rand() % worldSizeY;

        } while (world->worldBoard[y][x] != FIELD);

        Nightshade* fox = new Nightshade(x, y, world);
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

void GameFunctions::SaveToFile(World* world)
{
    ofstream SAVE("SAVE.TXT");
    SAVE << world->GetWorldX() <<" "<< world->GetWorldY()<<" "<< world->GetTurn()<<"\n";
    for (int i = 0; i < world->GetCreaturesArray().size(); i++)
    {
        Organism* a = world->GetCreaturesArray()[i];
        SAVE << a->GetSign() << " "
            << a->GetStrength() << " "
            << a->GetInitiative() <<" "
            << a->GetCoordinates().first << " "
            << a->GetCoordinates().second << " "
            << a->GetlifeTime() << " "
            << a->GetbreedingTimeout() << " ";
        if (a->GetSign() == HUMAN)
            SAVE << a->GetSkillIsActive() << " "
            << a->GetSkillTimeout() << " "
            << a->GetSkillTurnLeft();
        SAVE << "\n";


        
    }
    SAVE.close();
   
}

void GameFunctions::ReadGameFromFile()
{
    ifstream READ("SAVE.TXT");
    if (READ.is_open())
    {
        char sign;
        int x, y, strength, initiative, lifetime, breedingTimeout, skillTimeout, skillTurnLeft,turn;
        bool skillIsActive;
        READ >> x >> y >> turn;
        World* world = new World(x, y, turn);
        while (READ >> sign >> strength >> initiative >> x >> y >> lifetime >> breedingTimeout)
        {
            if(sign == '#')
                Borscht* plant = new Borscht(world, sign, strength, initiative, make_pair(x, y), lifetime, breedingTimeout);
            if (sign == '!')
                Nightshade* plant = new Nightshade(world, sign, strength, initiative, make_pair(x, y), lifetime, breedingTimeout);
            if (sign == '~')
                Grass* plant = new Grass(world, sign, strength, initiative, make_pair(x, y), lifetime, breedingTimeout);
            if (sign == '$')
                Guarana* plant = new Guarana(world, sign, strength, initiative, make_pair(x, y), lifetime, breedingTimeout);
            if (sign == '&')
                Dandelion* plant = new Dandelion(world, sign, strength, initiative, make_pair(x, y), lifetime, breedingTimeout);
            if (sign == 'W')
                Wolf* wolf = new Wolf(world, sign, strength, initiative, make_pair(x, y), lifetime, breedingTimeout);
            if (sign == 'A')
                Antelope* wolf = new Antelope(world, sign, strength, initiative, make_pair(x, y), lifetime, breedingTimeout);
            if (sign == 'F')
                Fox* wolf = new Fox(world, sign, strength, initiative, make_pair(x, y), lifetime, breedingTimeout);
            if (sign == 'T')
                Turtle* wolf = new Turtle(world, sign, strength, initiative, make_pair(x, y), lifetime, breedingTimeout);
            if (sign == 'W')
                Turtle* wolf = new Turtle(world, sign, strength, initiative, make_pair(x, y), lifetime, breedingTimeout);
            if (sign == 'H')
            {
                READ >> skillIsActive >> skillTimeout >> skillTurnLeft;
                Human* wolf = new Human(world, sign, strength, initiative, make_pair(x, y), lifetime, breedingTimeout,skillIsActive,skillTimeout,skillTurnLeft);
            }
        }
        StartSimulation(world);
    }
    else
    {
        system("CLS");
        NAME;
        cout << "Nie odnaleziono zapisanej gry";
        Sleep(1000);
        system("CLS");
        StartGame();
    }
    READ.close();
}










