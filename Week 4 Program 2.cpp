/********************************************************************
	Recursive Conversion

	Convert  the following function  to one that uses recursion.
	void sign(int n)
	{


		while (n > 0)
		{

			cout << "No Parking\n";
			n--;
		}
	}
	Demonstrate the function  with a driver program.
*********************************************************************/

#include <iostream>
using namespace std;

void printRecursive(int number)
{
	if (number > 0)
	{
		cout << "No Parking" << endl;
		printRecursive(number - 1);
	}
}


int main()
{
	int num;

	cout << "How many times do you want to print the message: ";
	cin >> num;

	printRecursive(num);

	return 0;
}