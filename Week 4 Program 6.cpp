/********************************************************************
	 Recursive Member Test

	Write a recursive Boolean function  named  isMember. The function  should  accept three parameters: 
	an  array  of integers,  an  integer  indicating  the  number  of elements  in the array,  and  an 
	integer  value to be searched  for.  The function  should  return  true if the value is found  in 
	the array,  or false if the value is not  found.  Demonstrate the use of the function  in a program 
	that  asks the user to enter  an array  of numbers  and  a value
	to be searched  for.
*********************************************************************/

#include <iostream>
using namespace std;

bool isMember(int arr[], int size, int val)
{
	int check = 0;
	
	if (arr[size-1] != val && size >= 0)
	{
		check = isMember(arr, size - 1, val);
		
	}
	else if (arr[size-1] == val && size >= 0)
	{
		return 1;
	}

	return check;
}


int main()
{
	int test[13] = { 4534, 2, 462, 6, 43, 12, 34, 9856, 56, 74, 231, 577, 321 };
	int val;

	cout << "Enter a number ";
	cin >> val;

	cout << isMember(test, 13, val)<< endl;


	return 0;
}