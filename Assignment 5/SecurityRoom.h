#include "Room.h"

#ifndef SECURITYROOM_H
#define SECURITYROOM_H

class  SecurityRoom: public Room
{
public:
	SecurityRoom(string, string);
	void simulate(Player*);
};

#endif