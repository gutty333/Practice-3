#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "Die.h"
#include "LoadedDie2.h"
#include "WarGame.h"
using namespace std;

int main()
{
	// Random Seeding
	srand(time(NULL));

	string line;
	int sides, diceType, rounds;
	char choice;
	line.assign(50, '-');

	do
	{
		WarGame test;

		cout << "Welcome to the Game of War" << endl;
		cout << line << endl;
		cout << "What is the number of sides each player will use? ";
		cin >> sides;

		// Apply the number of sides for the dice
		test.setSides(sides);

		for (int x = 0; x < 2; x++)
		{
			cout << "What type of dice will player " << x + 1 << " use? " << endl;
			cout << "1. Regular Dice" << endl;
			cout << "2. Loaded Dice" << endl;
			cin >> diceType;
			cout << endl;

			// Apply the dice type the players are using
			if (x == 0)
			{
				test.setDiceType1(diceType);
			}
			else
			{
				test.setDiceType2(diceType);
			}
		}

		cout << "How many rounds do you want the players to play? ";
		cin >> rounds;

		// Apply the round numbers to the object
		test.setRounds(rounds);

		// Simulate the game
		test.simulateGame();

		// Show the results to the user
		test.display();

		// Report who won, or whether it ended in a tie
		test.result();

		cout << "Do you want to run the game again? (Y/N) ";
		cin >> choice;
		cout << endl;
	} while (toupper(choice) == 'Y');
	
	return 0;
}
