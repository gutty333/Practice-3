#include "Room.h"

#ifndef CASTLETOWER_H
#define CASTLETOWER_H

class  CastleTower : public Room
{
public:
	CastleTower(string, string);
	void simulate(Player*);
};

#endif