// Some side practice on linked list

#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
};



//Function to find list size
int size(Node* head)
{
	Node* temp = head;
	int size = 0;

	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}

	return size;
}


int main()
{
	Node* head = new Node;

	head->value = 3;
	head->next = new Node;

	head->next->value = 6;
	head->next->next = new Node;

	head->next->next->value = 9;
	head->next->next->next = NULL;

	Node* newNode = new Node; // Creating a new node
	newNode->value = 12; // Adding value to that new node
	newNode->next = head; // Now connecting that new node to the list/head
	head = newNode; // Now here the head is the newNode

	


	cout << head->value << endl;
	cout << head->next->value << endl;
	cout << head->next->next->value << endl;
	cout << newNode->value << endl;
	cout << endl << "Size of list " << size(head) << endl;


	// The concept is quite simple
	// Drawings will be a huge help to visualize the connection of nodes
	return 0;
}
