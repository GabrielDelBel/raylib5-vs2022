
#include "Math.h"
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;


class ReversableWords
{
public:
	queue<char> original;
	stack<char> backwards;
	string wordToFlip;
	bool isPalindrome;
};

ReversableWords words;

void ReverseWord(string passedWord, int x)
{
	words.wordToFlip = passedWord;
	if (x < words.wordToFlip.length())
	{
		if (!isspace(words.wordToFlip[x]))
		{
			words.original.push(words.wordToFlip[x]);
			words.backwards.push(words.wordToFlip[x]);
			ReverseWord(words.wordToFlip, ++x);
		}
		else
		{
			ReverseWord(words.wordToFlip, ++x);
		}
		
	}

}

void PrintReversedWord()
{
	if (words.backwards.size() > 0)
	{
		cout << words.backwards.top();
		words.backwards.pop();
		PrintReversedWord();
	}	
}

void EmptyOriginalWord()
{
	if (words.original.size() > 0)
	{
		words.backwards.pop();
		PrintReversedWord();
	}
}

void IsPalindrome(int num)
{
	if (num >= words.wordToFlip.length())
	{
		cout << words.wordToFlip << " is a palindrome." << endl;;
	}

	if (words.backwards.size() > 0 && words.original.size() > 0 && words.backwards.size() == words.original.size())
	{
		if (words.original.front() == words.backwards.top())
		{
			words.original.pop();
			words.backwards.pop();
			IsPalindrome(++num);
		}
		else
		{
			cout << words.wordToFlip << " is not a palindrome." << endl;;
		}
	}
	else
	{
	}
}


int main()
{
	string word;

	cout << "Please Enter a String" << endl;
	cin >> word;
	ReverseWord(word, 0);
	cout << "Is the word you enetered a palindrome?" << endl;
	IsPalindrome(0);
	ReverseWord(word, 0);
	cout << "Here is your word reversed." << endl;
	PrintReversedWord();
	
};



