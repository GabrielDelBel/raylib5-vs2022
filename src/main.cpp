//#include "raylib.h"
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

static int moreCharacters;
static int numCharacters = 1;

struct Armour
{
    string name;
    string discription;
    int armourValue;   
};

istream& operator>>(istream& in, Armour& words/*non-constant reference cause we're modifying test*/)
{
    cout << "Enter the value of test: ";
    in >> words.armourValue;
    return in;
}

ostream& operator<< (ostream& out, const Armour& words)
{
    out << words.armourValue;
    return out;
}

int& operator== (Armour& first, Armour second)
{
    int difference;
    difference = first.armourValue - second.armourValue;
    return difference;
}

Armour armour1;
Armour armour2;
Armour armour3;

struct Weapon
{
    string name;
    int damage;
    string specialAbility[3] = {"Special effects actiavte twice as often","+10% damage on this weapon","Heal 15Hp every turn"};
    string chosenSpecialAbility;
};

istream& operator>>(istream& in, Weapon& words/*non-constant reference cause we're modifying test*/)
{
    cout << "Enter the value of test: ";
    in >> words;
    return in;
}

ostream& operator<< (ostream& out, const Weapon& words)
{
    out << words;
    return out;
}

int& operator== (Weapon& first, Weapon second)
{
    int difference;
    difference = first.damage - second.damage;
    return difference;
}

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

Character character[3];


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
    cout << endl;
    cout << "Please enter your character's starting health ranging from 100 to 500." << endl;
    cin >> character.startingHealth;
    cout << endl;
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
    cout << endl;
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

    cout << endl;
    cout << "Please select a special ability by pressing it's corresponding number. " << endl;
    cout << endl;
    cout << "1: " << character.weapon.specialAbility[0] << endl;
    cout << "2: " << character.weapon.specialAbility[1] << endl;
    cout << "3: " << character.weapon.specialAbility[2] << endl;
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

    cout << endl;
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

void PrintInformation(Character character)
{
    cout << endl;
    cout << character.name << endl;
    cout << endl;
    cout << "HP: " << character.startingHealth << endl;
    cout << endl;
    cout << "Weapon Name: " << character.weapon.name << endl;
    cout << "Weapon Damage: " << character.weapon.damage << endl;
    cout << "Weapon Special Ability: " << character.weapon.chosenSpecialAbility << endl;
    cout << endl;
    cout << "Armour Name: " << character.armour.name << endl;
    cout << "Armour Value: " << character.armour.armourValue << endl;
    cout << "Armour Description: " << character.armour.discription << endl;
    cout << endl;
}

void ExtraCharacters(int more, int num)
{
    if (more == 1)
    {
        if (num == 1)
        {
            CreateCharacter(character[1]);
            PrintInformation(character[1]);
            num++;

        }
        else if (num == 2)
        {
            CreateCharacter(character[2]);
            PrintInformation(character[2]);
            num++;
        }
        numCharacters = num;
    }
    else if (more != 0 && more != 1)
    {
        bool inputCheck = false;

        do {
            cout << "Your input wasn't recognised. Please select either 0 or 1" << endl;
            cin >> moreCharacters;

            if (more != 0 && more != 1)
            {

            }
            else
            {
                inputCheck = true;
            }

        } while (inputCheck == false);
    }
    
}


int main()
{ 
    /*
    cout << "Welcome to the character creator." << endl;
    cout << endl;
    
    CreateCharacter(character[0]);
    PrintInformation(character[0]);

    while (numCharacters < 3 )
    {
        cout << "Would you like to make another character. Please enter 1 for yes and 0 for no." << endl;
        cin >> moreCharacters;

        if (moreCharacters == 0)
        {
            break;
        }
        else
        {
            cout << endl;
            ExtraCharacters(moreCharacters, numCharacters);
        }

    }

    if (numCharacters > 1)
    {
        cout << endl;
        cout << "Would you like to compare characters? Please enter 1 for yes and 0 for no.";
        cin >> moreCharacters;

        if (moreCharacters == 1)
        {
            if ()
            {

            }
        }
        else if (moreCharacters != 0 && moreCharacters != 1)
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

    }
    */
    
    return 0;
}


