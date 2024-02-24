//#include "raylib.h"
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

class GameObject
{
public:

	void NormalAttack()
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

	virtual void SpecialAttack()
	{

	}
};

class Wizard : public Player
{
public:
	string static specialAttackName;
	int specialAttackAmount;
};

class Knight : public Player
{
public:
	string static specialAttackName;
	int specialAttackAmount;
};

class Ork : public Enemy
{
public:
	string static species;
	int* numTaunts;
};

class Undead : public Enemy
{
public:
	string static species;
	int* numTaunts;
};

