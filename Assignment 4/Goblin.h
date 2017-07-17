#include "Creature.h"

#ifndef GOBLIN_H
#define GOBLIN_H

class Goblin :public Creature
{
public:
	Goblin();
	virtual void combat(Creature*);
};

#endif