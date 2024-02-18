//#include "raylib.h"
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

struct Character
{
    string name;
    string species;
    string backstory;
    int startingHealth;
    Weapon weapon;
    Armor Armor;
};

struct Weapon 
{
    string name;
    int damage;
    string specialAbility[5];
};

Weapon weapon1;


struct Armor
{
    string name;
    string discription;
    int armorValue;
};

void StartingWeapons()
{
    weapon1.name = "Memes";
}

void CreateCharacter(Character &character)
{
    cout << "Please enter your character's name" << endl;
    cin >> character.name;
    cout << "Please enter your character's starting health ranging from 100 to 500." << endl;
    cin >> character.startingHealth;
    /*
    if (character.startingHealth << 100 || character.startingHealth >> 500)
    {

    }
    */
    cout << "Please select a starting weapon" << endl;
    cout << weapon1.name << endl;
    character.weapon.name = weapon1.name;

}



int main()
{
    cout << "Welcome to the character creator." << endl;
    Character character1;
    CreateCharacter(character1);
    cout << character1.name << endl;
    cout << character1.startingHealth << endl;
    cout << character1.weapon.name << endl;
    return 0;
}


