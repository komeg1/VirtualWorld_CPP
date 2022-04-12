#pragma once
#define STR to_string
#define FIELD '.'
#define NAME  cout << "                                    Tomasz Krezymon, ETI, Informatyka, 189642\n"
#define COORDS pair<int,int>
#define CREATURES vector<Organism*>
enum Logs {
	KILL=1

};

enum directions {
    NORTH = 1,
    EAST,
    SOUTH,
    WEST
};