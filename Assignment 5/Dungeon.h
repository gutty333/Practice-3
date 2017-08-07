#include "Room.h"

#ifndef DUNGEON_H
#define DUNGEON_H

class  Dungeon : public Room
{
public:
	Dungeon(string, string);
	void simulate(Player*);
};

#endif