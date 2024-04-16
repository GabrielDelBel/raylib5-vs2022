
#include "Math.h"
#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <cctype>
using namespace std;



class Items
{
public:
	string items[3] = {"knife" ,"sword", "gun"};
	string validCommands[2] = { "pickup" ,"drop"};
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
			classItem.items->erase(0);
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

Player* player;

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


int ValidateCommand(queue<char> word)
{
	string enteredCommand;
	do
	{
		enteredCommand += tolower(word.front());
		word.pop();
	} while (word.size() > 0);	
	cout << enteredCommand << endl;

	for (int x = 0; x < classItem.validCommands->size();x++)
	{
		if (enteredCommand == classItem.validCommands[x])
		{
			return x;
		}
		else
		{
			return -1;
		}
	}	
}

string ValidateItem(queue<char> word)
{
	string enteredCommand;
	do
	{
		enteredCommand += tolower(word.front());
		word.pop();
	} while (word.size() > 0);
	cout << enteredCommand << endl;

	for (int x = 0; x < classItem.validCommands->size();x++)
	{
		if (enteredCommand == classItem.items[x])
		{
			return enteredCommand;
		}
		else
		{
			return "failure";
		}
	}
}



int main()
{
	
	player = new Knight();
	string decision;
	bool split = false;
	queue<char> firstHalf;
	queue<char> secondHalf;
	int validation;

	cout << "Please type Pickup Knife" << endl;
	cin >> decision;
	for (int x = 0; x < decision.length() ; x++)
	{
		if (isspace(decision[x]))
		{
			split = true;
		}

		if (!split)
		{
			firstHalf.push(decision[x]);
		}
		else
		{
			secondHalf.push(decision[x]);
		}
	}
	validation = ValidateCommand(firstHalf);
	decision = ValidateItem(secondHalf);
	if (validation == 0)
	{
		Commands* command;
		command = new PickUp;
		command->CommandUsed(player->inventory, decision);
	}
	cout << player->inventory.size() << endl;
};



