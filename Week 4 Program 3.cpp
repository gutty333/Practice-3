/********************************************************************
	QuickSort Template

	Create  a template  version  of the  quickSort algorithm that  will work  with  any  data type that 
	 overloads  the comparison operators. Demonstrate the template  with a driver
	function.
*********************************************************************/

#include <iostream>
#include <algorithm> // This is needed for the swap function
using namespace std;


// Partition function
// This function will rearrange all the values of the array so that it can create 2 sublist
// All the values less than the pivot are to the left
// All the value greater than the pivot are to the right
// By default the pivot will be the starting element of the array (arr[0])
// It will return the pivot position to aid with the sort function
int partition(int arr[], int start, int end)
{
	int pivot = arr[start];
	int pivotPosition = start;

	for (int x = start + 1; x <= end; x++)
	{
		// Condition, if the element in array is less than the establish pivot, begin to swap elements to the left
		// Note that we are not sorting, we only care about moving all the values that are less than our pivot
		if (arr[x] < pivot)
		{
			swap(arr[pivotPosition + 1], arr[x]); // Takes the low value and moves it next to the current pivot location

			swap(arr[pivotPosition], arr[pivotPosition + 1]); // Swap the current location with the low value

			pivotPosition++; // Keeps moving the pivot, in a way it is moving it to the middle
		}
	}

	return pivotPosition;
}



// Quicksort function
// Will utilize the partition function
// This will break down the sublist and continue to partition them
void quickSort(int arr[], int start, int end)
{
	if (start < end)
	{
		int p = partition(arr, start, end); // Will return the pivot point location

		quickSort(arr, start, p - 1); // Now it will repeat the process for the elements to the left only

		quickSort(arr, p + 1, end); // Now it will repeat the process for the elements to the right only
	}
}


int main()
{
	const int size = 10;
	int test[size] = { 15, 53, 5, 2, 30, 1, 88, 64, 24, 3 };

	cout << "Original" << endl;
	for (int x = 0; x < size; x++)
	{
		cout << test[x] << " ";
	}

	quickSort(test, 0, size - 1);

	cout << endl << endl << "Quicksort" << endl;
	for (int x = 0; x < size; x++)
	{
		cout << test[x] << " ";
	}
	cout << endl;

	return 0;
}