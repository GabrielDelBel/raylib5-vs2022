
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
	int randNum;
	string taunts[3] = { "The ork utters a defaning roar","The ork slams their club again the ground", "The ork mocks the player" };

	
	void TauntPlayer()
	{
		randNum = (rand() % 3);
		cout << taunts[randNum] << endl;
	}
};

class Undead : public Enemy
{
public:
	string static species;
	int randNum;
	string taunts[3] = { "The zombie lazes around","The zombie disattaches their head and juggles it",
		"The zombie taunts the player" };

	 void TauntPlayer()
	{
		 randNum = (rand() % 3);
		 cout << taunts[randNum] << endl;
		 
	}
};



int main()
{
	int playerChoice;
	string playerClass;
	cout << "What Class do you want to be?" << endl;
	cout << "Please enter 1 for Wizard or 2 for Knight" << endl;
	do
	{
		cin >> playerChoice;
		if (playerChoice == 1)
		{
			cout << "You selected the Wizard Class." << endl;
			Wizard wizard;
			playerClass = "Wizard";
			cout << "What is your player's name?" << endl;
			cin >> wizard.name;
			wizard.health = 125;
			cout << "Here's a summary of what you've chosen so far." << endl;
			cout << "Class: " << playerClass << endl;
			cout << "Name: " << wizard.name << endl;
			cout << "Starting HP: " << wizard.health << endl;

		}
		else if (playerChoice == 2)
		{
			cout << "You selected the Knight Class." << endl;
			Knight knight;
			playerClass = "Knight";
			cout << "What is your player's name?" << endl;
			cout << "Here's a summary of what you've chosen so far." << endl;
			cout << "Class: " << playerClass << endl;
			cout << "Name: " << knight.name << endl;
			cout << "Starting HP: " << knight.health << endl;
			cin >> knight.name;
			knight.health = 200;
		}
		else
		{
			cout << "You inputted an invalid option. Please enter 1 for Wizard or 2 for Knight." << endl;
		}
	} while (playerChoice != 1 && playerChoice != 2);

	
	cout << "Would you like to watch a battle?" << endl;
	cout << "Please enter 1 for Yes or 2 for No" << endl;
	do
	{
		cin >> playerChoice;
		if (playerChoice == 1)
		{
			playerChoice = (rand() % 2) + 1;
			if (playerChoice == 1)
			{
				Ork ork;
				ork.species = "Ork";
				ork.health = 50;
				cout << "Name: " << ork.species << endl;
				cout << "Starting HP: " << ork.health << endl;

			}
			else 
			{
				Undead undead;
				undead.species = "Ork";
				undead.health = 35;
				cout << "Name: " << undead.species << endl;
				cout << "Starting HP: " << undead.health << endl;
				undead.NormalAttack();
			}
		}
		else if (playerChoice == 2)
		{
			
		}
		else
		{
			cout << "You inputted an invalid option. Please enter 1 for Yes or 2 for No." << endl;
		}
	} while (playerChoice != 1 && playerChoice != 2);



};



