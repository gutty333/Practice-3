#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
private:
	vector <Item> list;

public:
	Inventory();
	void addItem(Item);
	void removeItem(string);
	void showItems();
	void showItemMenu();

	int getSize();
	bool searchItem(string);
	Item getItem(int);
};

#endif