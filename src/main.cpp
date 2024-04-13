
#include "Math.h"
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;


class Pancakes
{
public:
	int numPancakes;
	stack<int> pancakeStack;
};

Pancakes pancakes;

class CustomerLine 
{
public:
	int numCustomers;
	queue<int> customerQueue;
};

CustomerLine line;

void CookPancakes()
{
	for (int x = 0; x < 5; x++)
	{
		pancakes.pancakeStack.push(0);
	}
	
}

int GetPancakeStackSize()
{
	return pancakes.pancakeStack.size();
}

void LineUpCustomers() 
{
	for (int x = 0; x < 30; x++)
	{
		line.customerQueue.push(0);
	}
}

void RemovePancakes(int orderSize)
{
	for (int x = 0; x <orderSize; x++)
	{
		if (pancakes.pancakeStack.size() > 0)
		{
			pancakes.pancakeStack.pop();
		}
		else
		{
			throw string("There aren't enough pancakes in the stack.");
		}
		
	}
}



int main()
{
	string wait;

	CookPancakes();
	LineUpCustomers();
	cout << "Welcome to Gabriel's Pancake Shop" << endl;
	cout << "Please press any key to continue." << endl;
	cin >> wait;
	cout << endl;

	for (int x = 1; x <= 30; x++)
	{
		int randomNum = (int)Random(1, 3);
		cout << "Seriving the " << x << " customer." << endl;
		cout << endl;
		cout << "The " << x << " customer wants " << randomNum << " pancakes." << endl;
		cout << endl;
		RemovePancakes(randomNum);
	}
	
};



