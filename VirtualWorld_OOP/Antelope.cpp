#include "Antelope.h"
#include "World.h"
Antelope::Antelope(int x, int y, World* world) : Animal(world, 'A', 4, 4, 0, make_pair(x, y), 0) {
	world->worldBoard[y][x] = sign;
	CREATURES temp = world->GetCreaturesArray();
	temp.push_back(this);
	world->SetCreaturesArray(temp);
}

void Antelope::collision(Organism* attackingOrganism)
{
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
			this->~Antelope();
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
			world->CreateLog(this, attackingOrganism, RUN, world);

			return;
		}
		else
		{
			COORDS newCoordinates = this->GetCoordinates();
			Kill(attackingOrganism	, 0);
			this->~Antelope();
			attackingOrganism->SetCoordinates(newCoordinates);
		}
	}

	return;
}

bool Antelope::breeding(World* world, Organism* other)
{
	if (this->GetBreedingTimeout() == 0 && other->GetBreedingTimeout() == 0)
	{
		vector<COORDS> area = PrepareArea(other);
		COORDS newCreatureCoords = RandomCoords(area, world);
		if (newCreatureCoords != make_pair(-1, -1))
		{
			Antelope* child = new Antelope(newCreatureCoords.first, newCreatureCoords.second, world);
			child->SetBreedingTimeout();
			this->SetBreedingTimeout();
			other->SetBreedingTimeout();
			return 1;
		}
	}
	return 0;
}

bool Antelope::IsBlocked(Organism* other)
{
	int val = rand() % 100 + 1;
	if (val <= 50)
		return 1;
	return 0;
}

vector<COORDS> Antelope::CheckSurrounding(World* world, COORDS coords, int action)
{
	int x1 = coords.first - 2,
		x2 = coords.first + 2,
		y1 = coords.second - 2,
		y2 = coords.second + 2;
	vector<COORDS> availableSurrounding;
	if (x1 < 0)
		x1 = 0;
	if (y1 < 0)
		y1 = 0;
	if (x2 >= world->GetWorldX())
		x2=world->GetWorldX()-1;
	if (y2 >= world->GetWorldY())
		y2 = world->GetWorldY() - 1;

	for (int i = y1; i <= y2; i++)
		for (int j = x1; j <= x2; j++)
		{
			if (world->worldBoard[i][j] == this->GetSign() && make_pair(j, i) == coords)
				continue;
			else if (world->worldBoard[i][j] == FIELD)
				availableSurrounding.push_back(make_pair(j, i));
			else {
				if (action != 1)
					availableSurrounding.push_back(make_pair(j, i));
			}
		}


	return availableSurrounding;
}

Antelope::~Antelope()
{
}



