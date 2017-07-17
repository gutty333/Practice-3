#include <iostream>
#include <string>
using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
	string name;
	int unit;
	int amount;
	double price;

public:
	Item();
	Item(string, int, int, double);

	void setName(string);
	void setUnit(int);
	void setAmount(int);
	void setPrice(double);

	string getName();
	int getUnit();
	int getAmount();
	double getPrice();
	double getTotalPrice();

	void printInfo();
};

#endif