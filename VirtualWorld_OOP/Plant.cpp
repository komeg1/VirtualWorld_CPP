#include "Plant.h"
#include "World.h"
Plant::Plant(World* world, char sign, int strength, COORDS coordinates):
Organism(world, sign, strength, PLANT_BASE_INITIATIVE,coordinates) {
}
Plant::Plant(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout) :
	Organism(world, sign, strength, initiative, coordinates, lifetime, breedingTimeout) {
}
void Plant::Action()
{
	if (SpreadProbability() && this->GetbreedingTimeout() == 0)
	{
		this->Spread();
		return;
	}
	if (this->GetbreedingTimeout() > 0)
		this->breedingTimeout--;
	
}

void Plant::Collision(Organism* other)
{
	if (this->GetStrength() == other->GetStrength())
	{
		if (this->GetlifeTime() > other->GetlifeTime())
		{
			Kill(other, 1);
			other->~Organism();

		}
		else
		{
			COORDS newCoordinates = this->GetCoordinates();
			Kill(other, 0);
			this->~Plant();
			other->SetCoordinates(newCoordinates);
		}
		return;

	}

	else if (this->GetStrength() > other->GetStrength())
	{

		Kill(other, 1);
		other->~Organism();
	}
	else if (this->GetStrength() < other->GetStrength())
	{
		COORDS newCoordinates = this->GetCoordinates();
		Kill(other, 0);
		this->~Plant();
		other->SetCoordinates(newCoordinates);
	}

	return;
}

void Plant::Kill(Organism * a, bool won)
{
		CREATURES temp;
		if (won)
		{
			this->world->CreateLog(this, a, EAT, world);
			temp = world->GetCreaturesArray();
			temp.erase(temp.begin() + a->GetIndex());
			world->SetCreaturesArray(temp);
			return;
		}
		else
		{
			this->world->CreateLog(a, this, EAT, world);
			temp = world->GetCreaturesArray();
			temp.erase(temp.begin() + this->GetIndex());
			world->SetCreaturesArray(temp);
			return;
		}


}


bool Plant::SpreadProbability()
{
	if (rand() % 100 < 2)
		return 1;
	return 0;
}

Plant::~Plant()
{
}
