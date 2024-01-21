#include "raylib.h"
#include "Math.h"
#include<iostream>
#include <string>

using namespace std;


 struct Achievement
 {
	 string title;
	 string description;
	 int scoreValue;

 };
 
 struct Game
 {
	 string name;
	 string manufacturer;
	 string developer;

	 Achievement* Achievement = nullptr;
 };

 struct Platform 
 {
	 string name;
	 string manufacturer;
	 Game* Game = nullptr; // game pointer named game = null pointer for now

 };

int main()
{

}
