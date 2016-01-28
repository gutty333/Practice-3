/********************************************************************
	Implement Conway’s  Game of Life

	You will design, implement, and test a program that runs the game of life. Conway’s Game of Life is
	a standard example of a cellular automaton. This means that you have an array or matrix of cells. 
	Each turn or generation the value of each cell may change based upon its neighbors. To get more 
	background look online, such as: http://en.wikipedia.org/wiki/Conway's_Game_of_Life Please do the 
	research so you understand the terms and how the rules are applied.

	Full description of assignment in Assignment1.pdf file.
*********************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include "Game.h"
using namespace std;

// NOT FINISHED 
int main()
{
	srand(time(0));
	string line;
	int choice, row, col;
	line.assign(50, '-');

	Game test;

	cout << "Conway's Game of Life" << endl;
	cout << line << endl;
	cout << "Choose a starting shape" << endl;
	cout << "1. Fixed Oscillator" << endl;
	cout << "2. Glider" << endl;
	cout << "3. Glider Cannon" << endl;
	cin >> choice;

	
	cout << endl;
	switch (choice)
	{
		case 1:
			cout << "Simulation for the Fixed Oscillator" << endl;

			cout << "Do you want to set the starting location for the shape (Y/N) ";
			char answer;
			cin >> answer;

			if (toupper(answer) == 'Y')
			{
				cout << "Set the starting location for this shape" << endl;
				cout << "Set the row (0-39): ";
				cin >> row;
				cout << "Set the column (0-19): ";
				cin >> col;

				test.setLocation(row, col);
				
			}
			else
			{
				cout << "Random Location" << endl;
				test.randomStart();
			}
			
			test.getWorld();
			break;


		case 2:
			cout << "Simulation for the Glider" << endl;
			break;


		case 3:
			cout << "Simulation for the Glider Cannon" << endl;
			break;

		default:
			cout << "Invalid Input" << endl;
	}


	return 0;
}