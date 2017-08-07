#include <iostream>
#include <string>
using namespace std;

#ifndef ITEM_H
#define ITEM_H


class Item
{
private:
	string name;
	string description;
	int value;
	bool perk;
	bool weapon;
	bool armor;

public:
	Item();
	Item(string, string, int,bool,bool,bool);
	Item(const Item&);

	string getName();
	string getDescription();
	int getValue();
	bool isPerk();
	bool isArmor();
	bool isWeapon();

	void displayInfo();
};

#endif