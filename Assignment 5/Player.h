#include "Character.h"
#include "Inventory.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Character
{
private:
	Inventory playerInventory;
	bool victory;

public:
	Player();

	void setName(string);
	void improveAttack(int);
	void improveHealth(int);
	void improveDefense(int);
	void setVictory(bool);

	void addItem(Item);
	void dropItem(string);

	
	void viewItems();
	void useItem(Item);
	void useItemMenu();
	bool searchItem(string);
	int getInventorySize();
	bool getVictory();
};

#endif