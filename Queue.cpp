#include <iostream>
#include "Queue.h"
using namespace std;

// Constructor will set both head and tail to NULL
Queue::Queue()
{
	head = tail = NULL;
}
// Destructor will free up all the nodes
Queue::~Queue()
{
	// When there is only a single node in the queue
	if (head->next == head)
	{
		node* temp = head;
		head = tail = NULL;
		delete (temp);
	}
	else
	{
		// Will signal the last node of our circular queue
		node* end = head->prev;

		// We traverse the circular queue 
		// Since one of the restriction is to not delete any of the nodes our starting location in the circle can be anywhere
		// We store the previous node the head points to since this lets us know when we fully traversed the circle
		while (head)
		{
			node* temp = head;
			head = head->next;
			delete (temp);

			// condition to end loop
			if (head == end)
			{
				node* temp = head;
				head = tail = NULL;
				delete temp;
			}
		}
	}
	
}
// Print method
void Queue::print()
{
	node* current = head;

	if (isEmpty())
	{
		cout << "nothing to print, the queue is empty" << endl;
	}
	else
	{
		while (current)
		{
			cout << current->data << " ";

			// base case to avoid an infinite loop due to the queue being circular and no null terminators
			if (current == tail)
			{
				break;
			}
			else
			{
				current = current->next;
			}
		}

		cout << endl;
	}
}
// isEmpty method
bool Queue::isEmpty()
{
	// Since we cannot physically remove any nodes until end of the program
	// The value -1 signals an empty node
	if (head == NULL || head->data == -1)
	{
		return true;
	}
	return false;
}
// get front method
void Queue::getFront()
{
	if (isEmpty())
	{
		cout << "The queue is empty nothing to retrieve" << endl;
	}
	else
	{
		cout << "The front value is " << head->data << endl;
	}
}
// remove front method
void Queue::removeFront()
{
	if (isEmpty())
	{
		cout << "The queue is empty nothing to remove" << endl;
	}
	else
	{
		// We set the current front node to empty (value = -1)
		// Than we update the head pointer
		head->data = -1;

		
		// This it to prevent the head from going back to the start
		// Essentially it will leave the head as the last node
		if (head->next->data != -1)
		{
			head = head->next;
		}
		
	}
}
// add back method
void Queue::addBack(int value)
{
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;
	temp->prev = NULL;


	if (head == NULL)
	{
		head = tail = temp;

		// Fixing the links since we cannot have NULL Pointers
		// Also every next and previous pointer will point to a node
		tail->next = head;
		head->prev = tail;
	}
	else if (head->data == -1)
	{
		node* temp2 = tail->next;
		
		// rearranging the links
		temp->next = temp2;
		tail->next = temp;
		temp->prev = tail;
		temp2->prev = temp;

		// updating head and tail
		// We update head since the current head node resembles a node that has been removed
		head = tail = temp;
	}
	else
	{
		// Update the tail pointer and fix the next and previous pointers
		node* temp2 = tail->next;
		temp->next = temp2;
		tail->next = temp;
		temp->prev = tail;
		temp2->prev = temp;

		tail = temp;
	}
}