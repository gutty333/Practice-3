#include "Room.h"

#ifndef ARMORY_H
#define ARMORY_H

class Armory : public Room
{
public:
	Armory(string, string);
	void simulate(Player*);
};

#endif