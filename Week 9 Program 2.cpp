/********************************************************************
Arithmetic Exceptions

Write a function that accepts an integer parameter and returns its integer square root. The
function should throw an exception if it is passed an integer that is not a perfect square.
Demonstrate the function with a suitable driver program.
*********************************************************************/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Will evaluate number and check if it is a perfect square
// If not it should throw an exception
int perfectSquare(int value)
{
	int result = sqrt(value);

	if (result*result != value)
	{
		throw value;
	}

	cout << "The square root of " << value << " is " << result << endl;
}


int main()
{
	
	cout << "Please enter a number" << endl;
	int num;
	cin >> num;


	try
	{
		perfectSquare(num);
	}
	catch (int value)
	{
		cout << "The value " << value << " is not a perfect square" << endl;
	}



	return 0;
}