#include <iostream>
#include <string>
using namespace std;

/*
Parent character class
This will represent both the player character and the enemies the player will encounter
*/

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{

protected:
	string name;
	bool alive;
	int health;
	int attack;
	int defense;
	
	// Help determine who calls the fight method
	// The caller acts as the attacker
	// Turn will allow us to change the roles from attacker to defender by having a different caller each iteration
	bool turn; 


public:
	Character();
	
	void setName(string);
	void updateHealth(int);
	void setTurn(bool);

	string getName();
	bool getAlive();
	bool getTurn();
	int getHealth();
	int getAttack();
	int getDefense();
	
	void displayStats();
	virtual void fighSimulation(Character*);
};


#endif 