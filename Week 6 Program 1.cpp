/********************************************************************
Using the ListNode structure introduced in this chapter,  write a function
void printFirst(ListNode *ptr)
that prints the value stored in the ﬁrst node of a list passed to it as parameter. The function
should print an error message and terminate the program if the list passed to it is empty.

Write a function
void printSecond(ListNode *ptr)
that  prints  the  value stored  in the  second  node  of a list passed  to it as parameter. The
function  should  print  an  error  message  and  terminate the  program if the  list
passed to it has less than  two nodes.

Write a function
double lastValue(ListNode *ptr)
that  returns   the  value  stored  in  the  last  node  of  a  nonempty list  passed  to  it  as
parameter. The function  should  print  an error  message and terminate the program if
the list passed to it is empty.

Write a function
ListNode *removeFirst(ListNode *ptr)
that  is passed  a linked  list as parameter, and  returns  the  tail  of the  list: that  is, it
removes  the  ﬁrst  node  and  returns  what  is left. The  function  should  deallocate  the
storage  of the  removed  node.  The  function  returns  NULL  if the  list passed  to  it is
empty.

Write a function
ListNode *ListConcat(ListNode *list1, ListNode *list2)
That  concatenates the items in list2 to the end of list1 and  returns  the resulting
list.
*********************************************************************/

#include <iostream>
using namespace std;

struct ListNode
{
	double value;
	ListNode* next;

	// Constructor
	ListNode(double val, ListNode* nextLink = NULL)
	{
		value = val;
		next = nextLink;
	}
};

// Print the first node data of a list
void printFirst(ListNode* node)
{
	if (node == NULL)
	{
		cout << "Empty list" << endl;
		return;
	}
	else
	{
		cout << node->value << endl;
	}
}

// Print the second node data of a list
void printSecond(ListNode* node)
{
	if (node == NULL)
	{
		cout << "Empty List" << endl;
		return;
	}
	else if (node->next == NULL)
	{
		cout << "List does not have 2 nodes" << endl;
		return;
	}
	else
	{
		cout << node->next->value << endl;
	}
}

// Return the last value of a list
double lastValue(ListNode* node)
{
	if (node == NULL)
	{
		cout << "Empty list" << endl;
		return 0;
	}
	

	ListNode* temp = node;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}


	return temp->value;
}

// Removes the first node of a list
ListNode* removeFirst(ListNode* node)
{
	if (node == NULL)
	{
		cout << "Empty List" << endl;
		exit(1);
	}

	ListNode* temp = node;

	node = node->next;

	delete(temp);

	return node;
}

// Concatenate function appends the list2 to the end of list1
ListNode* concate(ListNode* list1, ListNode* list2)
{
	if (list1 == NULL)
	{
		cout << "Empty list" << endl;
		exit(1);
	}

	ListNode* temp1 = list1;

	// Traverse to the end of list 1
	while (temp1->next != NULL)
	{
		temp1 = temp1->next;
	}

	temp1->next = list2;
	
	return list1;
}


int main()
{
	ListNode* node = new ListNode(2); // Create a new node
	ListNode* head = node; // Copy the new node 
	ListNode* temp = node; // Copy the new node

	node = new ListNode(4); // Create another node
	temp->next = node; // From the previous node now link to this new node
	temp = node; // Copy the new node
	node = new ListNode(6); // Repeat the steps again
	temp->next = node;
	temp = node;
	node = new ListNode(8);
	temp->next = node;
	temp = node;
	node = new ListNode(10);
	temp->next = node;
	temp = node;

	cout << "List 1" << endl;
	cout << head->value << endl;
	cout << head->next->value << endl;
	cout << head->next->next->value << endl;
	cout << head->next->next->next->value << endl;
	cout << head->next->next->next->next->value << endl;

	ListNode* head2 = new ListNode(12);
	ListNode* newNode = new ListNode(14, head2);
	head2 = newNode;
	newNode = new ListNode(16, head2);
	head2 = newNode;

	cout << endl << "List 2" << endl;
	cout << head2->value << endl;
	cout << head2->next->value << endl;
	cout << head2->next->next->value << endl;

	cout << endl << endl << "First Node ";
	printFirst(head);
	cout << "Second Node ";
	printSecond(head);
	cout << "Last Value: " << lastValue(head) << endl;
	head = removeFirst(head);
	cout << "First Node after remove ";
	printFirst(head);


	ListNode* head3 = NULL;
	head3 = concate(head, head2);
	cout << endl << endl << "First Node ";
	printFirst(head3);
	cout << "Second Node ";
	printSecond(head3);
	cout << "Last Value: " << lastValue(head) << endl;
	head3 = removeFirst(head3);
	cout << "First Node after remove ";
	printFirst(head3);

	return 0;
}