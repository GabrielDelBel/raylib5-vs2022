//#include "raylib.h"
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

struct Enemy
{
    float health;

    // base health "declaration" --> tells the compiler "hey, base health is a thing"
    static float baseHealth;
};

// base health "definition" --> tells the compiler specific information about base health
// (without *specific information* you will get linker errors!!!)
// :: is the "scope-resolution" operator. It resolves between different names
float Enemy::baseHealth = 100.0f;

// "Forward-declaration" (just like static variables, we can have function declarations, and definitions)
void StaticExamples();


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


struct Armor
{
    string name;
    string discription;
    int armorValue;
};

void Inhertiance();



int main()
{
    //StaticExamples();
    Inhertiance();

    return 0;
}

void Inhertiance()
{
    
}

// Function definition
void StaticExamples()
{
    // Why :: is useful:
    // We know we can't have duplicate variables because the compiler can't tell the difference.
    //float baseHealth = 1.0f;
    //float baseHealth = 2.0f;

    // We use :: to "resolve the scope" of object-specific variables so that compiler knows who's who!
    // (We need to tell the compiler which object baseHealth belongs to)
    Player::baseHealth = 100.0f;
    Enemy::baseHealth = 50.0f;

    Player player1;
    cout << "Player 1 health: " << player1.health << endl;

    // Changes health for *ALL* players
    cout << endl << "Changing base health to 200:" << endl;
    Player::baseHealth = 200.0f;
    Player player2;
    Player player3;
    cout << "Player 1 health: " << player1.health << endl;
    cout << "Player 2 health: " << player2.health << endl;
    cout << "Player 3 health: " << player3.health << endl;

    // Changes health for specific player
    // (if we change baseHealth AFTER player1 is created, player1 is unaffected)

    cout << endl << "Multiplying player1's health by 5:" << endl;
    player1.health *= 5.0f;
    cout << "Player 1 health: " << player1.health << endl;

    // All new players will now have a base health of 1000 (200 * 5)
    cout << endl << "Changing base health to 1000:" << endl;
    Player::baseHealth *= 5.0f;
    Player player4;
    cout << "Player 1 health: " << player1.health << endl;
    cout << "Player 2 health: " << player2.health << endl;
    cout << "Player 3 health: " << player3.health << endl;
    cout << "Player 4 health: " << player4.health << endl;
}

// Additional function pointer examples:
using Ex1 = void(*)();  // Ex1 is a pointer to a function that returns void and takes no arguments
using Ex2 = int(*)();   // Ex2 is a pointer to a function that returns int and takes no arguments
using Ex3 = float(*)(); // Ex3 is a pointer to a function that returns float and takes no arguments
using Ex4 = void(*)(int, float);
// Ex4 is a pointer to a function that returns void and takes an int followed by a float as arguments

void Example4(int a, float b)
{
    cout << a << b << "<-- output from function pointer example 4!" << endl;
}

void FunctionPointerExample()
{
    // This is a "delegate" in C#
    Ex4 exampleFunctionPtr = Example4;

    // We can store a function like any other variable, and then invoke it at our convenience!
    exampleFunctionPtr(1, 1.f);
}
