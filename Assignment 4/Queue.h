#include <iostream>
#include "Creature.h"

#ifndef QUEUE_H
#define QUEUE_H

struct node
{
	Creature* data;
	node* next;
};

class Queue
{
private:
	node* head;
	node* tail;
	int queueSize;

public:
	Queue();
	~Queue();
	void add(Creature*);
	void remove();
	Creature* front();
	void display();
	bool isEmpty();
	int getSize();
};

#endif