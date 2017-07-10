#ifndef QUEUE_H
#define QUEUE_H

struct node
{
	int data;
	node* next;
	node* prev;
};

class Queue
{
private:
	node* head;
	node* tail;

public:
	Queue();
	~Queue();
	void addBack(int);
	void getFront();
	void removeFront();
	bool isEmpty();
	void print();
};

#endif 