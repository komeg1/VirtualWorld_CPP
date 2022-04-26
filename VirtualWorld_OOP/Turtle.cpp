#include "Turtle.h"
#include "World.h"

Turtle::Turtle(int x, int y, World* world) : Animal(world, 'T', 2, 1, make_pair(x, y))
{
	AddToWorld(this);
}
void Turtle::Action()
{
	COORDS currentCoords = GetCoordinates();
	COORDS newCoords = RandomCoords(CheckSurrounding(currentCoords, 0));
	if(GenerateProbability())
	{
		if (CheckIfOrganism(newCoords))
		{
			Organism* other = FindOrganism(newCoords);
			other->Collision(this);

		}
		else
		{
			this->SetCoordinates(newCoords);
			this->UpdateLifeTime();
		}
		if (this->GetBreedingTimeout() > 0)
			this->BreedingTimeout--;

	}

}
void Turtle::Collision(Organism* attackingOrganism) {
	if (this->GetSign() == attackingOrganism->GetSign())
	{
		if (Breeding(this))
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

void Turtle::CreateChild(COORDS newCreatureCoords, Organism* other) {
	Turtle* child = new Turtle(newCreatureCoords.first, newCreatureCoords.second, world);
	this->SetBreedingTimeout();
	other->SetBreedingTimeout();
	child->SetBreedingTimeout();
}

Turtle::~Turtle() {

}