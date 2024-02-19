//#include "raylib.h"
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

int moreCharacters;
int numCharacters = 1;

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
    Armour armour;
    
    int selection;
    string ability;
    bool inputCheck = false;
};

void StartingWeapons()
{
    weapon1.name = "Bronze Sword";
    weapon1.damage = 45;
    cout << "1: " << weapon1.name << " The damage this weapon does is " << weapon1.damage << endl;
    weapon2.name = "Steel Sword";
    weapon2.damage = 85;
    cout << "2: " << weapon2.name << " The damage this weapon does is " << weapon2.damage << endl;
    weapon3.name = "Adamantium Sword";
    weapon3.damage = 125;
    cout << "3: " << weapon3.name << " The damage this weapon does is " << weapon3.damage << endl;
    cout << endl;



}

void StartingArmour()
{
    armour1.name = "Chainmail";
    armour1.armourValue = 5;
    armour1.discription = "Medievil chainmail. Good against slicing attacks.";
    cout << "1: " << armour1.name << " The protection value this armor gives is " << armour1.armourValue << endl;
    cout << armour1.discription << endl;
    armour2.name = "Plate Armour";
    armour2.armourValue = 10;
    armour2.discription = "Medievil Plate Armour. Good against slicing and stabbing attacks.";
    cout << "2: " << armour2.name << " The protection value this armor gives is " << armour2.armourValue << endl;
    cout << armour2.discription << endl;
    armour3.name = "Kevlar";
    armour3.armourValue = 20;
    armour3.discription = "A Kevlar Vest. Good against stabbing and projectile attacks.";
    cout << "3: " << armour3.name << " The protection value this armor gives is " << armour3.armourValue << endl;
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
            cin >> character.selection;
            if (character.selection != 1 && character.selection != 2 && character.selection != 3)
            {

            }
            else
            {
                character.inputCheck = true;
            }

        } while (character.inputCheck == false);

    }
    else
    {
        if (character.selection == 1)
        {
            character.weapon.name = weapon1.name;
            character.weapon.damage = weapon1.damage;
        }
        else if (character.selection == 2)
        {
            character.weapon.name = weapon2.name;
            character.weapon.damage = weapon2.damage;
        }
        else
        {
            character.weapon.name = weapon3.name;
            character.weapon.damage = weapon3.damage;
        }

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
            cin >> character.selection;
            if (character.selection != 1 && character.selection != 2 && character.selection != 3)
            {

            }
            else
            {
                character.inputCheck = true;
            }

        } while (character.inputCheck == false);

    }
    else
    {
        if (character.selection == 1)
        {
            character.weapon.chosenSpecialAbility = character.weapon.specialAbility[0];
        }
        else if (character.selection == 2)
        {
            character.weapon.chosenSpecialAbility = character.weapon.specialAbility[1];
        }
        else
        {
            character.weapon.chosenSpecialAbility = character.weapon.specialAbility[2];
        }

    }

    cout << "Please select a starting armour by pressing it's corresponding number. " << endl;
    cout << endl;
    StartingArmour();
    cin >> character.selection;
    if (character.selection != 1 && character.selection != 2 && character.selection != 3)
    {
        character.inputCheck = false;
        do {
            cout << "Your input wasn't recognised. Please select a starting weapon by pressing it's corresponding number." << endl;
            cin >> character.selection;
            if (character.selection != 1 && character.selection != 2 && character.selection != 3)
            {

            }
            else
            {
                character.inputCheck = true;
            }

        } while (character.inputCheck == false);

    }
    else
    {
        if (character.selection == 1)
        {
            character.armour.name = armour1.name;
            character.armour.armourValue = armour1.armourValue;
            character.armour.discription = armour1.discription;
        }
        else if (character.selection == 2)
        {
            character.armour.name = armour2.name;
            character.armour.armourValue = armour2.armourValue;
            character.armour.discription = armour2.discription;
        }
        else
        {
            character.armour.name = armour3.name;
            character.armour.armourValue = armour3.armourValue;
            character.armour.discription = armour3.discription;
        }

    }
    
    

}



int main()
{
    cout << "Welcome to the character creator." << endl;
    Character character1;
    CreateCharacter(character1);
    cout << character1.name << endl;
    cout << character1.startingHealth << endl;
    cout << character1.weapon.name << endl;
    cout << character1.weapon.damage << endl;
    cout << character1.weapon.chosenSpecialAbility << endl;
    cout << character1.armour.name << endl;
    cout << character1.armour.armourValue << endl;
    cout << character1.armour.discription << endl;
    cout << endl;

    while (numCharacters < 3 || moreCharacters == 0)
    {
        cout << "Would you like to make another character? Please enter 1 for yes and 0 for no.";
        cin >> moreCharacters;

        if (moreCharacters != 0 && moreCharacters != 1)
        {
            bool inputCheck = false;

            do {
                cout << "Your input wasn't recognised. Please select either 0 or 1" << endl;
                cin >> moreCharacters;

                if (moreCharacters != 0 && moreCharacters != 1)
                {

                }
                else
                {
                    inputCheck = true;
                }

            } while (inputCheck == false);
        }
        else if (numCharacters == 1)
        {
            if (moreCharacters == 1)
            {
                Character character2;
                CreateCharacter(character2);
                cout << character2.name << endl;
                cout << character2.startingHealth << endl;
                cout << character2.weapon.name << endl;
                cout << character2.weapon.damage << endl;
                cout << character2.weapon.chosenSpecialAbility << endl;
                cout << character2.armour.name << endl;
                cout << character2.armour.armourValue << endl;
                cout << character2.armour.discription << endl;
                cout << endl;

                numCharacters++;

            }
        }
        else
        {
            Character character3;
            CreateCharacter(character3);
            cout << character3.name << endl;
            cout << character3.startingHealth << endl;
            cout << character3.weapon.name << endl;
            cout << character3.weapon.damage << endl;
            cout << character3.weapon.chosenSpecialAbility << endl;
            cout << character3.armour.name << endl;
            cout << character3.armour.armourValue << endl;
            cout << character3.armour.discription << endl;
            cout << endl;

            numCharacters++;
        }
    }

    if (numCharacters > 1)
    {
        cout << "Would you like to compare characters? Please enter 1 for yes and 0 for no.";
        cin >> moreCharacters;

        if (moreCharacters != 0 && moreCharacters != 1)
        {
            bool inputCheck = false;

            do {
                cout << "Your input wasn't recognised. Please select either 0 or 1" << endl;
                cin >> moreCharacters;

                if (moreCharacters != 0 && moreCharacters != 1)
                {

                }
                else
                {
                    inputCheck = true;
                }
            } while (inputCheck == false);
    }
    
    return 0;
}


