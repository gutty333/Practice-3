/********************************************************************
SimpleVector Modification
Modify the SimpleVector class template, presented in this chapter, to include the
member functions push_back and pop_back. These functions should emulate the STL
vector class member functions of the same name. (See Table 16-4.) The push_back
function should throw an exception if the array is full. The push_back function should
accept an argument and insert its value at the end of the array. The pop_back function
should accept no argument and remove the last element from the array. Test the class
with a driver program.


SearchableVector Modification
Modify the SearchableVector class template, presented in this chapter, so it performs a
binary search instead of a linear search. Test the template in a driver program.


SortableVector Class Template
Write a class template named SortableVector. The class should be derived from the
SimpleVector class presented in this chapter. It should have a member function that sorts
the array elements in ascending order. (Use the sorting algorithm of your choice.) Test the
template in a driver program.
*********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// Simple Vector Class
template <class T>
class SimpleVector
{
protected:
	T* list;
	int listSize;
	int currentIndex;


public:
	SimpleVector();
	SimpleVector(int);
	SimpleVector ( SimpleVector& );
	~SimpleVector();

	void print();

	void push_back(T);
	void pop_back();
};

// Constructor
template <class T>
SimpleVector<T>::SimpleVector()
{
	list = NULL;
	listSize = 0;
	currentIndex = 0;
}

// Constructor Overload
template <class T>
SimpleVector<T>::SimpleVector(int size)
{
	listSize = size;
	currentIndex = 0;
	list = new T[listSize];
}

// Copy Constructor
template <class T>
SimpleVector<T>::SimpleVector(SimpleVector& tempObj)
{
	listSize = tempObj.listSize;
	currentIndex = tempObj.currentIndex;
	list = new T[listSize];


	for (int x = 0; x < currentIndex; x++)
	{
		list[x] = tempObj.list[x];
	}
}

// Destructor
template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (listSize > 0)
	{
		delete [] list;
	}
}

// print method
template <class T>
void SimpleVector<T>::print()
{
	if (currentIndex == 0)
	{
		cout << "There are no elements in the list" << endl;
		return;
	}

	for (int x = 0; x < currentIndex; x++)
	{
		cout << list[x] << endl;
	}
	cout << endl;
}

// push back method
template <class T>
void SimpleVector<T>::push_back(T value)
{
	try
	{
		if (currentIndex >= listSize)
		{
			throw "Unable to add anymore elements into the list";
		}

		// adding the value and updating our current index
		list[currentIndex] = value;
		currentIndex++;
	}
	catch (char* error)
	{
		cout << error << endl;
	}
}

// pop back method
template <class T>
void SimpleVector<T>::pop_back()
{
	try
	{
		if (currentIndex == 0)
		{
			throw "There are no more element to remove from the list";
		}

		// update the index
		currentIndex--;
	}
	catch (char* error)
	{
		cout << error << endl;
	}
}


// Searchable Vector Class
template <class T>
class SearchableVector :public SimpleVector<T>
{
public:
	SearchableVector() {};
	SearchableVector(int size) :SimpleVector<T>(size) {};
	SearchableVector(SimpleVector<T>& obj) :SimpleVector<T>(obj) {};
	void binarySearch(T);
};
// binary search method
template <class T>
void SearchableVector<T>::binarySearch(T target)
{
	int start = 0;
	int end = listSize;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (list[mid] == target)
		{
			cout << "The value " << target << " was found at index " << mid << endl;
			return;
		}
		else if (target < list[mid])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	cout << "The value " << target << " was not found in the list" << endl;
}

// Sortable Vector Class
template <class T>
class SortableVector :public SimpleVector<T>
{
public:
	SortableVector() {};
	SortableVector(int size) :SimpleVector<T>(size) {};
	SortableVector(SimpleVector<T>& obj) :SimpleVector<T>(obj) {};
	void sorting();
};
// sorting method which will use a selection sort approach
template <class T>
void SortableVector<T>::sorting()
{
	for (int x = 0; x < currentIndex-1; x++)
	{
		int lowestValue = x;

		for (int y = x + 1; y < currentIndex; y++)
		{
			if (list[y] < list[lowestValue])
			{
				
				lowestValue = y;
				
			}
		}


		T temp = list[x];
		list[x] = list[lowestValue];
		list[lowestValue] = temp;
	}
}
int main()
{
	SimpleVector<int> list(5);

	list.print();
	list.push_back(4);
	list.push_back(16);
	list.push_back(23);
	list.push_back(45);
	list.print();

	list.push_back(35);
	list.print();
	list.push_back(12);

	list.pop_back();
	list.pop_back();
	list.print();

	list.pop_back();
	list.pop_back();
	list.print();

	list.pop_back();
	list.pop_back();

	list.push_back(35);
	list.push_back(4);
	list.push_back(16);
	list.push_back(23);
	list.push_back(45);
	list.print();

	SimpleVector<int> list2(list);

	list2.print();

	cout << endl << endl << "Sorting and searching section" << endl;
	SortableVector<int> list3(list);
	list3.print();

	cout << "Sorting Result" << endl;
	list3.sorting();
	list3.print();


	SearchableVector<int> list4(list3);
	list4.print();
	
	list4.binarySearch(5);
	list4.binarySearch(35);
	list4.binarySearch(45);
	list4.binarySearch(4);
	
	return 0;
}