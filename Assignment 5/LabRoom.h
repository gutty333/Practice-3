#include "Room.h"

#ifndef LABROOM_H
#define LABROOM_H

class  LabRoom : public Room
{
public:
	LabRoom(string, string);
	void simulate(Player*);
};

#endif