/********************************************************************
	Analysis of Sorting  Algorithms

	Design a class AbstractSort that can be used to analyze the number of comparisons performed by a
	sorting  algorithm. The class should  have a member  function  compare  that  is capable  of
	comparing two array elements, and a means of keeping track of the number of comparisons performed.
	The class should be an abstract class with a pure virtual member function

	void sort(int arr[ ], int size)

	which,  when overridden, will sort the array  by calling the compare  function  to determine the
	relative  order  of pairs  of numbers.  Create  a subclass  of AbstractSort that  uses a simple
	sorting  algorithm to implement  the sort function.  The class should have a member function  that
	can be called after the sorting  is done to retrieve the number  of comparisons performed.


	Analysis of Quicksort
	Create  a subclass  of the AbstractSort class of Programming Challenge  1 that  uses the
	Quicksort algorithm to implement  the sort function.
*********************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

// Base Abstract Class
class AbstractSort
{
	protected:
		int compareCount;

	public:
		AbstractSort();
		bool compare(int, int);
		int getCompareCount();
		void print(int*, int);
		virtual void sort(int*, int) = 0;
		virtual void sort(int*, int, int) = 0;
};


// Bubble Sort Child Class
class BubbleSort :public AbstractSort
{
	public:
		virtual void sort(int*, int);
		virtual void sort(int*, int, int)
		{
			cout << "return" << endl;
		}
};

// Selection Sort Child Class
class SelectionSort :public AbstractSort
{
	public:
		virtual void sort(int*, int);
		virtual void sort(int*, int, int)
		{
			cout << "return" << endl;
		}
};

// Quick Sort Child Class
class QuickSort: public AbstractSort
{
	public:
		int partition(int*, int, int);
		virtual void sort(int*, int, int);
		virtual void sort(int*, int)
		{
			cout << "return" << endl;
		}
};


/******************** Implementing the Function Below *****************************/
// Default Constructor
AbstractSort::AbstractSort()
{
	compareCount = 0;
}

// Get Compare Count function
int AbstractSort::getCompareCount()
{
	return compareCount;
}

// Compare function
bool AbstractSort::compare(int x, int y)
{
	// For sorting in descending order
	if (x > y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Print function
void AbstractSort::print(int arr[], int size)
{
	for (int x = 0; x < size; x++)
	{
		cout << arr[x] << endl;
	}
}

// Bubble Sort sorting function
void BubbleSort::sort(int arr[], int size)
{
	int temp;
	bool swap;

	do
	{
		swap = false;

		for (int x = 0; x < size-1; x++)
		{
			if (compare(arr[x], arr[x + 1]))
			{
				temp = arr[x];
				arr[x] = arr[x + 1];
				arr[x + 1] = temp;
				swap = true;
				compareCount++;
			}
		}
	} while (swap);
}

// Selection Sort sorting function
void SelectionSort::sort(int arr[], int size)
{
	int index, value;

	for (int x = 0; x < size - 1; x++)
	{
		index = x;
		value = arr[x];

		for (int y = x + 1; y < size; y++)
		{
			if (compare(value, arr[y]))
			{
				value = arr[y];
				index = y;
				compareCount++;
			}
		}
		arr[index] = arr[x];
		arr[x] = value;
	}
}

// Partition function to find the pivot
int QuickSort::partition(int arr[], int start, int end)
{
	int pivot = arr[start];
	int pivotPosition = start;

	for (int x = start + 1; x <= end; x++)
	{
		if (compare(arr[x], pivot))
		{
			swap(arr[pivotPosition + 1], arr[x]);

			swap(arr[pivotPosition], arr[pivotPosition + 1]);

			pivotPosition++;
			compareCount++;
		}
	}

	return pivotPosition;
}

// Quick sort implementation
void QuickSort::sort(int arr[], int start, int end)
{
	if (start < end)
	{
		int p = partition(arr, start, end);

		sort(arr, start, p-1);

		sort(arr, p + 1, end);
	}
}


const int size = 10;

int main()
{
	AbstractSort* test[3] = { new BubbleSort, new SelectionSort, new QuickSort};

	int testArr[size];
	int testArr2[size];
	int testArr3[size];
	int value;

	for (int x = 0; x < size; x++)
	{
		cout << "Enter a number: ";
		cin >> value;
		testArr[x] = value;
	}

	// Copying values here
	for (int x = 0; x < size; x++)
	{
		testArr2[x] = testArr[x];
		testArr3[x] = testArr[x];
	}

	cout << endl << "Printing original of Bubble" << endl;
	test[0]->print(testArr, size);
	cout << "Here is the sort and count total" << endl;
	test[0]->sort(testArr, size);
	test[0]->print(testArr, size);
	cout << "Number of Comparison: " << test[0]->getCompareCount() << endl;

	cout << endl << "Printing original of Selection" << endl;
	test[1]->print(testArr2, size);
	cout << "Here is the sort and count total" << endl;
	test[1]->sort(testArr2, size);
	test[1]->print(testArr2, size);
	cout << "Number of Comparison: " << test[1]->getCompareCount() << endl;

	cout << endl << "Printing original of QuickSort" << endl;
	test[2]->print(testArr3, size);
	cout << "Here is the sort and count total" << endl;
	test[2]->sort(testArr3, 0, size);
	test[2]->print(testArr3, size);
	cout << "Number of Comparison: " << test[2]->getCompareCount() << endl;

	return 0;
}




