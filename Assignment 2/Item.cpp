#include "Item.h"

// Constructors
Item::Item()
{
	name = "";
	amount = unit = price = 0;
}
Item::Item(string n, int u, int a, double p)
{
	setName(n);
	setUnit(u);
	setAmount(a);
	setPrice(p);
}

// Setter methods
void Item::setName(string n)
{
	name = n;
}
void Item::setUnit(int u)
{
	unit = u;
}
void Item::setAmount(int a)
{
	if (a < 0)
	{
		amount = 0;
	}
	else
	{
		amount = a;
	}
}
void Item::setPrice(double p)
{
	price = p;
}

// Getter methods
string Item::getName()
{
	return name;
}
int Item::getUnit()
{
	return unit;
}
int Item::getAmount()
{
	return amount;
}
double Item::getPrice()
{
	return price;
}
double Item::getTotalPrice()
{
	return amount * price;
}

// print info method
void Item::printInfo()
{
	cout << "Name: " << name << endl;
	cout << "Unit: " << unit << endl;
	cout << "Total: " << amount << endl;
	cout << "Price: $" << price << endl;
	cout << "Total Price: $" << getTotalPrice() << endl << endl;
}