#include "Enemy.h"

int Enemy::NormalAttack()
{
	int randNum;
	randNum = 1 + (rand() % 20 / 100) * attack;
	cout << " dealt " << randNum << " damage to ";
	return randNum;

}
