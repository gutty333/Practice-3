
#ifndef GAMEDICE_H
#define GAMEDICE_H

class GameDice
{
	private:
		int sides;
		int	diceNum;


	public:
		GameDice();
		GameDice(int, int);
		int roll();
};

#endif