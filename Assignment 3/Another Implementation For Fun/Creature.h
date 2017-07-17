#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


#ifndef CREATURE_H
#define CREATURE_H

class Creature
{
protected:
	//string name;
	string type;
	int health;
	int armor;
	int attackSides;
	int attackRolls;
	int defenseSides;
	int defenseRolls;
	int attackTotal;

public:
	Creature();

	//void setName(string);
	void setHealth(int);

	//string getName();
	string getType();
	int getHealth();
	int getArmor();
	int attack();
	int defense();

	void printInfo();
	virtual void fight(Creature*, Creature*);
};


#endif 