/***********************************************************
The Game class will not be part of an is-a relation, but a has-a relation. 
The Game class will need to keep track of the type of dice for each
of the 2 players, the number of rounds to play, and some way to maintain the score.
************************************************************/

#ifndef WARGAME_H
#define WARGAME_H
#include "Die.h"
#include "LoadedDie2.h"
#include <string>
using namespace std;

class WarGame
{
	private:
		int rounds;
		int type1, type2;
		string player1;
		string player2;
		int* player1Scores;
		int* player2Scores;
		Die* dice;
		LoadedDie2* dice2;

	public:
		WarGame();
		~WarGame();
		void setSides(int);
		void setRounds(int);
		void setDiceType1(int);
		void setDiceType2(int);
		//string getPlayer1();
		//string getPlayer2();
		//int getRounds();
		//int getDiceType();
		void simulateGame();
		void display();
		void result();
};

#endif