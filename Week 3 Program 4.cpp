/********************************************************************
	Palindrome Testing

	A palindrome is a string that reads the same backward as forward. For example, the words mom,  dad, 
	 madam  and  radar are all palindromes. Write  a class Pstring that  is derived from the STL string 
	class. The Pstring class adds a member function

	bool isPalindrome( )

	that determines  whether  the string is a palindrome. Include a constructor that takes an STL 
	string object as parameter and passes it to the string base class constructor. Test your class by 
	having a main program that  asks the user to enter a string. The program uses the string to 
	initialize a Pstring object and then calls isPalindrome() to determine  whether the string entered 
	is a palindrome.

	You may find it useful to use the subscript  operator [] of the string class: if str is a string 
	object and k is an integer, then str[k] returns  the character at position  k in the string.
*********************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pstring: public string
{
	public:
		Pstring(string);
		bool isPalindrom();
};


Pstring::Pstring(string word) :string(word)
{
}
bool Pstring::isPalindrom()
{
	int size = this->size();
	string compare;
	int index = size - 1;
	vector <char> temp;

	while (index >= 0)
	{
		temp.push_back((*this)[index]);
		index--;
	}

	for (int x = 0; x < size; x++)
	{
		compare += temp[x];
	}

	return compare == *this;
}


int main()
{
	string test;

	do
	{
		cout << "Enter a string/word: (Enter -1 to exit) ";
		getline(cin, test);

		Pstring check(test);
		
		cout << check.isPalindrom() << endl << endl;
	} while (test != "-1");

	return 0;
}