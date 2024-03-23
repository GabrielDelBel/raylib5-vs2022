
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
	Rectangle(T x, T y)
	{
		length = x;
		width = y;
	}

	void SetLength(T x)
	{
		length = x;
	}
	void SetWidth(T y)
	{
		width = y;
	}

	T GetLength()
	{
		return length;
	}

	T GetWidth()
	{
		return width;
	}

};

template <class T>
T Area(Rectangle<T>& quadraltaical)
{
	return quadraltaical.GetLength() * quadraltaical.GetWidth();
}


int main()
{
	
	
	Rectangle<int> rectangle(2,5);
	Rectangle<float> rectangle2(4.37f, 7.02f);
	
	cout << "Rectangle 1:" << endl;
	cout << "Length " << rectangle.GetLength() << endl;
	cout << "Width " << rectangle.GetWidth() << endl;
	cout << "Rectangle 2:" << endl;
	cout << "Length " << rectangle2.GetLength() << endl;
	cout << "Width " << rectangle2.GetWidth() << endl;

	cout << "Rectangle 1:" << endl;
	cout << "Area " << Area<int>(rectangle) << endl;
	cout << "Rectangle 2:" << endl;
	cout << "Area " << Area<float>(rectangle2) << endl;
	
	
	

};



