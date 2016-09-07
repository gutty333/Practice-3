/********************************************************************
	Sequence Sum

	A sequence of integers such as 1, 3, 5, 7, … can be represented by a function  that  takes a 
	nonnegative  integer as parameter and returns  the corresponding term of the sequence. For example, 
	the sequence of odd numbers  just cited can be represented by the function

	int odd(int k) {return 2 * k + 1;}

	Write an abstract class AbstractSeq that has a pure virtual member function

	virtual int fun(int k) = 0;

	as a stand-in  for an actual sequence, and two member functions
	void printSeq(int k, int m);
	int sumSeq(int k, int m)

	that are passed two integer parameters k and m, where k < m. The function  printSeq will print  all 
	the  terms  fun(k) through fun(m) of the  sequence,  and  likewise,  the  function sumSeq will  
	return   the  sum  of  those  terms.  Demonstrate your  AbstractSeq class  by creating  subclasses  
	that  you  use  to  sum  the  terms  of  at  least  two  different  sequences. Determine  what  
	kind of output best shows off the operation of these classes, and write a program that produces  
	that kind of output.
*********************************************************************/

#include <iostream>
using namespace std;


class AbstractSeq
{
	public:
		virtual int fun(int) = 0;
		void printSeq(int, int);
		int sumSeq(int, int);
};

class EvenSeq :public AbstractSeq
{
	public:
		virtual int fun(int);
};

class OddSeq : public AbstractSeq
{
	public:
		virtual int fun(int);
};


// Even Sequence function
int EvenSeq::fun(int x)
{
	if (x >= 0)
	{
		return 2 * x;
	}
	else
	{
		return 0;
	}
}

// Odd Sequence function
int OddSeq::fun(int x)
{
	if (x >= 0)
	{
		return 2 *x+1;
	}
	else
	{
		return 0;
	}
}

// Print sequence function
void AbstractSeq::printSeq(int x, int y)
{
	for (x; x < y; x++)
	{
		cout << fun(x) << endl;
	}
}

// Sum sequence function
int AbstractSeq::sumSeq(int x, int y)
{
	int total = 0;

	for (x; x < y; x++)
	{
		total += fun(x);
	}

	return total;
}



int main()
{
	AbstractSeq* test[2] = { new EvenSeq, new OddSeq };


	int num1, num2;

	cout << "Enter two numbers: ";
	cin >> num1 >> num2;

	cout << endl << "Even Sequence" << endl;
	test[0]->printSeq(num1, num2);
	cout << "The sum is: " << test[0]->sumSeq(num1, num2) << endl;

	cout << endl << "Odd Sequence" << endl;
	test[1]->printSeq(num1, num2);
	cout << "The sum is: " << test[1]->sumSeq(num1, num2) << endl;

	return 0;
}