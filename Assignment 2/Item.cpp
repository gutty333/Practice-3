
#include "Item.h"

// Default Constructor
Item::Item()
{
	name = "";
	unit = quantity = price = 0;
}
// Constructor Overload
Item::Item(string n, int u, int total, double cost)
{
	name = n;
	unit = u;
	quantity = total;
	price = cost;
}

// Setter Functions
void Item::setName(string n)
{
	name = n;
}
void Item::setUnit(int u)
{
	unit = u;
}
void Item::setQuantity(int total)
{
	if (total < 0)
	{
		quantity = 0;
	}
	else
	{
		quantity = total;
	}
}
void Item::setPrice(double cost)
{
	price = cost;
}

// Getter Functions
string Item::getName()
{
	return name;
}
int Item::getUnit()
{
	return unit;
}
int Item::getQuantity()
{
	return quantity;
}
double Item::getPrice()
{
	return price;
}
// Total cost function
double Item::totalPrice()
{
	return quantity * price;
}