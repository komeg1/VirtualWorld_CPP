#pragma once
#include "Animal.h"
class Human : public Animal
{
private:
	bool skillIsActive = 0;
	int skillTurnLeft = 0;
	int skillTimeout = 0;
public:
	Human(int x, int y, World* world);
	void Action()override;
	bool Breeding(Organism* other)override;
	void UpdateCoords(COORDS* newCoords,int skill,int key);
	void CreateChild(COORDS newCoords, Organism* other)override;
	bool GetSkillIsActive()const;
	int GetSkillTurnLeft()const;
	int GetSkillTimeout()const;
	void SetSkillIsActive();
	void SetSkillTurnLeft(int turns);
	void SetSkillTimeout(int turns);
	void ActivateSkill();
	void UpdateSkillStatus();
	~Human()override;

};

