/********************************************************************
	You need to design, implement, and test a grocery shopping list program. The program
	should maintain and display a list of items.

	You will use a class for the Items.  The class should have data elements for the following 
	information: item name, unit (i.e. can, box, pounds, or ounces), number to buy, and unit price.  Do 
	you need any functions other than the constructor(s)?  How do you calculate the extended price for 
	the item (number to by times unit price?  How do you print it to the screen?

	You will also need a List class. You will store Item objects in your List object.  As each item is 
	entered an Item object must created and added to the List object. One List object may have many 
	Item objects.  Do you need a print function in this class?

	Your program must perform the following activities: create a list, add items, remove items, and 
	display the shopping list. To add an item you should prompt the user to enter the name, unit of 
	sale, the number needed, and the unit price. The display should show: each item in the list, the 
	number of items, the unit of sale, the unit price, the extended price for each item, and the total 
	price for all items. Oregon doesn’t have a sales tax so you can ignore that. Debug and test your 
	program.

	Once you have the List and Item classes working correctly, test if an item is already in
	your List before adding it. Overload the == operator to perform the test. There is a simple example
	to overload this operator in the book. Keep it simple. How will you compare items? You can assume
	that the user will type the information in correctly.
*********************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "List.h"
#include "Item.h"
using namespace std;

int main()
{
	cout << fixed << setprecision(2);
	string name;
	string line;
	line.assign(50, '-');
	int unit, total, choice;
	char choice2;
	double price;

	List bag;

	cout << "Welcome to the shop" << endl;
	cout << line << endl;
	do
	{
		cout << "What options do you want to make" << endl;
		cout << "\t 1. Add Items" << endl;
		cout << "\t 2. Remove Items" << endl;
		cout << "\t 3. View Current Items" << endl;
		cout << "\t 4. Exit" << endl;
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
			case 1:
			{
				cout << endl << "What is the name of item you want to add: ";
				getline(cin, name);
				cout << "What is the unit for this item: ";
				cin >> unit;
				cout << "What is the total/quantity for this item: ";
				cin >> total;
				cout << "What is cost of this item: ";
				cin >> price;
				Item product(name, unit, total, price);
				if (bag.operator==(product))
				{
					cout << "Sorry that item is already in the list" << endl;
				}
				else
				{
					bag.addItem(product);
				}
				break;
			}

			case 2:
			{
				cout << endl << "Which item do you want to remove from the list (Enter Item Name): ";
				getline(cin, name);
				Item product2;
				product2.setName(name);
				bag.removeItem(product2);
				break;
			}

			case 3:
			{
				cout << endl << "Here are the items you currently have in your list/bag" << endl;
				bag.printList();
				break;
			}

			case 4:
			{
				cout << endl << "Thank you for shopping, here is the report" << endl;
				bag.displayReport();
				break;
			}

			default:
				cout << endl << "Invalid input" << endl;
		}
		cout << endl;
	} while (choice != 4);
	

	return 0;
}