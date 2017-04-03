// Creature base class
// Will be an abstract class

#ifndef CREATURE_H
#define CREATURE_H
#include "GameDice.h"
#include <string>
using namespace std;

class Creature
{
	protected:
		string type;
		int armor;
		int health;
		int attackSides, attackDice;
		int defenseSides, defenseDice;
		bool achilles;

	public:
		Creature();
		int getAttack();
		int getDefense();
		int getArmor();
		void updateHealth(int);
		int getHealth();
		string getType();
		void setAchilles(bool);
		bool getAchilles();
};

#endif