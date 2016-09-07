/********************************************************************
Write  a C++ class that  has an array  of integers  as a member  variable,  a pure  virtual
member function

	bool compare(int x, int y) = 0;

that compares  its two parameters and returns  a boolean  value, and a member function
void sort()
that  uses the comparison defined  by the compare  virtual  function  to sort  the array. The sort 
function  will swap a pair of array elements a[k] and a[j] if

compare (a[k], a[j])

returns  true. Explain  how you can use this class to produce  classes that  sort arrays  in
ascending order and descending order.

*********************************************************************/

#include <iostream>
using namespace std;

const int size = 5;

// Base Abstract Class
class Base
{
	protected:
		int list[size];
		int index;

	public:
		Base();
		virtual bool compare(int, int) = 0;
		void setValues(int);
		void printList();
		void sort();
};

// Ascending Derived Class
class Ascending :public Base
{
	public:
		virtual bool compare(int, int);
};

// Descending Derived Class
class Descending :public Base
{
	public:
		virtual bool compare(int, int);
};



// Constructor
Base::Base()
{
	for (int x = 0; x < size; x++)
	{
		list[x] = 0;
	}

	index = 0;
}

// Compare function for the Ascending class
bool Ascending::compare(int x, int y)
{
	if (x > y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Compare function for the Descending class
bool Descending::compare(int x, int y)
{
	if (x < y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Sort Member Function
void Base::sort()
{
	int temp;
	bool swap;

	do
	{
		swap = false;

		for (int x = 0; x < size - 1; x++)
		{
			if (compare(list[x], list[x + 1]))
			{
				temp = list[x];
				list[x] = list[x + 1];
				list[x + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}


// Set values function
void Base::setValues(int val)
{
	if (index < size)
	{
		list[index] = val;
		index++;
	}
}

// Print function
void Base::printList()
{
	for (int x = 0; x < size; x++)
	{
		cout << list[x] << endl;
	}
}


int main()
{
	Base* test[] = { new Ascending, new Descending };


	// Setting values for both objects
	int value;
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < size; y++)
		{
			cout << "Enter a number: ";
			cin >> value;

			test[x]->setValues(value);
		}
		cout << endl;
	}


	cout << "Printing original Ascending" << endl;
	test[0]->printList();
	cout << endl << "Printing Ascending sorted" << endl;
	test[0]->sort();
	test[0]->printList();

	cout << endl << endl << "Printing original Descending" << endl;
	test[1]->printList();
	cout << endl << "Printing Descending sorted" << endl;
	test[1]->sort();
	test[1]->printList();

	return 0;
}