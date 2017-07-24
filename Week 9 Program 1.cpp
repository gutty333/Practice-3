/********************************************************************
String Bound Exceptions

Write a class BCheckString that is derived from the STL string class. This new class will
have two member functions:

A) A BCheckString(string s) constructor that receives a string object passed by
value and passes it on to the base class constructor.

B) An char operator[](int k) function that throws a BoundsException object
if k is negative or is greater than or equal to the length of the string. If k is within
the bounds of the string, this function will return the character at position k in the
string.

You will need to write the definition of the BoundsException class. Test your class with a
main function that attempts to access characters that are within and outside the bounds of
a suitably initialized BCheckString object.
*********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class BCheckString:public string
{
	public:
		class BoundsException
		{
			public:
				int index;
				BoundsException(int x)
				{
					index = x;
				}
		};

		BCheckString(string);
		char operator[](int);
};

// constructor
BCheckString::BCheckString(string value) :string(value)
{

}

// operator overloading
char BCheckString::operator[](int index)
{
	// Checking that the value pass is not out of bound
	// If so than throw an exception
	if (index < 0 || index >= length())
	{
		throw BoundsException(index);
	}

	// returning the character
	return at(index);
}


int main()
{
	string value;

	cout << "Please enter a word" << endl;
	cin >> value;

	BCheckString test(value);

	try
	{
		int index;
		cout << "Enter an index" << endl;
		cin >> index;
		char letter = test[index];

		cout << "The letter at index " << index << " is " << letter << endl;
	}
	catch (BCheckString::BoundsException temp)
	{
		cout << "The index of " << temp.index << " is out of bound" << endl;
		cout << "The word " << value << " has a length of " << value.length() << endl;
	}

	return 0;
}