//#include "raylib.h"
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

class GameObject
{
public:

	virtual void NormalAttack()
	{

	}
};

class Player : public GameObject
{
public:
	string name;
	int health;

	void NormalAttack()
	{

	}

	virtual void SpecialAttack()
	{

	}
};

class Enemy : public GameObject
{
public:
	int health;

	void NormalAttack()
	{

	}

	virtual void TauntPlayer()
	{

	}
};

class Wizard : public Player
{
public:
	string static specialAttackName;
	int specialAttackAmount;
	
	void SpecialAttack()
	{

	}
};

class Knight : public Player
{
public:
	string static specialAttackName;
	int specialAttackAmount;

	void SpecialAttack()
	{

	}
};

class Ork : public Enemy
{
public:
	string static species;
	int* numTaunts;

	void TauntPlayer()
	{

	}
};

class Undead : public Enemy
{
public:
	string static species;
	int* numTaunts;

	 void TauntPlayer()
	{

	}
};

