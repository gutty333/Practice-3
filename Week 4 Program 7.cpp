/********************************************************************
	String Reverser

	Write  a recursive  function  that  accepts  a string  as its argument and  prints  the  string  in
	reverse order.  Demonstrate the function  in a driver program.
*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reversal(string val)
{
	int size = val.size();
	
	if (size > 0)
	{
		cout << val[size-1];
		val.erase(val.begin() + size - 1);
		reversal(val);
	}
}

int main()
{
	string test;

	cout << "Enter a string: ";
	getline(cin, test);

	cout << "Here is the string reversed: ";
	reversal(test);
	cout << endl;

	return 0;
}