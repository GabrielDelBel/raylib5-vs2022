#pragma once
#include <string>
#include <list>
#include "Player_Enemy_Base.h"
#include <iostream>
using namespace std;

class Enemy
{
public:
	int health;
	int attack;

	int NormalAttack();

	virtual void TauntPlayer() = 0;
};

