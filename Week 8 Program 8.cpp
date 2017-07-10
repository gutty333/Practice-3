/********************************************************************
Balanced Multiple Delimiters

A string may use more than one type of delimiter to bracket information into “blocks.”
For example, A string may use braces { }, parentheses ( ), and brackets [ ] as delimiters. A
string is properly delimited if each right delimiter is matched with a preceding left delimiter
of the same type in such a way that the either the resulting blocks of information are
disjoint, or one of them is completely nested within the other. Write a program that uses a
single stack to check whether a string containing braces, parentheses, and brackets is
properly delimited.
*********************************************************************/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
Similar to the balanced parentheses we traverse the string
store any opening tags (,[,{ into the stack
When we reach a closing tag we need to analyze which delimiter it is
Than compare it to the top value in the stack
If they match correctly than pop the value  out and continue
If the delimiters do not match this signals the string is not balanced
The same will be when we finish traversing the string and there are still opening tags left in the stack
*/
void balancedDelimiter(string value)
{
	stack <char> list;

	for (int x = 0; x < value.length(); x++)
	{
		// Condition to store any opening tags into the stack
		if (value[x] == '(' || value[x] == '[' || value[x] == '{')
		{
			list.push(value[x]);
		}
		else if (value[x] == ')' || value[x] == ']' || value[x] == '}')
		{
			// Condition when we locate a closing tag
			// First make sure the stack is not empty
			// Than determine to which delimiter this belongs to
			// If the match is correct continue else string is not balanced
			if (list.empty())
			{
				cout << "The string is not balanced" << endl;
				return;
			}

			if (value[x] == ')' && list.top() == '(')
			{
				list.pop();
			}
			else if (value[x] == ']' && list.top() == '[')
			{
				list.pop();
			}
			else if (value[x] == '}' && list.top() == '{')
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

	if (list.empty())
	{
		cout << "Congratulations the string is balanced" << endl;
	}
	else
	{
		cout << "The string is not balanced" << endl;
	}
}



int main()
{
	balancedDelimiter("((hello there) [number time]{all in here{eyes}})");
	balancedDelimiter("[this is (not{the way things})[something crazy might happen]]");
	balancedDelimiter("{{{  the above and this {one should( return true)}}}}");
	balancedDelimiter("([[this one is ]]])");
	balancedDelimiter("}(now lets see){}");
	balancedDelimiter("[[{doing another(false test) here}]");
	balancedDelimiter("some more stuff{{{now that[1 23 [3234][324]})} ends now");

	return 0;
}