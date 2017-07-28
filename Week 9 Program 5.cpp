/********************************************************************
Rotate Left

The two sets of output below show the results of successive circular rotations of a vector.
One set of data is for a vector of integers, and the second is for a vector of strings.
1 3 5 7
3 5 7 1
5 7 1 3
7 1 3 5

a b c d e
b c d e a
c d e a b
d e a b c
e a b c d

Write two template functions that can be used to rotate and output a vector of a generic
type:
void rotateLeft(vector <T>& v)
void output(vector <T> v)

The first function performs a single circular left rotation on a vector, and the second
prints out the vector passed to it as parameter. Write a suitable driver program that
will allow you to test the two functions by generating output similar to the above.
Verify that the program works with vectors whose element types are char, int,
double, and string.


Template Reversal

Write a template function that takes as parameter a vector of a generic type and
reverses the order of elements in the vector, and then add the function to the program
you wrote for Programming Challenge 5. Modify the driver program to test the new
function by reversing and outputting vectors whose element types are char, int, double,
and string.
*********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// rotate template function
template <class T>
void rotateLeft(vector <T>& list)
{
	rotate(list.begin(),list.begin()+1, list.end());
}


// output template function
template <class T>
void output(vector <T> list)
{
	for (int x = 0; x < list.size(); x++)
	{

		cout << list[x] << " ";
	}
	cout << endl;
}


// reversal template function
template <class T>
void reversal(vector <T>& list)
{
	reverse(list.begin(), list.end());
}

int main()
{
	vector <int> list;
	list.push_back(1);
	list.push_back(3);
	list.push_back(5);
	list.push_back(7);

	cout << "Original List" << endl;
	output(list);

	cout << "List after rotations" << endl;
	rotateLeft(list);
	output(list);
	rotateLeft(list);
	output(list);
	rotateLeft(list);
	output(list);

	cout << "Reversing our List" << endl;
	reversal(list);
	output(list);


	vector <string> list2;
	list2.push_back("a");
	list2.push_back("b");
	list2.push_back("c");
	list2.push_back("d");
	list2.push_back("e");

	cout << endl << "Original List" << endl;
	output(list2);

	cout << "List after rotations" << endl;
	rotateLeft(list2);
	output(list2);
	rotateLeft(list2);
	output(list2);
	rotateLeft(list2);
	output(list2);
	rotateLeft(list2);
	output(list2);
	
	cout << "Reversing our List" << endl;
	reversal(list2);
	output(list2);
	return 0;
}