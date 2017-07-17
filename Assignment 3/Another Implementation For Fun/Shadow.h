#include "Creature.h"

#ifndef SHADOW_H
#define SHADOW_H

class Shadow : public Creature
{
public:
	Shadow();
	virtual void fight(Creature*, Creature*);
};

#endif
