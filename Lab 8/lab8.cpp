#include <iostream>
#include "Queue.h"
using namespace std;


int main()
{
	Queue list;

	list.print();
	list.getFront();

	list.addBack(12);
	list.addBack(4);
	list.addBack(32);
	list.addBack(56);
	list.addBack(7);
	list.addBack(8);
	list.print();
	list.getFront();

	list.addBack(29);
	list.print();

	list.removeFront();
	list.print();
	list.getFront();

	list.removeFront();
	list.removeFront();
	list.removeFront();
	list.print();

	list.removeFront();
	list.removeFront();
	list.removeFront();
	list.removeFront();

	list.addBack(98);
	list.getFront();
	
	list.addBack(103);
	list.addBack(84);
	list.addBack(1);
	list.print();
	return 0;

}