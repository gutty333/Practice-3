/********************************************************************
Evaluating Postfix Expressions

Write a program that reads postfix expressions and prints their values. Each input
expression should be entered on its own line, and the program should terminate when
the user enters a blank line.
Assume only binary operators, and that the expressions contain no variables. Note that
you will need to use parentheses to indicate the order of application of the operators in
the expression. Here are sample input–output pairs:
78                 78
78 6 +             84
78 6 + 9 2 - /     12
*********************************************************************/

#include <iostream>
#include <string>
#include <stack>
using namespace std;


/*
traverse the string
if the character represents a number/operand store it in a string
convert the string number to an integer data type when you reach a break point
add the value into a stack
else if the character from the expression represents an operator
clear the string number, and use the specified operator to evaluate to values inside the stack
once you complete the evaluation remove the prior values from the stack and push the new evaluated result into the stack
continue this process until the expression has been fully traversed
return the leftover value from the stack
*/
void postFixEvaluation(string expression)
{
	string num=""; // use to store the number characters to later convert to an int data type

	stack <int> list;

	for (int x = 0; x < expression.length(); x++)
	{
		// If the character is a number 
		if (expression[x] >= '0' && expression[x] <= '9')
		{
			num += expression[x];
		}
		else if(expression[x] == ' ')
		{
			if (!num.empty())
			{
				// Convert string number to an integer
				int tempNum = stoi(num);

				// add the operand into the stack
				list.push(tempNum);

				// clear the string to allow us to store a new string number
				num.clear();
			}
		}
		else if (expression[x] == '+' || expression[x] == '-' || expression[x] == '*' || expression[x] == '/')
		{
			// When we reach an operator there should be 2 values stored in the stack
			// retrieve the values to evaluate them based on the specified operator
			int value2 = list.top();
			list.pop();
			int value = list.top();
			list.pop();

			// Condition to perform the evaluation and store the result into the stack
			int result;
			if (expression[x] == '+')
			{
				result = value + value2;
				list.push(result);
			}
			else if (expression[x] == '-')
			{
				result = value - value2;
				list.push(result);
			}
			else if (expression[x] == '*')
			{
				result = value * value2;
				list.push(result);
			}
			else if (expression[x] == '/')
			{
				result = value / value2; // should never be zero if the postfix is correct
				list.push(result);
			}
		}
	}

	// In the case the expression is just a number
	if (list.empty())
	{
		list.push(stoi(num));
	}


	cout << "The result of the postfix expression  " << expression << "  =  " << list.top() << endl;
}



int main()
{

	postFixEvaluation("78");
	postFixEvaluation("78 6 +");
	postFixEvaluation("78 6 + 9 2 - /");
	postFixEvaluation("5 3 + 12 * 3 /");
	postFixEvaluation("12 6 3 / 10 5 - * + 17 +");

	return 0;
}