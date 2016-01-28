/********************************************************************
	Lab 1 Program

	You will create a program that uses two classes. Each class will be in a separate source file with
	an appropriate header file. The first class is Die. It will have a data member to indicate the
	number of sides. It will have a member function that returns the value of a single roll of a single
	die. The second class will be LoadedDie. It will also have a single data member that indicates the
	number of sides. It will have a member function that returns the value of a single roll of a single
	die. In this case it should return values that are higher than normal. You can’t just add one to
	the roll. Getting a 7 on a 6-sided die stands out!

	HINT: This is a programming assignment. You do not want to make the shift too subtle as that can
	make testing difficult.

	In a fifth file you will create a program that rolls each die N times. You should print the result
	of each roll to the screen as well as the total of the N rolls of each die. Is your loaded die
	returning higher values on average?

	Once your program is working and you have eliminated the bugs create a makefile to build your
	program. You do not need a complicated makefile. You can have a single target that just includes
	what you typed into the command line for testing.
*********************************************************************/
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