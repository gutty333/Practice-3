#include <iostream>
#include <string>
using namespace std;

struct node
{
	int data;
	node* next;
};

// Stack class 
class StackList
{
	private:
		node* stack;

	public:
		StackList();
		~StackList();
		void add(int);
		int remove();
		void print();
};
// Default constructor will set head to null
StackList::StackList()
{
	stack = NULL;
}
// The destructor will destroy any node remaining in the list
StackList::~StackList()
{
	while (stack)
	{
		remove();
	}
}
// the add method for the stack
void StackList::add(int value)
{
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;

	// Simple condition if stack is empty first value will become the top node
	if (stack == NULL)
	{
		stack = temp;
	}
	else
	{
		// If stack already has elements/node than new added value will be placed at the top
		// In this case the top represents the head
		temp->next = stack;
		stack = temp;
	}
}
// remove method will delete based on the LIFO/FILO rule
int StackList::remove()
{
	if (stack == NULL)
	{
		cout << "Stack is empty" << endl;
		return -1;
	}

	node* temp = stack;

	int value = stack->data;

	// adjusting the stack to now have the second to last as our top node
	stack = stack->next;

	// freeing up memory space
	delete temp;

	return value;
}
// print method that will traverse the stack and showcase the values
void StackList::print()
{
	node* temp = stack;

	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


// Queue Class
class QueueList
{
private:
	node* head;
	node* tail;

public:
	QueueList();
	~QueueList();
	void add(int);
	int remove();
	void print();
};

// QueueList Constructor
QueueList::QueueList()
{
	head = tail = NULL;
}
// Queue Destructor
QueueList::~QueueList()
{
	while (head)
	{
		remove();
	}
}


// add method
// Note this can also be implemented with a single node pointer but utilizing 2 allow us to implement insertion in constant time
void QueueList::add(int value)
{
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;

	// If queue is empty
	if (head == NULL)
	{
		head = tail = temp;
	}
	else
	{
		// the tail pointer signifies our last node
		tail->next = temp;
		tail = temp;
	}
}
// remove method will delete based on the FIFO rule
int QueueList::remove()
{
	// Case when list is empty
	if (head == NULL)
	{
		cout << "Empty queue list" << endl;
		return -1;
	}
	else if (head == tail)
	{
		// Here is a condition for when the queue has just one node
		// We need to update both our head and tail and set them to NULL
		node* temp = head;
		int value = head->data;

		head = tail = NULL;

		delete (temp);

		return value;
	}
	else
	{
		// This condition is when the queue has more than 1 element in its list
		// We just update the head to point to the next element that was added
		node* temp = head;
		int value = head->data;

		head = head->next;

		delete (temp);

		return value;
	}
}
// print method that will traverse the queue and showcase the values
void QueueList::print()
{
	node* temp = head;

	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}





int main()
{
	StackList stack;
	QueueList queue;

	cout << "Stack Section" << endl;
	stack.add(2);
	stack.add(4);
	stack.add(6);
	stack.add(8);
	stack.add(12);
	stack.add(5);
	stack.print();
	cout << "removing " << stack.remove() << endl;
	cout << "removing " << stack.remove() << endl;
	stack.print();

	cout << endl << endl << "Queue Section" << endl;
	queue.add(34);
	queue.add(12);
	queue.add(54);
	queue.add(8);
	queue.add(25);
	queue.add(8);
	queue.print();
	cout << "removing " << queue.remove() << endl;
	cout << "removing " << queue.remove() << endl;
	queue.print();
	cout << "removing " << queue.remove() << endl;

	return 0;
}