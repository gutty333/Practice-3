// Combat Class
// Will simulate combat and keep track of stats

#ifndef COMBAT_H
#define COMBAT_H
#include "Creature.h"

class Combat
{
	public:
		void fight(Creature*, Creature*);
		bool alive(Creature*);
};

#endif