/********************************************************************
	Ackermann’s Function

	Ackermann’s  function  is a recursive mathematical algorithm that  can be used to test how well a 
	computer performs  recursion.  Write  a function  A(m, n) that  solves Ackermann’s function.  Use 
	the following logic in your function:

	If m = 0 then  return n + 1
	If n = 0 then  return A(m-1, 1) Otherwise,     return A(m-1, A(m, n-1))

	Test your function  in a driver program that displays the following values:
	A(0, 0)    A(0, 1)    A(1, 1)    A(1, 2)    A(1, 3)    A(2, 2)    A(3, 2)
*********************************************************************/

#include <iostream>
using namespace std;

int Ackerman(int m, int n)
{
	if (m == 0)
	{
		return n + 1;
	}
	else if (n == 0)
	{
		return Ackerman(m - 1, n);
	}
	else
	{
		return Ackerman(m - 1, Ackerman(m, n - 1));
	}
}

int main()
{
	cout << Ackerman(0, 0) << endl;
	cout << Ackerman(0, 1) << endl;
	cout << Ackerman(1, 1) << endl;
	cout << Ackerman(1, 2) << endl;
	cout << Ackerman(1, 3) << endl;
	cout << Ackerman(2, 2) << endl;
	cout << Ackerman(3, 2) << endl;

	return 0;
}