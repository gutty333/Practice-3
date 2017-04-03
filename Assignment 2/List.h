
#ifndef LIST_H
#define LIST_H
#include <vector>
#include "Item.h"

class List
{
	private:
		vector <Item> items;

	public:
		void addItem(Item);
		void removeItem(Item);
		void printList();
		void displayReport();
		bool operator==(Item);
};

#endif