
#include "GameDice.h"
#include <cstdlib>

// Default Constructor
GameDice::GameDice()
{
	sides = 6;
	diceNum = 1;
}
// Overload Constructor
GameDice::GameDice(int diceSides, int diceTotal)
{
	sides = diceSides;
	diceNum = diceTotal;
}
//Dice roll Function
int GameDice::roll()
{
	int total = 0;

	for (int x = 0; x < diceNum; x++)
	{
		total += rand() % sides + 1;
	}

	return total;
}