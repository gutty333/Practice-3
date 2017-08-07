#include "Inventory.h"

Inventory::Inventory(){}

// Add Item function
void Inventory::addItem(Item temp)
{
	cout << "Adding a " << temp.getName() << " to your inventory" << endl;

	list.push_back(temp);
}

// Remove Item  function
void Inventory::removeItem(string target)
{
	cout << "Removing " << target << " from your inventory" << endl;

	for (int x = 0; x < list.size(); x++)
	{
		if (list[x].getName() == target)
		{
			list.erase(list.begin() + x);
			return;
		}
	}
}

// Display Items function
void Inventory::showItems()
{
	for (int x = 0; x < list.size(); x++)
	{
		list[x].displayInfo();
	}
}
void Inventory::showItemMenu()
{
	for (int x = 0; x < list.size(); x++)
	{
		cout << x << ". " << list[x].getName() << endl;
	}
}

// Will return the size of our list
int Inventory::getSize()
{
	return list.size();
}


// Search Item method will perform a regular linear search to find the target item
bool Inventory::searchItem(string target)
{
	for (int x = 0; x < list.size(); x++)
	{
		if (list[x].getName() == target)
		{
			return true;
		}
	}

	return false;
}

// Will return the item selected by the user
Item Inventory::getItem(int index)
{
	return list[index];
}