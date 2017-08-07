#include <iostream>
#include <string>
#include "Character.h"
#include "Player.h"
#include "Item.h"
using namespace std;


#ifndef ROOM_H
#define ROOM_H

class Room
{
protected:
	string name;
	string description;
	Room* up;
	Room* down;
	Room* left;
	Room* right;
public:
	Room();
	Room(string, string);

	string getName();
	string getDescription();

	void displayRoomInfo();
	virtual void simulate(Player*) = 0;
};

#endif