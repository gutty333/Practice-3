#include <iostream>
#include <string>
using namespace std;

// Function that will recursively reverse a string
void stringRev(string value)
{
	int size = value.size();

	if (size > 0)
	{
		cout << value[size - 1];
		value.erase(value.begin() + size-1);
		stringRev(value);
	}
	else
	{
		cout << endl;
	}
}


// Function to recursively calculate the sum of an array
int arraySum(int arr[], int size)
{
	int total = 0;
	if (size > 0)
	{
		total+= arr[size - 1];
		return arraySum(arr, size - 1) + total;
	}
	else
	{
		return 0;
	}
}


// recursive function to find the total in the specified row ex(4 rows = 10)
// row 4 = 4, row 3 = 3, row 2 = 2, row 1 = 1, Simple :)
int triangle(int row)
{
	if (row > 0)
	{
		return triangle(row -1) + row;
	}
	else
	{
		return 0;
	}
}

int main()
{
	stringRev("hello people this is weird");
	stringRev("No idea of what I am doing :0");
	stringRev("The force is strong with this code");
	stringRev("pencil and paper are great help for recursive functions");

	int test[] = { 2, 3, 4, 5, 6, 7, 8 };
	int test2[] = { 1, 2, 3, 43423, 12, 4, 5541, 23, 9 };
	int test3[] = { 1, 2, 3 };
	cout << endl << arraySum(test, 7) << endl;
	cout << arraySum(test2, 9) << endl;
	cout << arraySum(test3, 3) << endl;

	cout << endl <<  triangle(4) << endl;
	cout << triangle(5) << endl;
	cout << triangle(6) << endl;
	cout << triangle(7) << endl;

	return 0;
}