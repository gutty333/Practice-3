#include "Room.h"

#ifndef HALLWAY_H
#define HALLWAY_H

class Hallway : public Room
{
public:
	Hallway(string, string);
	void simulate(Player*);
};

#endif