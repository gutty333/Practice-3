/********************************************************************
	Game class, this class will be used to show the world to the player.
	
	Properties:
	

	Operations:
	Create an grid of 40 rows and 20 columns
	Showcase the initial world(Empty)
	Each element in the array will represent the cells
	In the beginning all the elements will be dead
	Check the rules, if a cells meets the requirements, change it to dead or alive
	Update the simulation

*********************************************************************/
#ifndef GAME_H
#define GAME_H

class Game
{
	private:
		char dead;
		char alive;
		char world[40][20];

	public:
		Game();
		bool checkDead();
		bool checkAlive();
		void getWorld();
		void simulation();
		
		void randomStart();
		void setLocation(int, int);

		void oscillator();
		void glider();
		void gliderCannon();
};

#endif