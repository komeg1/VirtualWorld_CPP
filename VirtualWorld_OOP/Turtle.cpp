#include "Turtle.h"
#include "World.h"

Turtle::Turtle(int x, int y, World* world) : Animal(world, 'T', 2, 1, 0, make_pair(x, y), 0)
{
	world->worldBoard[y][x] = sign;
	CREATURES temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
}
void Turtle::action(World* world)
{
	COORDS currentCoords = GetCoordinates();
	COORDS newCoords = RandomCoords(CheckSurrounding(world, currentCoords, 0), world);
	if(GenerateProbability())
	{
		if (CheckIfOrganism(newCoords, world))
		{
			Organism* other = FindOrganism(newCoords, world);
			other->collision(this);

		}
		else
		{
			this->SetCoordinates(newCoords);
			this->UpdateLifeTime();
		}
		if (this->GetBreedingTimeout() > 0)
			this->breedingTimeout--;

	}

}
void Turtle::collision(Organism* attackingOrganism) {
	if (this->GetSign() == attackingOrganism->GetSign())
	{
		if (breeding(world, this))
			world->CreateLog(this, this, BREED, world);
		else
			world->CreateLog(this, this, BREEDTIME, world);
		return;
	}

	if (this->GetStrength() == attackingOrganism->GetStrength())
	{
		if (this->GetlifeTime() > attackingOrganism->GetlifeTime())
		{
			Kill(attackingOrganism, 1);
			attackingOrganism->~Organism();

		}
		else
		{
			COORDS newCoordinates = this->GetCoordinates();
			Kill(attackingOrganism, 0);
			this->~Turtle();
			attackingOrganism->SetCoordinates(newCoordinates);
		}
		return;

	}

	else if (this->GetStrength() > attackingOrganism->GetStrength())
	{

		Kill(attackingOrganism, 1);
		attackingOrganism->~Organism();
	}
	else if (this->GetStrength() < attackingOrganism->GetStrength())
	{
		if (IsBlocked(attackingOrganism))
		{
			world->CreateLog(this, attackingOrganism, BLOCK, world);
			return;
		}
		else
		{
			COORDS newCoordinates = this->GetCoordinates();
			Kill(attackingOrganism, 0);
			this->~Turtle();
			attackingOrganism->SetCoordinates(newCoordinates);
		}
	}

	return;
}

bool Turtle::GenerateProbability()
{
	int val = rand() % 100 + 1;
	if (val <= 25)
		return 1;
	return 0;
}

bool Turtle::IsBlocked(Organism* other)
{
	cout << "JESTEM " << other->GetStrength();
	if (other->GetStrength() < 5)
		return 1;
	return 0;
}

bool Turtle::breeding(World* world, Organism* other)
{
	if (this->GetBreedingTimeout() == 0 && other->GetBreedingTimeout() == 0)
	{
		vector<COORDS> area = PrepareArea(other);
		COORDS newCreatureCoords = RandomCoords(area, world);
		if (newCreatureCoords != make_pair(-1, -1))
		{
			Turtle* child = new Turtle(newCreatureCoords.first, newCreatureCoords.second, world);
			child->SetBreedingTimeout();
			this->SetBreedingTimeout();
			other->SetBreedingTimeout();
			return 1;
		}
	}
	return 0;
}

Turtle::~Turtle() {

}