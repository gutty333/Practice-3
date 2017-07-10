/********************************************************************
Static Stack Template

In this chapter you studied IntStack, a class that implements a static stack of integers.
Write a template that will create a static stack of any data type. Demonstrate the class with
a driver program.
*********************************************************************/
#include <iostream>
using namespace std;

class staticStack
{
private:
	int* stack;
	int size;
	int topIndex;

public:
	staticStack(int);
	~staticStack();
	void push(int);
	void pop();
	void top();
	void print();
	bool isEmpty();
};

// Constructor
staticStack::staticStack(int stackSize)
{
	stack = new int[stackSize];
	size = stackSize;
	topIndex = -1;
}
// Destructor
staticStack::~staticStack()
{
	delete[]  stack;
}
// Print method
void staticStack::print()
{
	for (int x = 0; x <= topIndex; x++)
	{
		cout << stack[x] << " ";
	}
	cout << endl;
}
// Push method will add a value to the top most spot
void staticStack::push(int value)
{
	if (topIndex == size - 1)
	{
		cout << "The stack is full no more values can be added" << endl;
	}
	else
	{
		topIndex++;
		stack[topIndex] = value;
	}
}
// Pop method will remove the top most value as long as the stack is not empty
void staticStack::pop()
{
	if (isEmpty())
	{
		cout << "The stack is already empty, unable to remove any values" << endl;
	}
	else
	{
		topIndex--;
	}
}
// Top method will return the top most value
void staticStack::top()
{
	if (isEmpty())
	{
		cout << "No values are found since the stack is empty" << endl;
	}
	else
	{
		cout << "The top value is " << stack[topIndex] << endl;
	}
}
// isEmpty method
bool staticStack::isEmpty()
{
	if (topIndex == -1)
	{
		return true;
	}
	return false;
}




int main()
{
	staticStack list(5);


	list.push(3);
	list.push(7);
	list.push(12);
	list.push(23);
	list.push(47);
	list.print();

	list.push(123);
	list.print();
	list.top();
	list.pop();
	list.print();
	list.pop();
	list.top();

	list.push(64);
	list.push(87);
	list.top();
	list.print();
	list.push(345);
	

	list.pop();
	list.pop();
	list.pop();
	list.pop();
	list.pop();
	list.pop();

	list.push(11);
	list.top();
	list.pop();
	list.top();
	return 0;
}