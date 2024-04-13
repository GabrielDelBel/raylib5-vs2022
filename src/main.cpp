
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

void LineUpCustomers() 
{
	for (int x = 0; x < 30; x++)
	{
		line.customerQueue.push(0);
	}
}

void RemovePancakes(int orderSize)
{
	for (int x = orderSize; x > 0; x--)
	{
		try
		{
			if (pancakes.pancakeStack.size() > 0)
			{
				pancakes.pancakeStack.pop();
			}
			else
			{
				throw int(x);
			}
		}
		catch (int remaningPancakes)
		{
			cout << "Error: The customer ordered " << remaningPancakes << " too many pancakes." << endl;
			cout << endl;
			cout << "Cooking more pancakes." << endl;
			cout << endl;
			CookPancakes();
			RemovePancakes(remaningPancakes);
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
		cout << "There are currently " << pancakes.pancakeStack.size() << " pancakes on the stack." << endl;
		cout << endl;
		RemovePancakes(randomNum);
		cout << "After the order there are " << pancakes.pancakeStack.size() << " pancakes on the stack." << endl;
		cout << endl;
	}
	
};



