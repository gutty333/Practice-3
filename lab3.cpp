/***********************************************************
You realize that your dice-rolling program (from lab 1) may be more complicated than needed. There
is similarity between Die and LoadedDie. It would be better to use inheritance. You will create a
class hierarchy to show the inheritance of LoadedDie from Die.

For this assignment you will also need a Game class. The Game class will not be part of an is-a
relation, but a has-a relation. The Game class will need to keep track of the type of dice for each
of the 2 players, the number of rounds to play, and some way to maintain the score.

You will design a program to play a simplified version of war, using dice instead of cards. There
will be only one user, but 2 “players” for the game. You should give the user the option of setting
the number of sides on the dice used, if one player or both are using regular or loaded dice, and
the number of rounds to play. Your program will use the game class to determine which player won.
Your program should print out which player won to the user. To play a game, for each round you roll
a die of the appropriate type for each player. The higher result wins. If they are equal it is a
draw.
The winner of the game is the player who won the most rounds.
************************************************************/

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
