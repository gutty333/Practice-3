/********************************************************************
	Iterative Factorial
	
	Write  an  iterative  version  (using  a  loop  instead  of  recursion)  of  the  factorial  
	function shown  in this chapter.  Demonstrate the use of the function  in a program that  prints  
	the factorial  of a number  entered by the user.
*********************************************************************/

#include <iostream>
using namespace std;

// Factorial Function using a basic for loop instead of being a recursive function
int factorial(int number)
{
	int factor = 1;

	for (number;number>0; number--)
	{
		factor *= number;
	}

	return factor;
}

int main()
{

	int num;

	cout << "Enter a number and I will show you the factorial: ";
	cin >> num;

	cout << "The factorial of " << num << " is " << factorial(num) << endl;

	return 0;
}