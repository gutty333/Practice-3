#include "List.h"
#include <iomanip>

// Constructor
List::List()
{
	listTotal = 0;
}

// Add item method
// Will prompt the user to enter an item's information and add it to the list
// If the item is already in the list, it will not be added
void List::addItem()
{
	string name;
	int unit, amount;
	double price;

	// Prompts for the user
	cout << "What is the item name? ";
	cin >> name;


	// Condition to check that the new item is not included in the list already
	// Will use the operator overlord for ==
	// The left side represents our current object instance and the right represent a value string
	if (*this == name)
	{
		cout << endl << "Unable to add " << name << " to the list because it is already included" << endl;
		cout << "Please enter a different item" << endl;
		return;
	}


	cout << "What is the item unit of sale? ";
	cin >> unit;

	cout << "What is the item quantity? ";
	cin >> amount;

	cout << "What is the item unit price? ";
	cin >> price;

	// Creating the new item
	Item newItem(name, unit, amount, price);

	// Adding it to the list
	itemList.push_back(newItem);
}

// Remove item method
// Will showcase the user all the current items in the list and they can use which one to delete based on index selection
void List::removeItem()
{

	// check if there are any items in the list
	if (itemList.size() == 0)
	{
		cout << "There are no items on the list" << endl;
		cout << "Please add some items!" << endl;
	}
	else
	{
		cout << "Which item do you want to remove" << endl;
		int x;

		for (x = 0; x < itemList.size(); x++)
		{
			cout << x + 1 << ". " << itemList[x].getName() << endl;
		}
		int choice;
		cin >> choice;
		choice -= 1;

		// removing the selected item
		cout << "Removing " << itemList[choice].getName() << " from the list" << endl;
		itemList.erase(itemList.begin() + choice);
	}
}

// Display method which will the showcase the info of items in the list
// Will also calculate the total cost for all items in the list
void List::display()
{
	cout << fixed << setprecision(2) << endl;
	listTotal = 0;

	if (itemList.size() == 0)
	{
		cout << "Nothing to display, you have no items in your cart/list" << endl;
	}
	else
	{
		for (int x = 0; x < itemList.size(); x++)
		{
			itemList[x].printInfo();
			listTotal += itemList[x].getTotalPrice();
		}

		cout << "The cost of all items in our list is $" << listTotal << endl;
	}
}

// The operator overlord for the equal operator
bool List::operator==(string value)
{
	// Will compare the new item name entered by the user to the other items in our list
	
	for (int x = 0; x < itemList.size(); x++)
	{
		if (itemList[x].getName() == value)
		{
			return true;
		}
	}

	return false;
}