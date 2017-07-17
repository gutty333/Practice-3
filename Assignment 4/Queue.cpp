#include "Queue.h"

// Constructor 
Queue::Queue()
{
	head = tail = NULL;
	queueSize = 0;
}

// Destructor
Queue::~Queue()
{
	while (head)
	{
		remove();
	}
}

// Is Empty method
bool Queue::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	return false;
}

// Print method 
void Queue::display()
{
	if (isEmpty())
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		node* current = head;

		while (current)
		{
			current->data->printStats();

			current = current->next;
		}
	}
}

// Add method
void Queue::add(Creature* selectedCreature)
{
	node* temp = new node;
	temp->data = selectedCreature;
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

// Remove method
void Queue::remove()
{
	if (isEmpty())
	{
		cout << "Queue is already empty" << endl;
	}
	else if (head->next == NULL)
	{
		node* temp = head;

		head = tail = NULL;

		delete (temp);
	}
	else
	{
		node* temp = head;

		head = head->next;

		delete (temp);
	}
}

// Front method
Creature* Queue::front()
{
	return head->data;
}

// Get size method 
int Queue::getSize()
{
	queueSize = 0;

	node* current = head;

	while (current)
	{
		queueSize++;
		current = current->next;
	}

	return queueSize;
}