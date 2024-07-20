
#include "Math.h"
#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <cctype>
#include "Room.h"
#include "Player_Enemy_Base.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

class Room
{
public:
	int textStage;
	int availaleActions;
	bool isDoorOpen;
	string items[3];
	string fillerText[3];
	string validCommands[7];
	string choiceText[7];
};

Room dungeon[4];

class Items
{
public:
	string itemsKnight[4] = {"claymore", "scimitar", "longsword","rapier"};
	string itemsWizard[4] = { "wand", "cloak", "inferno", "book" };
	string itemsBoth[3] = { "small potion", "medium potion", "large potion" };
	string validCommands[7] = { "pickup" ,"drop", "use", "equip","open","search","leave"};
	string choiceText[7] = { "Pickup ", "Drop ","Use ","Equip ","Open Inventory","Search Around","Leave Room"};
};

Items classItem;

class Commands
{
public: 
	virtual void CommandUsed(list<string>& inventory, string item, int roomNum) = 0;


};

Commands* command;

class PickUp : public Commands
{
public:
	void CommandUsed(list<string>& inventory, string item, int roomNum)
	{
		bool foundItem = false;
		for (int a = 0; a < dungeon[roomNum].items->size(); a++)
		{
			if (dungeon[roomNum].items[a] == item)
			{
				inventory.push_front(item);
				dungeon[roomNum].items->erase(a);
				foundItem = true;
			}
			
		}
		if (!foundItem)
		{
			cout << "The item you selected wasn't there";
		}
		
	}
};



class Drop : public Commands
{
public:
	void CommandUsed(list<string>& inventory, string item, int roomNum)
	{
		bool foundItem = false;
		for (int a = 0; a < inventory.size(); a++)
		{
			if (inventory.front() == item)
			{
				foundItem = true;
				inventory.pop_front();
			}
			else
			{
				string savedItem;
				savedItem = inventory.front();
				cout << inventory.front() << endl;
				inventory.pop_front();
				inventory.push_back(savedItem);
			}
		}
		if (!foundItem)
		{
			cout << "The item you selected wasn't there";
		}
	}
};

bool canHeal = false;

class Heal : public Commands
{
	void CommandUsed(list<string>& inventory, string item, int roomNum)
	{
		bool foundItem = false;
		canHeal = false;
		for (int a = 0; a < inventory.size(); a++)
		{
			if (inventory.front() == item)
			{
				foundItem = true;
				canHeal = true;

			}
			else
			{
				string savedItem;
				savedItem = inventory.front();
				cout << inventory.front() << endl;
				inventory.pop_front();
				inventory.push_back(savedItem);
			}
		}
		if (!foundItem)
		{
			cout << "The item you selected wasn't there";
		}
	}
};

class Equip : public Commands
{
	void CommandUsed(list<string>& inventory, string item, int roomNum)
	{
		
			bool foundItem = false;
			canHeal = false;
			for (int a = 0; a < inventory.size(); a++)
			{
				if (inventory.front() == item)
				{
					foundItem = true;
					canHeal = true;

				}
				else
				{
					string savedItem;
					savedItem = inventory.front();
					cout << inventory.front() << endl;
					inventory.pop_front();
					inventory.push_back(savedItem);
				}
			}
			if (!foundItem)
			{
				cout << "The item you selected wasn't there";
			}
		
	}
};

Player* player;

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

	void SetHP(int changeHealth)
	{
		health += changeHealth;
	}

	void SetAttack(int changeAttack)
	{
		attack += changeAttack;
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
	void SetHP(int changeHealth)
	{
		health += changeHealth;
	}

	void SetAttack(int changeAttack)
	{
		attack += changeAttack;
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

void Dungeon(int roomNumber, Player* character);

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
		for (int j = 0; j < classItem.validCommands->length(); j++)
		{
			dungeon[i].validCommands[j] = classItem.validCommands[j];
			dungeon[i].choiceText[j] = classItem.choiceText[j];
		}
	}

	dungeon[0].items[0] = classItem.itemsBoth[0];
	dungeon[0].items[1] = classItem.itemsKnight[0];
	dungeon[0].items[2] = classItem.itemsWizard[0];
	dungeon[0].fillerText[0] = "You are in the dungeon entrence. This must have been where they brought the prisoners for proccesing.";
	dungeon[0].fillerText[1] = "After a bit of seaching you find weapons on the ground. However, you saw movement out of the corner of your eye.";
	dungeon[0].fillerText[2] = "You search more, but find nothing. You don't notice the undead attacking from behind.";


	
}

void PrintInventory(int roomNumber, Player* character)
{
	int invalidActions = 0;
	cout << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Inventory" << endl;
	for (int i = 0; i < character->inventory.size(); i++)
	{
		string savedItem;
		savedItem = character->inventory.front();
		cout << character->inventory.front() << endl;
		character->inventory.pop_front();
		character->inventory.push_back(savedItem);
	}
	cout << "---------------------------------------------------------------" << endl;
}

