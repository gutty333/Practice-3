#include <iostream>
#include <string>
#include "Room.h"
using namespace std;

struct room
{
	Room* currentRoom;
	bool completed;

	room* left;
	room* right;
	room* up;
	room* down;
};