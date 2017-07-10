/********************************************************************
Balanced Parentheses

A string of characters has balanced parentheses if each right parentheses occurring in the
string is matched with a preceding left parentheses in the same way each right brace in a
C++ program is matched with a preceding left brace. Write a program that uses a stack to
determine whether a string entered at the keyboard has balanced parentheses.
*********************************************************************/

#include <iostream>
#include <string>
#include <stack>
using namespace std;


/*
traverse the string
any opening parentheses should be store into the stack
when you reach a closing a closing tag check the top of the stack
if the current top of the stack is an opening tag, remove it from the stack
continue the repetition until the string have been fully traversed
if there are any left over values inside the stack we can declare that it is not balanced
same if when we reach a closing tag and there are no opening tag at the top of stack
*/
void balancedParentheses(string value)
{
	stack <char> list;

	for (int x = 0; x < value.length(); x++)
	{
		if (value[x] == '(')
		{
			// Adding any opening tags to the stack
			list.push(value[x]);
		}
		else if (value[x] == ')')
		{
			// Analyzing the top of the stack
			// If the current top is an opening tag, than remove and continue
			// Else this signals that the string is not balanced
			// First we check if there are any data in the stack to compare

			if (list.empty())
			{
				cout << "The string is not balanced" << endl;
				return;
			}

			if (list.top() == '(')
			{
				list.pop();
			}
			else
			{
				cout << "The string is not balanced" << endl;
				return;
			}
		}
	}

	// Check if there were any left over tags
	if (list.empty())
	{
		cout << "The string has balanced parentheses" << endl;
	}
	else
	{
		cout << "The string is not balanced" << endl;
	}
}


int main()
{
	balancedParentheses("(hello)");
	balancedParentheses("((taste)(hello))");
	balancedParentheses("(( ( (hello (nice)) ) good))");
	balancedParentheses("((hello)");
	balancedParentheses(")(hello)");
	balancedParentheses("(yes)(()(hello)");

	return 0;
}