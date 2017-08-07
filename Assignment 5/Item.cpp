#include "Item.h"

// Constructors
Item::Item()
{
	name = description = "";
	value = 0;
	perk = armor = weapon = false;
}
Item::Item(string n, string d, int v, bool p, bool w, bool a)
{
	name = n;
	description = d;
	value = v;
	perk = p;
	weapon = w;
	armor = a;
}
Item::Item(const Item& copy)
{
	name = copy.name;
	description = copy.description;
	value = copy.value;
	perk = copy.perk;
	armor = copy.armor;
	weapon = copy.weapon;
}

// Getter Functions
string Item::getName()
{
	return name;
}
string Item::getDescription()
{
	return description;
}
int Item::getValue()
{
	return value;
}
bool Item::isArmor()
{
	return armor;
}
bool Item::isPerk()
{
	return perk;
}
bool Item::isWeapon()
{
	return weapon;
}



// Display Function
void Item::displayInfo()
{
	cout << endl << "Name: " << name << endl;
	cout << "Description: " << description << endl;
	if (value == 0)
	{
		cout << "Item does not have a numeric value" << endl;
	}
	else
	{
		cout << "Value: " << value << endl;
	}
	cout << endl;
}