#include <iostream>
#include <string>
using namespace std;

#ifndef CREATURE_H
#define CREATURE_H


class Creature
{
	protected:
		string name;
		string type;
		int health;
		int armor;
		int defenseSides;
		int defenseRollCount;
		int attackSides;
		int attackRollCount;
		bool alive;
		bool specialAbility;
		int killCount;
		string teamName;
		int maxHealth;

	public:
		Creature();

		string getName();
		string getType();
		int getHealth();
		int getArmor();
		int getDefenseSides();
		int getDefenseRollCount();
		int getAttackSides();
		int getAttackRollCount();
		bool getAlive();
		bool getSpecialAbility();
		int getKillCount();
		string getTeamName();

		void setHealth(int);
		void setAlive(bool);
		void setName(string);
		void setTeamName(string);
		void updateKillCount();
		void printStats();
		

		virtual void combat(Creature*);
		
		virtual void healthRecovery();
};

#endif