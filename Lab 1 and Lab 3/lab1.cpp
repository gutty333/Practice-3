#include <iostream>
#include <ctime>
#include "Die.h"
#include "LoadedDie.h"
using namespace std;

void display(int array[], int size)
{
	int total = 0;

	for (int x = 0; x < size; x++)
	{
		cout << "Roll " << x+1 <<  " is: " << array[x] << endl;
		total += array[x];
	}

	cout << "The total is: " << total << endl;
}

int main()
{
	srand(time(0));

	cout << "How many side will the Die have? ";
	int sides;
	cin >> sides;

	Die dieObj(sides);

	cout << "How many times do you want to roll the Die? ";
	int roll;
	cin >> roll;

	int* rolls = new int[roll];

	for (int x = 0; x < roll; x++)
	{
		rolls[x] = dieObj.roll();
	}

	cout << "Results:" << endl;
	display(rolls, roll);
	

	cout << endl << endl << "How many side will the LoadedDie have? ";
	cin >> sides;

	LoadedDie dieObj2(sides);

	cout << "How many times do you want to roll the LoadedDie? ";
	cin >> roll;

	rolls = new int[roll];

	for (int x = 0; x < roll; x++)
	{
		rolls[x] = dieObj2.roll();
	}

	cout << "Results:" << endl;
	display(rolls, roll);
	
	delete[] rolls;
	rolls = 0;

	return 0;
}