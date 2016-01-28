
#include <iostream>
#include <cstdlib>
using namespace std;
#include "Game.h"


Game::Game()
{
	dead = '-';
	alive = 'o';


	for (int row = 0; row < 40; row++)
	{
		for (int col = 0; col < 20; col++)
		{
			world[row][col] = dead;
		}
	}
}


void Game::getWorld()
{
	for (int row = 0; row < 40; row++)
	{
		for (int col = 0; col < 20; col++)
		{
			cout << world[row][col];
		}
		cout << endl;
	}
}


void Game::randomStart()
{
	int row = rand() % 40;
	int col = rand() % 20;

	world[row][col] = alive;
}



void Game::setLocation(int row, int col)
{
	world[row][col] = alive;

}

void Game::oscillator()
{
	


}