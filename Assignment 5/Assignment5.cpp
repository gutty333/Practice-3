#include <iostream>
#include <string>
#include <ctime>
#include "Player.h"
#include "Game.h"
using namespace std;

int main()
{
	srand(time(0));
	string name;
	Player* player = new Player;

	// Introduction and allowing the player to name their character
	cout << "Welcome Soldier" << endl;
	cout << "Please enter a name for you character" << endl;
	getline(cin, name);
	player->setName(name);

	Game castleGame(player);

	// Will create the map for the game
	castleGame.createMap();

	// Will simulate the game
	castleGame.playGame();

	return 0;
}