#include "Item.h"
#include <vector>

#ifndef LIST_H
#define LIST_H

class List
{
private:
	double listTotal;
	vector <Item> itemList;

public:
	List();
	void addItem();
	void removeItem();
	void display();
	bool operator==(string);
};


#endif 