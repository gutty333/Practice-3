/********************************************************************
Dynamic Stack Template

In this chapter you studied DynIntStack, a class that implements a dynamic stack of
integers. Write a template that will create a dynamic stack of any data type. Demonstrate
the class with a driver program.
*********************************************************************/

#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class dynamicStack
{
private:
	node* stack;

public:
	dynamicStack();
	~dynamicStack();
	void push(int);
	void pop();
	void top();
	void print();
	bool isEmpty();
};


// constructor will set the start of the stack to null
dynamicStack::dynamicStack()
{
	stack = NULL;
}
// destructor will free up any left over nodes
dynamicStack::~dynamicStack()
{
	while (stack)
	{
		node* temp = stack;
		stack = stack->next;
		delete (temp);
	}
}
// print method will traverse the stack to print the values
void dynamicStack::print()
{

	if (isEmpty())
	{
		cout << "Nothing to print, list is empty" << endl;
	}
	else
	{
		node* current = stack;

		while (current)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
}
// is empty method
bool dynamicStack::isEmpty()
{
	if (stack == NULL)
	{
		return true;
	}
	return false;
}
// push method
void dynamicStack::push(int value)
{
	// generate a new node to add to the stack with the value passed
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;

	if (isEmpty())
	{
		stack = temp;
	}
	else
	{
		temp->next = stack;
		stack = temp;
	}
}
void dynamicStack::pop()
{
	if (isEmpty())
	{
		cout << "List is empty" << endl;
	}
	else
	{
		node* temp = stack;

		stack = stack->next;

		delete(temp);
	}
}
void dynamicStack::top()
{
	if (isEmpty())
	{
		cout << "List is empty no value to retrieve" << endl;
	}
	else
	{
		cout << "The value is " << stack->data << endl;
	}
}


int main()
{
	dynamicStack stack;

	stack.print();

	stack.push(34);
	stack.push(45);
	stack.push(5);
	stack.push(7);
	stack.push(28);
	stack.print();

	stack.top();
	stack.pop();
	stack.print();
	
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.top();
	stack.push(18);
	stack.top();


	return 0;
}