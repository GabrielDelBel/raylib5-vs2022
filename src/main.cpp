
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

class GameObject
{
public:
	virtual int NormalAttack() = 0;
	
	
};

class Player : public GameObject
{
public:
	string name;
	int health;

	int NormalAttack()
	{
		int randNum;
		randNum = (rand() % 15) + 50;
		cout << " dealt " << randNum << " damage to the ";
		return randNum;
	}

	virtual int SpecialAttack() = 0;
};

class Enemy : public GameObject
{
public:
	int health;

	int NormalAttack()
	{
		int randNum;
		randNum = (rand() % 35) + 25;
		cout << " dealt " << randNum << " damage to ";
		return randNum;
		
	}

	virtual void TauntPlayer() = 0;
	
};

class Wizard : public Player
{
public:
	static string specialAttackName;
	int specialAttackAmount;
	
	int SpecialAttack()
	{
		specialAttackAmount = (rand() % 25) + 150;
		cout << " dealt " << specialAttackAmount << " damage to the ";
		return specialAttackAmount;
	}
};

string Wizard::specialAttackName = "Meteor Strike.";

class Knight : public Player
{
public:
	static string specialAttackName;
	int specialAttackAmount;

	int SpecialAttack()
	{
		specialAttackAmount = (rand() % 35) + 115;
		cout << " dealt " << specialAttackAmount << " damage to the ";
		return specialAttackAmount;
	}
};

string Knight::specialAttackName = "Piercing Blade.";

class Ork : public Enemy
{
public:
	static string species;
	string taunts[3] = { "The Ork utters a defaning roar.","The Ork slams their club again the ground.", "The Ork mocks the player." };

	
	void TauntPlayer()
	{
		int randNum;
		randNum = (rand() % 3);
		cout << taunts[randNum] << endl;
	}
};

string Ork::species = "Ork";

class Undead : public Enemy
{
public:
	static string species;
	string taunts[3] = { "The Undead lazes around.","The Undead disattaches their head and juggles it.",
		"The Undead taunts the player." };

	 void TauntPlayer()
	{
		 int randNum;
		 randNum = (rand() % 3);
		 cout << taunts[randNum] << endl;
		 
	}
};

string Undead::species = "Undead";

