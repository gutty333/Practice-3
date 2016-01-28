/********************************************************************
1. Write a function that recursively reverses a string. The function will have a single
parameter of type string. It will print the reversed characters to the screen followed by a
newline character. Before you start writing code answer these questions. What is the
base case? Will you print out the characters before or after the recursive function call?
HINT: You can try it both ways and see if it makes a difference.

2. Write a function that recursively calculates the sum of an array. The function should
have 2 parameters, the array and an integer showing the number of elements in the array.
The function will use a recursive call to sum the value of all elements. What is the base
case? What is the structure of the recursive call?

3. A triangular number is the sum of all items that form a triangle with N rows. It may
help to think of the number of bowling pins if you changed the number of rows. For
example in a standard game there are 4 rows and 10 pins. If you add a fifth row you add
5 pins for a total of 15. Always remember mathisfun.com!
Write a recursive function to calculate the triangular number for N. (Or a function that
counts the number of pins necessary for N rows.) What is the base case? How many
items are in row 1? How many are in row 2? How do you sum the number of items in
each row and add it to the total value?
*********************************************************************/

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
	cout << arraySum(test, 7) << endl;
	cout << arraySum(test2, 9) << endl;
	cout << arraySum(test3, 3) << endl;

	cout << endl <<  triangle(4) << endl;
	cout << triangle(5) << endl;
	cout << triangle(6) << endl;
	cout << triangle(7) << endl;

	return 0;
}