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
	 string gameManufacturer;
	 string developer;
	 int achievementCount = 0;

	 Achievement* achievementArray = nullptr;
 };

 struct Platform 
 {
	 string Name;
	 string manufacturer;
	 int gameCount = 0;
	 Game* gameArray = nullptr; // game pointer named game = null pointer for now

 };

 void CreatePlatform(Platform& platform)
 {
	 cout << "What platform is the achievement for?" << endl;
	 cin >> platform.Name;
	 cout << "What manufacturer made the platform?" << endl;
	 cin >> platform.manufacturer;
	 cout << "How many games have achivements?" << endl;
	 cin >> platform.gameCount;
	 platform.gameArray = new Game[platform.gameCount];

	 for (int i = 0; i < platform.gameCount; i++)
	 {
		 CreateGames(platform.gameArray[i]);
	 }
 }

 void CreateGames(Game& game)
 {
	 cout << "What's the name of the game?" << endl;
	 cin >> game.gameName;
	 cout << "Who manufactured the game?" << endl;
	 cin >> game.gameManufacturer;
	 cout << "Who developed the game?" << endl;
	 cin >> game.developer;
	 cout << "How many acheivemnts in this game?" << endl;
	 cin >> game.achievementCount;
	 game.achievementArray = new Achievement[game.achievementCount];

	 for (int i = 0; i < game.achievementCount; i++)
	 {
		 CreateAchievements(game.achievementArray[i]);
	 }
 }

 void CreateAchievements(Achievement& achievement)
 {
	 cout << "What's the title of the achievement?" << endl;
	 cin >> achievement.title;
	 cout << "What's the discription of the achievement?" << endl;
	 cin >> achievement.description;
	 cout << "What's the score of the achievement of the achievement?" << endl;
	 cin >> achievement.scoreValue;
 }

int main()
{
	Platform platform;
	CreatePlatform(platform);

	cout << "The platform name is " + platform.Name + " The Manufacturers name is " + platform.manufacturer;
}
