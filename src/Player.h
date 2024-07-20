#pragma once
#include <string>
#include <list>

class Player
{
public:
	std::string name;
	int health;
	int attack;
	bool isInventoryOpen;
	std::string typeCharacter;
	std::list<std::string> inventory;

	int NormalAttack();

	virtual void SetInitialHPAttackandClass() = 0;

	virtual int SpecialAttack() = 0;

	virtual void SetHP(int changeHealth) = 0;

	virtual void SetAttack(int changeAttack) = 0;
};

