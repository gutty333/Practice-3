#include <iostream>
#include "List.h"


int main()
{
	List cart;
	int choice;
	cout << "Welcome to the store" << endl;

	do
	{
		// Menu
		cout << endl << "Please select and option" << endl;
		cout << "1. Add Item" << endl;
		cout << "2. Remove Item" << endl;
		cout << "3. Display Items" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;

		// Condition to implement the operations
		switch (choice)
		{
			case 1:
			{
				cout << endl << "Adding an Item" << endl;
				cart.addItem();
				break;
			}
			case 2:
			{
				cout << endl << "Removing an Item" << endl;
				cart.removeItem();
				break;
			}
			case 3:
			{
				cout << endl << "Displaying the Item/Items" << endl;
				cart.display();
				break;
			}
			case 4:
			{
				cout << endl << "Thank for shopping" << endl;
				break;
			}
			default:
			{
				cout << "Invalid Input" << endl;
			}
		}
	} while (choice != 4);



	return 0;
}