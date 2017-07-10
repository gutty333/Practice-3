/********************************************************************
Static Queue Template

In this chapter you studied IntQueue, a class that implements a static queue of integers.
Write a template that will create a static queue of any data type. Demonstrate the class
with a driver program.
*********************************************************************/

#include <iostream>
using namespace std;

class staticQueue
{
private:
	int* queue;
	int queueSize;
	int frontIndex;
	int endIndex;
	int totalElement; // keeps track of total elements in the queue

public:
	staticQueue(int);
	~staticQueue();
	void push(int); // Also knows as enqueue
	void pop(); // Also known as dequeue
	void front();
	void print();
	bool isEmpty();
};

staticQueue::staticQueue(int size)
{
	queue = new int[size];

	queueSize = size;

	frontIndex = 0;
	endIndex =  - 1;
	totalElement = 0;
}
staticQueue::~staticQueue()
{
	delete[] queue;
}
// push method
// checks if the queue is full
// if not it advances the endIndex 
// Will also increment the number of elements inside the queue
void staticQueue::push(int value)
{
	if (totalElement == queueSize)
	{
		cout << "The queue is already full" << endl;
	}
	else
	{
		endIndex = (endIndex+1) % queueSize;
		queue[endIndex] = value;
		totalElement++;
	}
}
// pop method
// advances the frontIndex location
// will also decrease the number of elements from the queue
void staticQueue::pop()
{
	if (isEmpty())
	{
		cout << "Queue is empty nothing to remove" << endl;
	}
	else
	{
		frontIndex = (frontIndex+1)%queueSize;
		totalElement--;
	}
	
}
// isEmpty method checks if number of elements is less than or equal to 0
bool staticQueue::isEmpty()
{
	if (totalElement <= 0)
	{
		return true;
	}
	return false;
}
// front method will retrieve the first element of the list
void staticQueue::front()
{
	if (isEmpty())
	{
		cout << "nothing to retrieve the queue is empty" << endl;
	}
	else
	{
		cout << "the value is " << queue[frontIndex] << endl;
	}
}
// print method will traverse the circular dynamic array
void staticQueue::print()
{
	if (isEmpty())
	{
		cout << "Nothing to display, the queue is empty" << endl;
	}
	else
	{
		for (int x = frontIndex, total = 0; total < totalElement; x = (x + 1) % queueSize, total++)
		{
			cout << queue[x] << " ";
		}
		cout << endl;
	}
}


int main()
{
	staticQueue queue(5);

	queue.print();

	queue.push(23);
	queue.push(12);
	queue.push(5);
	queue.print();
	queue.front();
	queue.push(18);
	queue.push(36);
	queue.push(48);
	
	queue.print();
	queue.pop();
	queue.front();
	queue.pop();
	queue.print();
	queue.pop();
	queue.pop();
	queue.pop();
	
	queue.print();
	queue.pop();
	queue.push(187);
	queue.push(42);
	queue.print();
	queue.front();

	return 0;
}
