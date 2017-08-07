#include <iostream>
#include <string>
#include "Player.h"
#include "RoomStructure.h"
using namespace std;

#ifndef GAME_H
#define GAME_H

class Game
{
private:
	Player* player;
	room* head;

public:
	Game();
	Game(Player*);

	void setDeafult(room*);
	void createMap();
	void playGame();
};


#endif