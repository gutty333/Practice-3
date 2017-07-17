#include <iostream>
#include <string>
using namespace std;

#ifndef CREATURE_H
#define CREATURE_H


class Creature
{
	protected:
		string name;
		int health;
		int armor;
		int defenseSides;
		int defenseRollCount;
		int attackSides;
		int attackRollCount;
		bool alive;
		bool specialAbility;

	public:
		Creature();

		string getName();
		int getHealth();
		int getArmor();
		int getDefenseSides();
		int getDefenseRollCount();
		int getAttackSides();
		int getAttackRollCount();
		bool getAlive();
		bool getSpecialAbility();

		void setHealth(int);
		void setAlive(bool);

		virtual void combat(Creature*);
};

#endif