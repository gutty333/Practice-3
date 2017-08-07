#include "Room.h"

#ifndef STARTINGROOM_H
#define STARTINGROOM_H

class StartingRoom : public Room
{
public:
	StartingRoom(string, string);
	void simulate(Player*);
};

#endif