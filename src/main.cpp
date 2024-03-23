
#include "Math.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Rectangle
{
	T length;
	T width;
	

public:
	void SetLength(T x)
	{
		length = x
	}
	void SetWidth(T y)
	{
		width = y
	}

	T GetLength()
	{
		return length;
	}

	T GetWidth()
	{
		return width
	}

	T area;

};

template <class T>
T Area(T Rectangle)
{
	Rectangle.
	return length * width;
}


int main()
{
	Rectangle<int> rectangle;
	Rectangle<float> rectangle2;
	int x = 2;
	int y = 5;
	rectangle.SetLength(x);
	rectangle.SetWidth(y);
	float a = 4.37;
	float b = 7.02;

	rectangle.area = Area<int>(rectangle);
	cout << intResult << endl;
	floatResult = Area<float>(a, b);
	cout << floatResult << endl;
	
	

};



