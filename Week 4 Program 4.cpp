/********************************************************************
	Recursive Array Sum
	
	Write a function  that accepts two arguments, an array of integers and a number  indicating the
	number  of elements in the array.  The function  should  recursively calculate  the sum of
	all the numbers  in the array.  Demonstrate the use of the function  in a program that  asks
	the user to enter an array of numbers  and prints its sum.
*********************************************************************/

#include <iostream>
using namespace std;


int arraySum(int arr[], int size)
{
	if (size > 0)
	{
		return arraySum(arr, size - 1) + arr[size - 1];
	}
	else
	{
		return 0;
	}
}

int main()
{
	const int size = 5;
	int test[size];

	for (int x = 0; x < size; x++)
	{
		cout << "Enter a number: ";
		cin >> test[x];
	}

	cout << endl << "The sum of all numbers is: " << arraySum(test, size) << endl;

	return 0;
}