//#include "raylib.h"
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

struct Armour
{
    string name;
    string discription;
    int armourValue;
};

Armour armour1;
Armour armour2;
Armour armour3;

struct Weapon
{
    string name;
    int damage;
    string specialAbility[3] = {"1: Special effects actiavte twice as often","2: +10% damage on this weapon","3: Heal 15Hp every turn"};
    string chosenSpecialAbility;
};

Weapon weapon1;
Weapon weapon2;
Weapon weapon3;

struct Character
{
    string name;
    string species;
    string backstory;
    int startingHealth;
    Weapon weapon;
    Armour Armour;
    
    int selection;
    string ability;
    bool inputCheck = false;
};

void StartingWeapons()
{
    weapon1.name = "Bronze Sword";
    weapon1.damage = 45;
    cout << "1" << weapon1.name << " The damage this weapon does is " << weapon1.damage << endl;
    weapon2.name = "Steel Sword";
    weapon2.damage = 85;
    cout << "2" << weapon2.name << " The damage this weapon does is " << weapon2.damage << endl;
    weapon3.name = "Adamantium Sword";
    weapon3.damage = 125;
    cout << "3" << weapon3.name << " The damage this weapon does is " << weapon3.damage << endl;
    cout << endl;



}

void StartingArmour()
{
    armour1.name = "Chainmail";
    armour1.armourValue = 5;
    armour1.discription = "Medievil chainmail. Good against slicing attacks.";
    cout << "1" << armour1.name << " The protection value this armor gives is " << armour1.armourValue << endl;
    cout << armour1.discription << endl;
    armour1.name = "Plate Armour";
    armour1.armourValue = 10;
    armour1.discription = "Medievil Plate Armour. Good against slicing and stabbing attacks.";
    cout << "2" << armour2.name << " The protection value this armor gives is " << armour2.armourValue << endl;
    cout << armour2.discription << endl;
    armour1.name = "Kevlar";
    armour1.armourValue = 20;
    armour1.discription = "A Kevlar Vest. Good against stabbing and projectile attacks.";
    cout << "3" << armour3.name << " The protection value this armor gives is " << armour3.armourValue << endl;
    cout << armour3.discription << endl;
}

void CreateCharacter(Character &character)
{
    cout << "Please enter your character's name" << endl;
    cin >> character.name;
    cout << "Please enter your character's starting health ranging from 100 to 500." << endl;
    cin >> character.startingHealth;
    if (character.startingHealth < 100 || character.startingHealth > 500)
    {
        character.inputCheck = false;
         do {
            cout << "Your input wasn't recognised. Please enter your character's starting health ranging from 100 to 500." << endl;
            cin >> character.startingHealth;
            if (character.startingHealth < 100 || character.startingHealth > 500)
            {

            }
            else
            {
                character.inputCheck = true;
            }

         } while (character.inputCheck == false);

    }
    cout << "Please select a starting weapon by pressing it's corresponding number. " << endl;
    cout << endl;
    StartingWeapons();
    cin >> character.selection;
    if (character.selection != 1 && character.selection != 2 && character.selection != 3)
    {
        character.inputCheck = false;
        do {
            cout << "Your input wasn't recognised. Please select a starting weapon by pressing it's corresponding number." << endl;
            cin >> character.startingHealth;
            if (character.startingHealth < 100 || character.startingHealth > 500)
            {

            }
            else
            {
                character.inputCheck = true;
            }

        } while (character.inputCheck == false);

    }
    cout << "Please select a special ability by pressing it's corresponding number. " << endl;
    cout << endl;
    cout << character.weapon.specialAbility[0] << endl;
    cout << character.weapon.specialAbility[1] << endl;
    cout << character.weapon.specialAbility[2] << endl;
    cin >> character.selection;

    if (character.selection != 1 && character.selection != 2 && character.selection != 3)
    {
        character.inputCheck = false;
        do {
            cout << "Your input wasn't recognised. Please select a special ability by pressing it's corresponding number." << endl;
            cin >> character.startingHealth;
            if (character.startingHealth < 100 || character.startingHealth > 500)
            {

            }
            else
            {
                character.inputCheck = true;
            }

        } while (character.inputCheck == false);

    }
    
    

}



int main()
{
    StartingWeapons();
    StartingArmour();
    cout << "Welcome to the character creator." << endl;
    Character character1;
    CreateCharacter(character1);
    cout << character1.name << endl;
    cout << character1.startingHealth << endl;
    cout << character1.weapon.name << endl;
    return 0;
}


