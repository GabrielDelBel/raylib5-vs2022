#include "Player.h"
#include <iostream>
using namespace std;

int NormalAttack()
{
	int randNum;
	randNum = (rand() % 15) + 50;
	cout << " dealt " << randNum << " damage to the ";
	return randNum;
}
