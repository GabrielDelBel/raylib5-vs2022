
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Sqaure
{
	T length;
	T width;

};

template <class T>
T Square(T length, T width)
{
	return length * width;
}

int main()
{
	int x = 2;
	int y = 5;
	int intResult;
	float a = 4.37;
	float b = 7.02;
	float floatResult;

	intResult = Square<int>(x, y);
	cout << intResult << endl;
	floatResult = Square<float>(a, b);
	cout << floatResult << endl;
	
	

};



