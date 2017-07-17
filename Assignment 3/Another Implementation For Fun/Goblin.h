#include "Creature.h"

#ifndef GOBLIN_H
#define GOBLIN_H


class Goblin : public Creature
{
private:
	bool achilles;
public:
	Goblin();
	void setAchilles(bool);
	bool getAchilles();
	virtual void fight(Creature*,Creature*);
};


#endif