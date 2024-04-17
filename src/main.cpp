
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
	string itemsKnight[4] = {"Claymore", "Scimitar", "LongSword","Rapier"};
	string itemsWizard[4] = { "Fire Wand", "Magic Cloak", "Inferno Wand", "Book of Knowledge" };
	string itemsBoth[3] = { "Small Potion", "Medium Potion", "Large Potion" };
	string validCommands[6] = { "pickup" ,"drop", "use", "equip","open","search"};
};

Items classItem;

class Commands
{
public: 
	virtual void CommandUsed(list<string>& inventory, string item) = 0;


};

Commands* command;

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

class Heal : public Commands
{
	void CommandUsed(list<string>& inventory, string item)
	{

	}
};

class Equip : public Commands
{
	void CommandUsed(list<string>& inventory, string item)
	{

	}
};

class Look
{
	void CommandUsed()
	{

	}
};

class Open 
{
	void CommandUsed()
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
	int attack;
	string typeCharacter;
	list<string> inventory;

	int NormalAttack()
	{
		int randNum;
		randNum = (rand() % 15) + 50;
		cout << " dealt " << randNum << " damage to the ";
		return randNum;
	}

	virtual void SetInitialHPAttackandClass() = 0;

	virtual int SpecialAttack() = 0;
};

Player* player;

class Enemy : public GameObject
{
public:
	int health;
	int attack;
	

	int NormalAttack()
	{
		int randNum;
		randNum = 1 + (rand() % 20 / 100) * attack;
		cout << " dealt " << randNum << " damage to ";
		return randNum;
		
	}

	virtual void TauntPlayer() = 0;
	
};

Enemy* enemy;

class Wizard : public Player
{
public:
	static string specialAttackName;
	int specialAttackAmount;
	
	void SetInitialHPAttackandClass()
	{
		health = 150;
		attack = 30;
		typeCharacter = "Wizard";
	}

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

	void SetInitialHPAttackandClass()
	{
		health = 200;
		attack = 20;
		typeCharacter = "Knight";
	}

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

class Room
{
public:
	int textStage;
	int availaleActions;
	bool isDoorOpen;
	string items[3];
	string fillerText[3];
	string validCommands[6];
	Enemy* foe;

};

Room dungeon[4];

void SetUpDungeon(string characterClass)
{
	for (int i = 0; i < 4; i++)
	{
		dungeon[i].textStage = 0;
		if (i == 0)
		{
			dungeon[i].isDoorOpen = true;
		}
		else
		{
			dungeon[i].isDoorOpen = false;
		}
		for (int j = 0; i < classItem.validCommands->length(); i++)
		{
			dungeon[i].validCommands[j] = classItem.validCommands[j];
		}
	}
	dungeon[0].items[0] = classItem.itemsBoth[0];
	dungeon[0].items[1] = classItem.itemsKnight[0];
	dungeon[0].items[2] = classItem.itemsKnight[0];
	dungeon[0].fillerText[0] = "You are in the dungeon entrence. This must have been where they brought the prisoners for proccesing.";
	dungeon[0].fillerText[1] = "After a bit of seaching you find weapons on the ground. However, you saw movement out of the corner of your eye.";
	dungeon[0].fillerText[2] = "You search more, but find nothing. You don't notice the undead attacking from behind.";


	
}
void Dungeon(int roomNumber)
{
	int 
	cout << dungeon[roomNumber].fillerText[dungeon[roomNumber].textStage] << endl;
	cout << endl;
	cout << "You can ";
	for (int i = 0; i < dungeon; i++)
	{
		int x = dungeon[roomNumber].availaleActions.Length()
	}
}

void SplitChoice(string decision, int roomNum)
{
	queue<char> firstHalf;
	queue<char> secondHalf;
	for (int x = 0; x < decision.length(); x++)
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
	ValidateCommandOrItem(player, firstHalf, secondHalf, roomNum);
}

void ValidateCommandOrItem(Player* character, queue<char> action, queue<char> item, int roomNum)
{
	string enteredCommand;
	string enteredItem;
	do
	{
		enteredCommand += tolower(action.front());
		action.pop();
	} while (action.size() > 0);	

	do
	{
		enteredItem += tolower(item.front());
		item.pop();
	} while (item.size() > 0);

	for (int x = 0; x < classItem.validCommands->size();x++)
	{
		if (enteredCommand == classItem.validCommands[x])
		{
			if (x == 0)
			{
				command = new PickUp();
				command->CommandUsed(character->inventory, enteredItem);
			}
		}
		else
		{
			cout << "You did not choose a valid option." << endl;
		}
	}	
}

bool valid = false;

string SimpleValidation(string simpleDecision)
{
	do
	{
		
		if (simpleDecision == "1")
		{
			valid = true;
			return "1";

		}
		else if (simpleDecision == "2")
		{
			valid = true;
			return "2";
		}
		else
		{
			cout << "You did not choose a valid option." << endl;
			getline(cin, simpleDecision);
			valid = false;

		}

	} while (!valid);
}

void ChooseClass(string chosenClass)
{
	if (chosenClass == "1")
	{
		player = new Wizard();
		player->SetInitialHPAttackandClass();
		SetUpDungeon("wizard");
	}
	else if (chosenClass == "2")
	{
		player = new Knight();
		player->SetInitialHPAttackandClass();
		SetUpDungeon("knight");
	}
}

void Battle(Player* character, Enemy* combattant )
{
	character->SpecialAttack();
	combattant->TauntPlayer();
}

bool split = false;

int main()
{

	string decision;

	cout << "Welcome To Gabriel's Amazing RPG" << endl;
	cout << "You can either play as a Wizard or a Knight." << endl;
	cout << "Please press 1 for Wizard or 2 for Knight." << endl;
	getline(cin, decision);
	if (SimpleValidation(decision) == "1")
	{
		ChooseClass("1");
	}
	else
	{
		ChooseClass("2");
	}
	cout << "Please enter your name." << endl;
	getline(cin, decision);
	player->name = decision;
	cout << "Here are your starting stats" << endl;
	cout << "Name: " << player->name <<  endl;
	cout << "Class: " << player->typeCharacter << endl;
	cout << "Starting Health: " << player->health << endl;
	cout << "Starting Attack: " << player->attack << endl;
	cout << endl;
	cout << "Press any key to continue.";
	cout << endl;
	cout << "You are a " << player->typeCharacter << "in search of fame and riches." << endl;
	cout << "You left your small village and headed towards a nearby dungeon 3 days away." << endl;
	cout << "You've heard rumors that there's a treasure deep in the dungeon guarded by a monster who had been terrorizing the nearby town." << endl;
	cout << "Who ever defeats the monster would become famous. As well as being able to claim the treasure." << endl;
	cout << "You enter the dungeon." << endl;
	dungeon[0];



	
	
};



