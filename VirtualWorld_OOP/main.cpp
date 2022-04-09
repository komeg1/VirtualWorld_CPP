#include "World.h"
#include "Animal.h"
#include "Organism.h"
#include "Wolf.h"
#include <cstdlib>
#include <Windows.h>
int main() {
	srand(time(NULL));
	World* world = new World();
	Wolf* test = new Wolf(0,0,world);
	Wolf* test2 = new Wolf(5, 5, world);

	while (true)
	{
		world->nextTurn(world, world->GetCreaturesArray());
		Sleep(10);
		system("CLS");
	}
	
}