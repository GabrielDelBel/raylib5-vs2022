
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Rectangle
{
	T length;
	T width;

	void SetLength(T x)
	{
		length = x
	}
	void Setwidth(T y)
	{
		width = y
	}

	T GetLength()
	{
		return length;
	}

	T Getwidth()
	{
		return width
	}

};

template <class T>
T Area(T Rectangle)
{
	return length * width;
}


int main()
{
	Rectangle<int> rectangle = Rectangle<int>();
	int x = 2;
	int y = 5;
	int intResult;
	float a = 4.37;
	float b = 7.02;
	float floatResult;

	intResult = Area<int>(rectangle);
	cout << intResult << endl;
	floatResult = Area<float>(a, b);
	cout << floatResult << endl;
	
	

};