int main()
{
	int playerChoice;
	int seed;
	string playerClass;
	Wizard wizard;
	Knight knight;
	cout << "Welcome to Gabriel's Battle Simulator." << endl;
	cout << endl;
	cout << "What Class do you want to be?" << endl;
	cout << endl;
	cout << "Please enter 1 for Wizard or 2 for Knight" << endl;
	do
	{
		cin >> playerChoice;
		cout << endl;
		if (playerChoice == 1)
		{
			cout << "You selected the Wizard Class." << endl;
			cout << endl;
			playerClass = "Wizard";
			cout << "What is your player's name?" << endl;
			cin >> wizard.name;
			wizard.health = 125;
			cout << endl;
			cout << "Here's a summary of what you've chosen so far." << endl;
			cout << endl;
			cout << "Class: " << playerClass << endl;
			cout << "Name: " << wizard.name << endl;
			seed = (int)wizard.name[0];
			cout << "Starting HP: " << wizard.health << endl;

		}
		else if (playerChoice == 2)
		{
			cout << "You selected the Knight Class." << endl;
			cout << endl;
			playerClass = "Knight";
			cout << "What is your player's name?" << endl;
			cin >> knight.name;
			cout << endl;
			knight.health = 200;
			cout << endl;
			cout << "Here's a summary of what you've chosen so far." << endl;
			cout << endl;
			cout << "Class: " << playerClass << endl;
			cout << "Name: " << knight.name << endl;
			seed = (int)knight.name[0];
			cout << "Starting HP: " << knight.health << endl;
			
		}
		else
		{
			cout << "You inputted an invalid option. Please enter 1 for Wizard or 2 for Knight." << endl;
			cout << endl;
		}
	} while (playerChoice != 1 && playerChoice != 2);

	cout << endl;
	cout << "Would you like to watch a battle?" << endl;
	cout << endl;
	cout << "Please enter 1 for Yes or 2 for No" << endl;
	do
	{
		cin >> playerChoice;
		cout << endl;
		if (playerChoice == 1)
		{
			srand(seed);
			playerChoice = (rand() % 2) + 1;

			if (playerChoice == 1)
			{
				Ork ork = new Ork();
				ork.health = 500;
				cout << "Species: " << ork.species << endl;
				cout << "Starting HP: " << ork.health << endl;
				cout << endl;
				if (playerClass == "Wizard")
				{
					ork.TauntPlayer();
					cout << wizard.name;
					ork.health -= wizard.NormalAttack();
					cout << ork.species << "." << endl;
					cout << "The " << ork.species << " has " << ork.health << " health remaining." << endl;
					ork.TauntPlayer();
					cout << wizard.name << " used " << wizard.specialAttackName << endl;
					cout <<  wizard.name;
					ork.health -= wizard.SpecialAttack();
					cout << ork.species << "." << endl;
					cout << "The " << ork.species << " has " << ork.health << " health remaining." << endl;
					cout << "The " << ork.species;
					wizard.health -= ork.NormalAttack();
					cout << wizard.name << "." << endl;
					cout << wizard.name << " has " << wizard.health << " health remaining." << endl;
					cout << "The " << ork.species;
					wizard.health -= ork.NormalAttack();
					cout << wizard.name << "." << endl;
					cout << wizard.name << " has " << wizard.health << " health remaining." << endl;
					cout << wizard.name << " used " << wizard.specialAttackName << endl;
					cout << wizard.name;
					ork.health -= wizard.SpecialAttack();
					cout << ork.species << "." << endl;
					cout << "The " << ork.species << " has " << ork.health << " health remaining." << endl;
					ork.TauntPlayer();
					cout << wizard.name << " used " << wizard.specialAttackName << endl;
					cout << wizard.name;
					ork.health -= wizard.SpecialAttack();
					cout << ork.species << "." << endl;
					cout << endl;
					cout << "You Win!" << endl;
				}
				else
				{
					ork.TauntPlayer();
					cout << knight.name;
					ork.health -= knight.NormalAttack();
					cout << ork.species << "." << endl;
					cout << "The " << ork.species << " has " << ork.health << " health remaining." << endl;
					ork.TauntPlayer();
					cout << knight.name << " used " << knight.specialAttackName << endl;
					cout << knight.name;
					ork.health -= knight.SpecialAttack();
					cout << ork.species << "." << endl;
					cout << "The " << ork.species << " has " << ork.health << " health remaining." << endl;
					cout << "The " << ork.species;
					knight.health -= ork.NormalAttack();
					cout << knight.name << "." << endl;
					cout << knight.name << " has " << knight.health << " health remaining." << endl;
					cout << "The " << ork.species;
					knight.health -= ork.NormalAttack();
					cout << knight.name << "." << endl;
					cout << knight.name << " has " << knight.health << " health remaining." << endl;
					cout << knight.name << " used " << knight.specialAttackName << endl;
					cout << knight.name;
					ork.health -= knight.SpecialAttack();
					cout << ork.species << "." << endl;
					cout << "The " << ork.species << " has " << ork.health << " health remaining." << endl;
					ork.TauntPlayer();
					cout << knight.name << " used " << knight.specialAttackName << endl;
					cout << knight.name;
					ork.health -= knight.SpecialAttack();
					cout << ork.species << "." << endl;
					cout << endl;
					cout << "You Win!" << endl;
				}
				
				

			}
			else 
			{
				Undead undead;
				undead.health = 450;
				cout << "Species: " << undead.species << endl;
				cout << "Starting HP: " << undead.health << endl;
				cout << endl;
				if (playerClass == "Wizard")
				{
					undead.TauntPlayer();
					cout << wizard.name;
					undead.health -= wizard.NormalAttack();
					cout << undead.species << "." << endl;
					cout << "The " << undead.species << " has " << undead.health << " health remaining." << endl;
					undead.TauntPlayer();
					cout << wizard.name << " used " << wizard.specialAttackName << endl;
					cout << wizard.name;
					undead.health -= wizard.SpecialAttack();
					cout << undead.species << "." << endl;
					cout << "The " << undead.species << " has " << undead.health << " health remaining." << endl;
					cout << "The " << undead.species;
					wizard.health -= undead.NormalAttack();
					cout << wizard.name << "." << endl;
					cout << wizard.name << " has " << wizard.health << " health remaining." << endl;
					cout << "The " << undead.species;
					wizard.health -= undead.NormalAttack();
					cout << wizard.name << "." << endl;
					cout << wizard.name << " has " << wizard.health << " health remaining." << endl;
					cout << wizard.name << " used " << wizard.specialAttackName << endl;
					cout << wizard.name;
					undead.health -= wizard.SpecialAttack();
					cout << undead.species << "." << endl;
					cout << "The " << undead.species << " has " << undead.health << " health remaining." << endl;
					undead.TauntPlayer();
					cout << wizard.name << " used " << wizard.specialAttackName << endl;
					cout << wizard.name;
					undead.health -= wizard.SpecialAttack();
					cout << undead.species << "." << endl;
					cout << endl;
					cout << "You Win!" << endl;
				}
				else
				{
					undead.TauntPlayer();
					cout << knight.name;
					undead.health -= knight.NormalAttack();
					cout << undead.species << "." << endl;
					cout << "The " << undead.species << " has " << undead.health << " health remaining." << endl;
					undead.TauntPlayer();
					cout << knight.name << " used " << knight.specialAttackName << endl;
					cout << knight.name;
					undead.health -= knight.SpecialAttack();
					cout << undead.species << "." << endl;
					cout << "The " << undead.species << " has " << undead.health << " health remaining." << endl;
					cout << "The " << undead.species;
					knight.health -= undead.NormalAttack();
					cout << knight.name << "." << endl;
					cout << knight.name << " has " << knight.health << " health remaining." << endl;
					cout << "The " << undead.species;
					knight.health -= undead.NormalAttack();
					cout << knight.name << "." << endl;
					cout << knight.name << " has " << knight.health << " health remaining." << endl;
					cout << knight.name << " used " << knight.specialAttackName << endl;
					cout << knight.name;
					undead.health -= knight.SpecialAttack();
					cout << undead.species << "." << endl;
					cout << "The " << undead.species << " has " << undead.health << " health remaining." << endl;
					undead.TauntPlayer();
					cout << knight.name << " used " << knight.specialAttackName << endl;
					cout << knight.name;
					undead.health -= knight.SpecialAttack();
					cout << undead.species << "." << endl;
					cout << endl;
					cout << "You Win!" << endl;
				}
			}
		}
		else if (playerChoice == 2)
		{
			
		}
		else
		{
			cout << "You inputted an invalid option. Please enter 1 for Yes or 2 for No." << endl;
			cout << endl;
		}
	} while (playerChoice != 1 && playerChoice != 2);



};



