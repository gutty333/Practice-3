#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;


// Simple linear search
// Will iterate through each value of the file until target value is found
void search(istream& file, int target)
{
	// Verify the file can open
	if (!file)
	{
		cout << "Unable to locate file" << endl;
		return;
	}

	int count = 0;
	int temp;

	while (file >> temp)
	{
		if (temp == target)
		{
			cout << "The target value of " << target << " was found" << endl;
			cout << "It took " << count << " step/steps" << endl;
			return;
		}
		count++;
	}

	cout << "The target value of " << target << " was not found" << endl;
	cout << "It took " << count << " step/steps" << endl;
}

// Binary search method used to analyze any of the sorted files
void search2(istream& file, int target)
{
	// Verify the file can open
	if (!file)
	{
		cout << "Unable to locate file" << endl;
		return;
	}

	int count = 0;
	vector <int> list;
	int value;
	// Storing the values from the file
	while (file >> value)
	{
		list.push_back(value);
	}


	int start = 0;
	int end = list.size();

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (list[mid] == target)
		{
			cout << "The target value of " << target << " was found" << endl;
			cout << "It took " << count << " step/steps" << endl;
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

		count++;
	}

	cout << "The target value of " << target << " was not found" << endl;
	cout << "It took " << count << " step/steps" << endl;
}


// Sort method which will take any of the original files and sort their value in ascending order
void sort(istream& file, string name)
{
	ofstream sortFile(name);
	vector <int> list;

	// First read the file and store the values
	int value;
	while (file >> value)
	{
		list.push_back(value);
	}

	// Now sorting the values using a bubble sort implementation
	for (int current = 0; current < list.size() - 1; current++)
	{
		int minIndex = current;

		for (int x = current + 1; x < list.size(); x++)
		{
			if (list[minIndex] > list[x])
			{
				minIndex = x;
			}
		}

		if (minIndex != current)
		{
			int temp = list[current];
			list[current] = list[minIndex];
			list[minIndex] = temp;
		}
	}

	// writing the sorted file
	for (int x = 0; x < list.size(); x++)
	{
		sortFile << list[x] << endl;
	}

	sortFile.close();
}


int main()
{
	srand(time(0));
	ofstream original("original.txt");
	ofstream early("early.txt");
	ofstream middle("middle.txt");
	ofstream end("end.txt");

	// Loop to fill files with random values
	/*
		will take care of all 4 files inside here
		the other option is creating one than manually copying and inserting the 0
		this loop will create all 4 sharing the same random values as if they were a copy
		with the exception of adding the value 0 at various locations
	*/
	for (int x = 0; x < 20; x++)
	{
		int value = rand() % 100 + 1;

		// Condition to insert the 0 at various locations
		if (x == 0)
		{
			early << 0 << endl;
		}
		else if (x == 10)
		{
			middle << 0 << endl;
		}
		
		original << value << endl;
		early << value << endl;
		middle << value << endl;
		end << value << endl;

		if (x == 19)
		{
			end << 0 << endl;
		}
	}

	original.close();
	early.close();
	middle.close();
	end.close();


	// List to keep track of the user created files
	vector <string> userFiles;
	
	int choice;
	cout << "Welcome to Lab 7" << endl;
	cout << "The 4 files have been created" << endl;
	do
	{
		cout << endl << "What action would you like to do" << endl;
		cout << "1. Search for the value 0" << endl;
		cout << "2. Create files with the values sorted" << endl;
		cout << "3. Search for a target value using binary search" << endl;

		cin >> choice;

		if (choice == 1)
		{
			ifstream original("original.txt");
			cout << "Results for the original.txt file" << endl;
			search(original, 0);

			ifstream early("early.txt");
			cout << endl << "Results for the early.txt file" << endl;
			search(early, 0);

			ifstream middle("middle.txt");
			cout << endl << "Results for the middle.txt file" << endl;
			search(middle, 0);

			ifstream end("end.txt");
			cout << endl << "Results for the end.txt file" << endl;
			search(end, 0);

			original.close();
			early.close();
			middle.close();
			end.close();
		}
		else if (choice == 2)
		{
			string fileName;

			// Sorting the original file
			cout << "Provide a name for a new file sorting the original.txt file" << endl;
			cin >> fileName;
			fileName += ".txt";
			userFiles.push_back(fileName);
			ifstream original("original.txt");
			sort(original, fileName);

			// Sorting the second file
			cout << endl << "Provide a name for a new file sorting the early.txt file" << endl;
			cin >> fileName;
			fileName += ".txt";
			userFiles.push_back(fileName);
			ifstream early("early.txt");
			sort(early, fileName);

			// Sorting the third file
			cout << endl << "Provide a name for a new file sorting the middle.txt file" << endl;
			cin >> fileName;
			fileName += ".txt";
			userFiles.push_back(fileName);
			ifstream middle("middle.txt");
			sort(middle, fileName);

			// Sorting the last file
			cout << endl << "Provide a name for a new file sorting the end.txt file" << endl;
			cin >> fileName;
			fileName += ".txt";
			userFiles.push_back(fileName);
			ifstream end("end.txt");
			sort(end, fileName);

			cout << endl << "The new sorting files have been created" << endl;
			original.close();
			early.close();
			middle.close();
			end.close();
		}
		else if (choice == 3)
		{
			cout << "Pick a number from 0-100" << endl;
			int target;
			cin >> target;

			ifstream original(userFiles[0]);
			cout << endl << "Results for the " << userFiles[0] << " file" << endl;
			search2(original, target);

			ifstream early(userFiles[1]);
			cout << endl << "Results for the " << userFiles[1] << " file" << endl;
			search2(early, target);

			ifstream middle(userFiles[2]);
			cout << endl << "Results for the " << userFiles[2] << " file" << endl;
			search2(middle, target);

			ifstream end(userFiles[3]);
			cout << endl << "Results for the " << userFiles[3] << " file" << endl;
			search2(end, target);

			original.close();
			early.close();
			middle.close();
			end.close();
		}
		else
		{
			cout << "Please enter a valid input" << endl;
		}

		cout << endl << "Try another action? 0 = no  1 = yes" << endl;
		cin >> choice;
	}while (choice);

	return 0;
}