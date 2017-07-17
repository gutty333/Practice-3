#include "WarGame.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Default Constructor
WarGame::WarGame()
{
	rounds = 0;
	player1 = "Player 1";
	player2 = "Player 2";
	type1 = 0;
	type2 = 0;
}
// Destructor
WarGame::~WarGame()
{
	// freeing up the memory 
	delete dice;
	delete dice2;
	delete[] player1Scores;
	delete[] player2Scores;
}


// Setter Functions
void WarGame::setRounds(int roundTotal)
{
	rounds = roundTotal;
	player1Scores = new int[roundTotal];
	player2Scores = new int[roundTotal];
}
void WarGame::setSides(int sideTotal)
{
	/*Die temp(sideTotal);
	dice = temp;
	LoadedDie2 temp2(sideTotal);
	dice2 = temp2;*/

	dice = new Die(sideTotal);
	dice2 = new LoadedDie2(sideTotal);
}
void WarGame::setDiceType1(int diceType)
{
	type1 = diceType;
}
void WarGame::setDiceType2(int diceType)
{
	type2 = diceType;
}

// Simulate Game Function
void WarGame::simulateGame()
{
	for (int x = 0; x < rounds; x++)
	{
		if (type1 == 1)
		{
			player1Scores[x] = dice->roll();
		}
		else if (type1 == 2)
		{
			player1Scores[x] = dice2->rollLoaded();
		}

		if (type2 == 1)
		{
			player2Scores[x] = dice->roll();
		}
		else if (type2 == 2)
		{
			player2Scores[x] = dice2->rollLoaded();
		}
	}
}

// Display
void WarGame::display()
{
	for (int x = 0; x < rounds; x++)
	{
		cout << "Round " << x + 1 << endl;
		cout << player1 << ": " << player1Scores[x] << endl;
		cout << player2 << ": " << player2Scores[x] << endl;
		cout << endl;
	}
}

// Result Function
void WarGame::result()
{
	int player1Wins = 0;
	int player2Wins = 0;

	for (int x = 0; x < rounds; x++)
	{
		if (player1Scores[x]> player2Scores[x])
		{
			player1Wins++;
		}
		else if (player2Scores[x] > player1Scores[x])
		{
			player2Wins++;
		}
	}

	if (player1Wins > player2Wins)
	{
		cout << player1 << " has won the game, congratulations" << endl;
	}
	else if (player2Wins > player1Wins)
	{
		cout << player2 << " has won the game, congratulations" << endl;
	}
	else
	{
		cout << "The game ended in a tie" << endl;
	}
}