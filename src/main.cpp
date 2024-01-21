#include "raylib.h"
#include "Math.h"
#include<iostream>
#include "string"


 struct Achievement
 {
	 string title;

 };
 
 struct Game
 {
	 Achievement* Achievement = nullptr;
 };

 struct Platform 
 {
	 Game* Game = nullptr; // game pointer named game = null pointer for now

 };

int main()
{

}
