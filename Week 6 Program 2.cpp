/********************************************************************
	Simple Linked List Class

	Using an appropriate definition  of ListNode, design a simple linked list class with only two member
	functions  and a default constructor:
	void add(double x);
	boolean isMember(double x); LinkedList( );
	The add function  adds  a new node  containing  x to the  front  (head)  of the  list, while  the
	isMember function  tests to see if the list contains  a node with the value x. Test your linked
	list class by adding various numbers  to the list and then testing for membership.

	List Copy Constructor
	Modify your list class of Programming Challenge 1 to add a copy constructor. Test your class
	by making a copy of a list and then testing membership  on the copy.

	List Print
	Modify  the list class you created  in the previous  programming challenges to add  a print
	member  function.  Test the class by starting  with  an empty list, adding  some elements,  and
	then printing  the resulting list out.

	List Member Deletion
	Modify  the  list  class  you  created  in  the  previous  programming challenges  by  adding  a
	function  to remove an item from the list, and by adding a destructor:
	void remove(double x);
	~LinkedList();
	Test the class by adding by a sequence of instructions that mixes operations for adding items,
	removing items, and printing  the list.

	List Reverse
	Modify  the  list  class  you  created  in  the  previous  programming challenges  by  adding  a
	member function  for reversing the list:
	void reverse();
	The member  function  rearranges the nodes  in the list so that  their  order  is reversed.  You
	should do this without creating or destroying  nodes.

*********************************************************************/

#include <iostream>
using namespace std;


class LinkList
{
	private:
		struct Node
		{
			double value;
			Node* next;
			Node(double val, Node* nextLink = NULL)
			{
				value = val;
				next = nextLink;
			}
		};

		Node* head;

	public:
		LinkList();
		void add(double);
		bool isMember(double);
		void print();
		void remove(double);
};


// Constructor
LinkList::LinkList()
{
	head = NULL;
}
// Add method
void LinkList::add(double data)
{
	if (head == NULL)
	{
		head = new Node(data);
	}
	else
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
}
// Is member method
bool LinkList::isMember(double data)
{
	if (head == NULL)
	{
		cout << "List is empty " << endl;
		exit(1);
	}
	else
	{
		Node* temp = head;
		while (temp)
		{
			if (temp->value == data)
			{
				return 1;
			}

			temp = temp->next;
		}
	}

	return false;
}
// Print method
void LinkList::print()
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
		exit(1);
	}
	else
	{
		Node* temp = head;
		cout << endl << "Printing the list" << endl;
		while (temp)
		{
			cout << temp->value << endl;
			temp = temp->next;
		}
	}
}
// Remove method
void LinkList::remove(double data)
{
	Node* temp, *previous=NULL;

	if (head == NULL)
	{
		cout << "List is empty" << endl;
		exit(1);
	}
	else if (head->value == data)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		temp = head;

		while (temp != NULL && temp->value != data)
		{
			previous = temp;
			temp = temp->next;
		}

		if (temp)
		{
			previous->next = temp->next;
			delete temp;
		}
	}
}


int main()
{
	LinkList test;

	
	test.add(2);
	test.add(4);
	test.add(6);
	test.add(8);
	test.add(14);

	cout << test.isMember(3) << endl;
	cout << test.isMember(8) << endl;
	cout << test.isMember(4) << endl;
	cout << test.isMember(12) << endl;
	test.print();

	test.remove(8);
	test.print();

	return 0;
}