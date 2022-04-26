#include "Human.h"
#include "World.h"
#include <Windows.h>
#include <conio.h>
Human::Human(int x, int y, World* world) : Animal(world, 'H', 5, 4, make_pair(x, y)) {
	AddToWorld(this);
}
Human::Human(World* world, char sign, int strength, int initative, COORDS coordinates, int lifetime, int breedingTimeout, bool skillIsActive, int skillTimeout, int skillTurnLeft) :
	Animal(world, sign, strength, initiative, coordinates, lifetime, breedingTimeout), skillIsActive(skillIsActive), skillTimeout(skillTimeout), skillTurnLeft(skillTurnLeft) {
	AddToWorld(this);
}
void Human::UpdateCoords(COORDS* newCoords,int skill,int key)
{

	if (key == KEY_UP)
		newCoords->second-=skill;
	if (key == KEY_LEFT)
		newCoords->first-=skill;
	if (key == KEY_RIGHT)
		newCoords->first+=skill;
	if (key == KEY_DOWN)
		newCoords->second+=skill;

	if (newCoords->first < 0)
	{
		newCoords->first = 0;
		return;
	}
	if (newCoords->first == world->GetWorldX())
	{
		newCoords->first--;
		return;
	}
	if (newCoords->second < 0)
	{
		newCoords->second = 0;
		return;
	}
	if (newCoords->second == world->GetWorldY())
	{
		newCoords->second--;
		return;
	}
}

void Human::ActivateSkill() {
	if (this->GetSkillIsActive() == 1)
	{
		if(this->GetSkillTurnLeft()>0)
		cout << "UMIEJETNOSC JEST JUZ AKTYWNA, POZOSTALO " << this->GetSkillTurnLeft() << "\n";
	}
	if (this->GetSkillIsActive() == 0)
	{
		if (this->GetSkillTimeout() > 0)
			cout << "CZLOWIEK MUSI ODPOCZAC JESZCZE " << this->GetSkillTimeout() << " TURY" << endl;
		else
		{
			this->SetSkillIsActive();
			this->SetSkillTimeout(SKILL_TURN_AMNT);
			this->SetSkillTurnLeft(SKILL_TURN_AMNT);
			this->world->PrintConsole();
		}
	}

}
void Human::Action() {
	COORDS currentCoords = GetCoordinates();
	COORDS newCoords = currentCoords;
	int key = 0;
	char action;


	while (key == 0)
	{	
		world->PrintConsole();
		cout << "\nPodaj ruch czlowieka:";
		
		key = _getch();
		if (key == KEY_SKILL)
		{
			ActivateSkill();
			key = _getch();
		}
		else if (key == SAVE_GAME)
		{
			GameFunctions temp;
			temp.SaveToFile(this->world);
			key = _getch();

		}
		key = _getch();
		system("CLS");
		if (key != KEY_UP && key != KEY_LEFT && key != KEY_RIGHT && key != KEY_DOWN)
			key = 0;
	}

		if(GetSkillIsActive()==1&&rand()%100+1<=50)
			UpdateCoords(&newCoords,2,key);
		else
			UpdateCoords(&newCoords, 1, key);
	



	CREATURES creaturesVec = world->GetCreaturesArray();
	char nextField = world->worldBoard[newCoords.second][newCoords.first];
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
	UpdateSkillStatus();
}

void Human::UpdateSkillStatus() {
	if (this->skillIsActive)
	{
		this->skillTurnLeft--;
		if (this->skillTurnLeft == 0)
		{
			this->skillIsActive = 0;
			this->skillTimeout = SKILL_TURN_AMNT;
		}
	}
	else if (this->skillIsActive == 0)
		if (this->skillTimeout > 0)
			this->skillTimeout--;
}

bool Human::Breeding(Organism* other)
{
	if(other->GetSign()==this->GetSign())
	return 1;
	return 0;
}

void Human::CreateChild(COORDS newCoords, Organism* other)
{
	return;
}

bool Human::GetSkillIsActive()const
{
	return skillIsActive;
}

int Human::GetSkillTurnLeft()const
{
	return skillTurnLeft;
}

int Human::GetSkillTimeout()const
{
	return skillTimeout;
}

void Human::SetSkillIsActive()
{
	skillIsActive=~skillIsActive;
}

void Human::SetSkillTurnLeft(int turns)
{
	skillTurnLeft = turns;
}

void Human::SetSkillTimeout(int turns)
{
	skillTimeout = turns;
}

Human::~Human(){
	system("CLS");
	NAME;
	char action;
	cout << "CZLOWIEK ZOSTAL ZABITY, CZY CHCESZ KONTYNUOWAC OGLADANIE ROZGRYWKI? [Y/N]: ";
	cin >> action;
	if (action == 'Y')
		this->world->NextTurn();
	else
		exit(0);
}


