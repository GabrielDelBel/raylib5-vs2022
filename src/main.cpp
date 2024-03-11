
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

class Knight : public Player
{
public:
	static string specialAttackName;
	int specialAttackAmount;

	int SpecialAttack()
	{
		specialAttackAmount = (rand() % 35) + 115;
		cout << " dealt " << specialAttackAmount << "damage to the ";
		return specialAttackAmount;
	}
};

class Ork : public Enemy
{
public:
	static string species;
	string taunts[3] = { "The ork utters a defaning roar.","The ork slams their club again the ground.", "The ork mocks the player." };

	
	void TauntPlayer()
	{
		int randNum;
		randNum = (rand() % 3);
		cout << taunts[randNum] << endl;
	}
};

class Undead : public Enemy
{
public:
	static string species;
	string taunts[3] = { "The zombie lazes around.","The zombie disattaches their head and juggles it.",
		"The zombie taunts the player." };

	 void TauntPlayer()
	{
		 int randNum;
		 randNum = (rand() % 3);
		 cout << taunts[randNum] << endl;
		 
	}
};

int health()
{

}

int main()
{
	int playerChoice;
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
			cout << "Here's a summary of what you've chosen so far." << endl;
			cout << endl;
			cout << "Class: " << playerClass << endl;
			cout << "Name: " << knight.name << endl;
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
			playerChoice = (rand() % 2) + 1;
			if (playerChoice == 1)
			{
				Ork ork;
				ork.health = 500;
				cout << "Species: Ork" << endl;
				cout << "Starting HP: " << ork.health << endl;
				cout << endl;
				if (playerClass == "Wizard")
				{
					ork.TauntPlayer();
					cout << wizard.name;
					wizard.NormalAttack();
					cout << "Ork." << endl;
					ork.TauntPlayer();
					cout << wizard.name;
					wizard.SpecialAttack();
					cout << "Ork." << endl;
					cout << "The Ork";
					ork.NormalAttack();
					cout << wizard.name << "." << endl;
					cout << "The Ork";
					ork.NormalAttack();
					cout << wizard.name << "." << endl;
					cout << wizard.name;
					wizard.SpecialAttack();
					cout << "Ork." << endl;
					ork.TauntPlayer();
					cout << wizard.name;
					wizard.SpecialAttack();
					cout << "Ork." << endl;
				}
				else
				{
					ork.TauntPlayer();
					cout << knight.name;
					knight.NormalAttack();
					cout << "Ork." << endl;
					ork.TauntPlayer();
					cout << knight.name;
					knight.SpecialAttack();
					cout << "Ork." << endl;
					cout << "The Ork";
					ork.NormalAttack();
					cout << knight.name << "." << endl;
					cout << "The Ork";
					ork.NormalAttack();
					cout << knight.name << "." << endl;
					cout << knight.name;
					knight.SpecialAttack();
					cout << "Ork." << endl;
					ork.TauntPlayer();
					cout << knight.name;
					knight.SpecialAttack();
					cout << "Ork." << endl;
				}
				
				

			}
			else 
			{
				Undead undead;
				undead.health = 450;
				cout << "Species: Undead" << endl;
				cout << "Starting HP: " << undead.health << endl;
				cout << endl;
				if (playerClass == "Wizard")
				{
					undead.TauntPlayer();
					cout << wizard.name;
					wizard.NormalAttack();
					cout << "Undead." << endl;
					undead.TauntPlayer();
					cout << wizard.name;
					wizard.SpecialAttack();
					cout << "Undead." << endl;
					cout << "The Undead";
					undead.NormalAttack();
					cout << wizard.name << "." << endl;
					cout << "The Undead";
					undead.NormalAttack();
					cout << wizard.name << "." << endl;
					cout << wizard.name;
					wizard.SpecialAttack();
					cout << "Undead." << endl;
					undead.TauntPlayer();
					cout << wizard.name;
					wizard.SpecialAttack();
					cout << "Undead." << endl;
				}
				else
				{
					undead.TauntPlayer();
					cout << knight.name;
					knight.NormalAttack();
					cout << "Undead." << endl;
					undead.TauntPlayer();
					cout << knight.name;
					knight.SpecialAttack();
					cout << "Undead." << endl;
					cout << "The Undead";
					undead.NormalAttack();
					cout << knight.name << "." << endl;
					cout << "The Undead";
					undead.NormalAttack();
					cout << knight.name << "." << endl;
					cout << knight.name;
					knight.SpecialAttack();
					cout << "Undead." << endl;
					undead.TauntPlayer();
					cout << knight.name;
					knight.SpecialAttack();
					cout << "Undead." << endl;
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



