/********************************************************************
	Recursive Multiplication

	Write  a recursive  function  that  accepts  two  arguments  into  the parameters x and  y. The
	function  should  return  the value of x times y. Remember,  multiplication can be performed as
	repeated  addition:
	7 * 4 = 4 + 4 + 4 + 4 + 4 + 4 + 4
*********************************************************************/

#include <iostream>
using namespace std;

int multiply(int x, int y)
{
	if (y > 0)
	{
		return multiply(x, y - 1) + x;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int x, y;

	cout << "What two numbers to multiply (separate each number by a space): ";
	cin >> x >> y;

	cout << "Result: " << multiply(x, y) << endl;


	return 0;
}