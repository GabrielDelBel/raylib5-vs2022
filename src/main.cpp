//#include "raylib.h"
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

class GameObject
{
public:
	virtual void NormalAttack() = 0;
	
	
};

class Player : public GameObject
{
public:
	int playerChoice;
	string playerClass;
	string name;
	int health;

	void NormalAttack()
	{

	}

	virtual void SpecialAttack() = 0;
};

class Enemy : public GameObject
{
public:
	int health;

	void NormalAttack()
	{

	}

	virtual void TauntPlayer() = 0;
	
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
	Player *player;
	Enemy enemy;
	cout << "What Class do you want to be?" << endl;
	cout << "Please enter 1 for Wizard or 2 for Knight" << endl;
	do
	{
		cin >> player.playerChoice;
		if (player.playerChoice == 1)
		{
			cout << "You selected the Wizard Class." << endl;
			Wizard wizard;
			player.playerClass = "Wizard";
			player.health = 125;
		}
		else if (player.playerChoice == 2)
		{
			cout << "You selected the Knight Class." << endl;
			Knight knight;
			player.playerClass = "Knight";
			player.health = 200;
		}
		else
		{
			cout << "You inputted an invalid option. Please enter 1 for Wizard or 2 for Knight." << endl;
		}
	} while (player.playerChoice != 1 && player.playerChoice != 2);

	cout << "What is your player's name?" << endl;
	cin >> player.name;

	cout << "Here's a summary of what you've chosen so far." << endl;
	cout << "Class: " << player.playerClass << endl;
	cout << "Name: " << player.name << endl;
	cout << "Starting HP: " << player.name << endl;
	
	cout << "Would you like to watch a battle?" << endl;
	cout << "Please enter 1 for Yes or 2 for No" << endl;
	do
	{
		cin >> player.playerChoice;
		if (player.playerChoice == 1)
		{
			player.playerChoice = (rand() % 2) + 1;
			if (player.playerChoice == 1)
			{
				Ork ork;
			}
			else 
			{
				Undead undead;
			}
		}
		else if (player.playerChoice == 2)
		{
			
		}
		else
		{
			cout << "You inputted an invalid option. Please enter 1 for Yes or 2 for No." << endl;
		}
	} while (player.playerChoice != 1 && player.playerChoice != 2);



};



