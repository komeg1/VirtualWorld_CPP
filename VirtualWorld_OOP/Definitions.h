#pragma once
#define STR to_string
#define FIELD '.'
#define NAME  cout << "                                    Tomasz Krezymon, ETI, Informatyka, 189642\n"
#define COORDS pair<int,int>
#define CREATURES vector<Organism*>
#define BREEDING_CNTDOWN 10
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
enum Logs {
	KILL=1,
    BREED,
    BREEDTIME,
    BLOCK,
    RUN,
    EAT,
    BOOST

};

enum directions {
    NORTH = 1,
    EAST,
    SOUTH,
    WEST
};
