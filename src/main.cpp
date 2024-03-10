//#include "raylib.h"
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

class GameObject
{
public:
	int playerChoice;
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
	string species;
	int& randNum;
	string taunts[3] = { "The ork utters a defaning roar","The ork slams their club again the ground", "The ork mocks the player" };

	
	void TauntPlayer()
	{
		species = "Ork";
		randNum++;
		if (randNum > 2)
		{
			randNum = 0;
		}
		cout << taunts[randNum] << endl;
	}
};

class Undead : public Enemy
{
public:
	string static species;
	int& randNum;
	string taunts[3] = { "The zombie lazes around","The zombie disattaches their head and juggles it",
		"The zombie taunts the player" };

	 void TauntPlayer()
	{
		 species = "Zombie";
		 randNum++;
		 if (randNum > 2)
		 {
			 randNum = 0;
		 }
		 cout << taunts[randNum] << endl;
	}
};

int main()
{
	Player player;
	Enemy enemy;
	Knight knight;
	Wizard wizard;
	Undead undead;
	Ork ork;
	cout << "What Species do you want to be?" << endl;
	cout << "Please endter 1 for Wizard and 2 for Knight" << endl;
	cin >> player.name;
	cout << "What is your player's name?" << endl;
	cin >> player.name;
	




};