void ValidateCommandOrItem(Player* character, queue<char> action, queue<char> item, int roomNum)
{
	string enteredCommand;
	string enteredItem;
	int validchoice = 0;

	item.pop();

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

	for (int x = 0; x < dungeon[roomNum].validCommands->size();x++)
	{
		if (enteredCommand == classItem.validCommands[x])
		{
			validchoice++;
			if (x == 0)
			{
				command = new PickUp();
				command->CommandUsed(character->inventory, enteredItem,roomNum);
			}
			else if (x == 1)
			{
				command = new Drop();
				command->CommandUsed(character->inventory, enteredItem, roomNum);
			}
			else if (x == 2)
			{
				command = new Heal();
				command->CommandUsed(character->inventory, enteredItem, roomNum);
				if(canHeal)
					character->SetHP(character->health/100*30);
			}
			else if (x == 3)
			{
				command = new Equip();
				command->CommandUsed(character->inventory, enteredItem,roomNum);
				if (canHeal)
					character->SetAttack(10);
			}
			else if (x == 4)
			{
				if (character->isInventoryOpen == false)
				{
					character->isInventoryOpen = true;
				}
				else
				{
					character->isInventoryOpen = false;
				}
			}
			else if (x == 5)
			{
				dungeon[roomNum].textStage++;
			}
			else if (x == 6)
			{
				if (dungeon[roomNum].isDoorOpen == true)
				{
					Dungeon(++roomNum, character);
				}
				else
				{
					cout << "The Door isn't Open Yet." << endl;
				}

			}
		}
		else
		{
			
		}
	}
	if (validchoice == 0)
	{
		cout << "You made an invalid choice" << endl;
	}
	
}

bool split = false;

void SplitChoice(string decision, int roomNum)
{
	queue<char> firstHalf;
	queue<char> secondHalf;
	split = false;
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

void Dungeon(int roomNumber, Player* character)
{
	string choice;


	if (dungeon[roomNumber].isDoorOpen == false) 
	{
		dungeon[roomNumber].choiceText[6] = "";
	}

	if (character->inventory.size() == 0)
	{
		dungeon[roomNumber].choiceText[1] = "";
		dungeon[roomNumber].choiceText[2] = "";
		dungeon[roomNumber].choiceText[3] = "";
		dungeon[roomNumber].choiceText[4] = "";
	}
	else if (character->inventory.size() >= 0)
	{
		if (character->isInventoryOpen == false)
		{
			dungeon[roomNumber].choiceText[1] = "";
			dungeon[roomNumber].choiceText[2] = "";
			dungeon[roomNumber].choiceText[3] = "";
		}
		if (character->isInventoryOpen == true)
		{
			dungeon[roomNumber].choiceText[0] = "";
			dungeon[roomNumber].choiceText[5] = "";
			dungeon[roomNumber].choiceText[4] = "Close Inventory";
		}
	}

	cout << dungeon[roomNumber].fillerText[dungeon[roomNumber].textStage] << endl;

	if (character->isInventoryOpen == true)
	{
		PrintInventory(roomNumber, character);
	}

	cout << endl;
	cout << "You can: " << endl;
	for (int i = 0; i < dungeon[roomNumber].validCommands->length(); i++)
	{	
		if (dungeon[roomNumber].choiceText[i] == "")
		{

		}
		else
		{
			if (i == 0 && dungeon[roomNumber].items->size() > 0)
			{
				for (int j = 0; j < dungeon[roomNumber].items->size()/4; j++)
				{
					cout << dungeon[roomNumber].choiceText[0] << dungeon[roomNumber].items[j] << endl;
				}
				
			}
			else 
			{
				cout << dungeon[roomNumber].choiceText[i] << endl;
			}
			
		}
		
	}

	cout << "Please type one of your available options. Case doesn't matter" << endl;
	getline(cin, choice);
	SplitChoice(choice,roomNumber);
	for (int j = 0; j < dungeon[roomNumber].choiceText->length(); j++)
	{
		dungeon[roomNumber].choiceText[j] = classItem.choiceText[j];
	}
	Dungeon(roomNumber, character);
}

void Battle(Player* character, Enemy* combattant )
{
	character->SpecialAttack();
	combattant->TauntPlayer();
}


int main()
{
	bool valid = false;
	string decision;
	cout << "Welcome To Gabriel's Amazing RPG" << endl;
	cout << "You can either play as a Wizard or a Knight." << endl;
	cout << "Please press 1 for Wizard or 2 for Knight." << endl;
	do
	{
		getline(cin, decision);

		if (decision == "1")
		{
			valid = true;
			player = new Wizard();
			player->SetInitialHPAttackandClass();
			SetUpDungeon("wizard");
			
		}
		else if (decision == "2")
		{
			player = new Knight();
			player->SetInitialHPAttackandClass();
			SetUpDungeon("knight");
			valid = true;
			
		}
		else
		{
			cout << "You did not choose a valid option." << endl;

		}

	} while (!valid);
	
	
		
	
	

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
	cout << "You are a " << player->typeCharacter << " in search of fame and riches." << endl;
	cout << "You left your small village and headed towards a nearby dungeon 3 days away." << endl;
	cout << "You've heard rumors that there's a treasure deep in the dungeon guarded by a monster who had been terrorizing the nearby town." << endl;
	cout << "Who ever defeats the monster would become famous. As well as being able to claim the treasure." << endl;
	cout << "You enter the dungeon." << endl;
	Dungeon(0,player);



	
	
};



