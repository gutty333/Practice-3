/********************************************************************
Min/Max Templates

Write templates for the two functions min and max. min should accept two arguments and
return the value of the argument that is the lesser of the two. max should accept two
arguments and return the value of the argument that is the greater of the two. Design a
simple driver program that demonstrates the templates with various data types.
*********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// Min Template function
template <class T>
T minValue(T val, T val2)
{
	if (val < val2)
	{
		return val;
	}
	return val2;
}


// Max template function
template <class T>
T maxValue(T val, T val2)
{
	if (val > val2)
	{
		return val;
	}
	return val2;
}


int main()
{
	cout << "The minimum value  is " << minValue(4, 19) << endl;
	cout << "The minimum value  is " << minValue(32, 15) << endl;
	cout << "The minimum value  is " << minValue(4.56, 19.3) << endl;
	cout << "The minimum value  is " << minValue('z', 'b') << endl;

	cout << "The maximum value  is " << maxValue(13, 19) << endl;
	cout << "The maximum value  is " << maxValue(32, 6) << endl;
	cout << "The maximum value  is " << maxValue(14.56, 42.13) << endl;
	cout << "The maximum value  is " << maxValue('c', 'x') << endl;
	return 0;
}