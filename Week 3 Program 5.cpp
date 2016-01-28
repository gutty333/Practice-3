/********************************************************************
	String Encryption

	Write  a  class  EncryptableString that   is  derived  from  the  STL  string class.  The
	Encryptable string class adds a member function

	void encrypt( )

	That  encrypts  the string contained in the object by replacing  each letter with its successor in 
	the ASCII ordering.  For example, the string baa would be encrypted  to cbb. Assume that all 
	characters that are part of an EncryptableString object are letters a, .., z and A, .., Z, and that 
	 the successor of z is a and the successor of Z is A. Test your class with a program
	that asks the user to enter strings that are then encrypted  and printed.
*********************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class EncryptableString :public string
{
	public:
		EncryptableString(string);
		void encrypt();
};


// Constructor
EncryptableString::EncryptableString(string word) :string(word)
{
}

// Encrypt Member Function
void EncryptableString::encrypt()
{
	int lenght = this->size();
	int ascii;
	vector <char> newString;

	for (int x = 0; x < lenght; x++)
	{
		newString.push_back((*this)[x]);
		ascii = (int)newString[x] + 1;
		
		if (ascii > 90 && ascii < 97)
		{
			ascii = 65;
		}
		else if (ascii > 122 && ascii < 127)
		{
			ascii = 97;
		}
		
		newString[x] = (char)ascii;
	}

	for (int y = 0; y < lenght; y++)
	{
		cout << newString[y];
	}
	cout << endl;
}

int main()
{
	string test;

	do
	{
		cout << "Enter a string/word: (Enter -1 to exit) ";
		getline(cin, test);

		EncryptableString check(test);

		check.encrypt();
		cout << endl;
	} while (test != "-1");


	return 0;
}