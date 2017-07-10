/********************************************************************
Dynamic Queue Template

In this chapter you studied DynIntQueue, a class that implements a dynamic queue of
integers. Write a template that will create a dynamic queue of any data type. Demonstrate
the class with a driver program.
*********************************************************************/

#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class dynamicQueue
{
private:
	node* head;
	node* tail;

public:
	dynamicQueue();
	~dynamicQueue();
	void push(int);
	void pop();
	void front();
	void print();
	bool isEmpty();
};

dynamicQueue::dynamicQueue()
{
	head = tail = NULL;
}
dynamicQueue::~dynamicQueue()
{
	// freeing up any left over nodes
	while (head)
	{
		node* temp = head;

		head = head->next;

		delete(temp);
	}

	// fixing the tail pointer
	tail = NULL;
}
void dynamicQueue::print()
{
	if (isEmpty())
	{
		cout << "Nothing to print the list is empty" << endl;
	}
	else
	{
		node* current = head;

		while (current)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
}
bool dynamicQueue::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	return false;
}
void dynamicQueue::push(int value)
{
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;

	if (isEmpty())
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}
void dynamicQueue::pop()
{
	if (isEmpty())
	{
		cout << "nothing to remove, list is already empty" << endl;
	}
	else if (head->next == NULL)
	{
		node* temp = head;
		head = tail = NULL;
		delete(temp);
	}
	else
	{
		node* temp = head;
		head = head->next;
		delete(temp);
	}
}
void dynamicQueue::front()
{
	if (isEmpty())
	{
		cout << "nothing to retrieve, queue is empty" << endl;
	}
	else
	{
		cout << "The value is " << head->data << endl;
	}
}


int main()
{
	dynamicQueue queue;

	queue.print();

	queue.pop();

	queue.front();

	queue.push(23);
	queue.push(2);
	queue.push(14);
	queue.push(65);
	queue.push(27);
	queue.push(43);
	queue.push(98);
	queue.print();

	queue.pop();
	queue.pop();
	queue.print();
	queue.front();

	queue.push(57);
	queue.pop();
	queue.print();
	queue.front();

	queue.pop();
	queue.pop();
	queue.pop();
	queue.print();
	queue.push(3);
	queue.front();

	return 0;
}