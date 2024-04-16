
#include "Math.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;



class Items
{
public:
	string items[3] = {"knife" ,"sword", "gun"};
};

Items classItem;

class Commands
{
public: 
	virtual void CommandUsed(list<string>& inventory, string item) = 0;


};

class PickUp : public Commands
{
public:
	void CommandUsed(list<string>& inventory, string item)
	{
		if (classItem.items[0] == item)
		{
			inventory.push_front(item);
		}
		else
		{
			cout << "You did not make a valid selection";
		}
		
	}
};

class Drop : public Commands
{
public:
	void CommandUsed(list<string>& inventory, string item)
	{

	}
};

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
	list<string> inventory;

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
	Player* player;
	player = new Knight();
	Commands* command;
	string decision;

	cout << "Please type Pickup Knife" << endl;
	cin >> decision;
	player->inventory;
};



