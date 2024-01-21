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
	 string gameName;
	 string manufacturer;
	 string developer;

	 Achievement* Achievement = nullptr;
 };

 struct Platform 
 {
	 string Name;
	 string manufacturer;
	 int gameCount;
	 Game* Game = nullptr; // game pointer named game = null pointer for now

 };

 void CreatePlatform(Platform& platform)
 {
	 int numGames;
	 cout << "What platform is the achievement for?" << endl;
	 cin >> platform.Name;
	 cout << "What manufacturer made the platform?" << endl;
	 cin >> platform.manufacturer;
	 cout << "How many games have achivements?" << endl;
	 cin >> platform.gameCount;
	 int* gameCount[platform.gameCount] = new int[];


 }

int main()
{

}
