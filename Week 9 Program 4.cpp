/********************************************************************
Sequence Accumulation

Write a function
T accum(vector <T> v)
that forms and returns the “sum” of all items in the vector v passed to it. For example, if T is
a numeric type such as int or double, the numeric sum will be returned, and if T represents
the STL string type, then the result of concatenation is returned.

NOTE: For any type T, the expression T() yields the value or object created by the
default constructor. For example, T() yields the empty string object if T is the string
class. If T represents a numeric type such as int, then T() yields 0. Use this fact to
initialize your “accumulator.”

Test your function with a driver program that asks the user to enter 3 integers, uses accum
to compute the sum, and prints out the sum. The program than asks the user to enter
3 strings, uses accum to concatenate the strings, and prints the result.
*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// accumulation template function
template <class T>
T accum(vector <T> list)
{
	T total;

	for (int x = 0; x < list.size(); x++)
	{
		if (x == 0)
		{
			total = list[x];
		}
		else
		{
			total += list[x];
		}
		
	}

	return total;
}

int main()
{
	vector <int> numList;
	vector <string> stringList;

	int num;
	string name;

	for (int x = 0; x < 3; x++)
	{
		cout << "Enter a number " << endl;
		cin >> num;

		numList.push_back(num);
	}

	cout << "The sum of all values is " << accum(numList) << endl;
	

	for (int x = 0; x < 3; x++)
	{
		cout << "Enter a word" << endl;
		cin >> name; 

		stringList.push_back(name);
	}

	cout << "The sum of all values is " << accum(stringList) << endl;


	return 0;
}