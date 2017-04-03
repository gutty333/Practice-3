
#include "List.h"
#include <iostream>
using namespace std;

// Add Item Function
void List::addItem(Item itemTemp)
{
	items.push_back(itemTemp);
}

// Remove Item Function
void List::removeItem(Item itemTemp)
{
	int size = items.size();
	int index = 0;
	bool found=false;

	for (int x = 0; x < size; x++)
	{
		if (itemTemp.getName() == items[x].getName())
		{
			index = x;
			found = true;
		}
	}

	if (size == 0)
	{
		cout << "There are no items to remove from the list" << endl;
	}
	else if (found)
	{
		items.erase(items.begin() + index);
		cout << "The item, " << itemTemp.getName() << " was removed from the list" << endl;
	}
	else
	{
		cout << "The item, " << itemTemp.getName() << " is not on the list" << endl;
	}
}

// Print List method, will only show the item names to the user
void List::printList()
{
	int size = items.size();

	for (int x = 0; x < size; x++)
	{
		cout << x + 1 << ". " << items[x].getName() << endl;
	}
}

// Display Report Function, this will display all the information to the user
void List::displayReport()
{
	double total = 0;
	int size = items.size();

	for (int x = 0; x < size; x++)
	{
		cout << "Name: " << items[x].getName() << endl;
		cout << "Unit: " << items[x].getUnit() << endl;
		cout << "Quantity: " << items[x].getQuantity() << endl;
		cout << "Price : $" << items[x].getPrice() << endl << endl;

		total += items[x].totalPrice();
	}

	cout << "The total price of all the items in the list is $" << total << endl;
}


// == Operator Overload Function
bool List::operator==(Item b)
{
	int size = items.size();

	for (int x = 0; x < size; x++)
	{
		if (items[x].getName() == b.getName())
		{
			return true;
		}
	}

	return false;
}
