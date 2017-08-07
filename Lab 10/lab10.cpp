#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/*
Important, please note that both the non recursive and recursive methods
Were taken from https://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
These two functions are part of their respective source
The use here is for educational purpose
*/

// Non recursive implementation from codeproject
long FibonacciNR(const int &n)
{
	long first = 0;
	long second = 1;
	int counter = 2;
	while (counter < n)
	{
		int temp = second;
		second = first + second;
		first = temp;
		++counter;
	}
	if (n == 0)
		return 0;
	else
		return first + second;
}

// Recursive implementation from codeproject
long FibonacciR(const int &n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return FibonacciR(n - 1) + FibonacciR(n - 2);
}



// Non tail recursive factorial. Code is from the slides
long rfactorial(int n) 
{
	if (n == 1)
		return 1;
	else
		return n * rfactorial(n - 1);
}

// Tail Recursive factorial. Code is from the slides
long factorialHelper(int n, int result) {
	if (n == 1)
		return result;
	else
		return factorialHelper(n - 1, n*result);
}
long factorial(int n) 
{
	return factorialHelper(n, 1);
}

int main()
{
	// Comparison for the 25th Fibonacci number
	clock_t start;
	start = clock();
	cout << "Iterative implementation of the 25th Fibonacci number: " << FibonacciNR(25) << endl;;
	start = clock() - start;
	cout << "It took " << start << " clicks or " << double(start) / CLOCKS_PER_SEC << " seconds" << endl;

	start = clock();
	cout << "Recursive implementation of the 25th Fibonacci number:  " << FibonacciR(25) << endl;;
	start = clock() - start;
	cout << "It took " << start << " clicks or " << double(start) / CLOCKS_PER_SEC << " seconds" << endl;

	// Comparison for the 50th Fibonacci number
	start = clock();
	cout << "Iterative implementation of the 40th Fibonacci number: " << FibonacciNR(40) << endl;;
	start = clock() - start;
	cout << "It took " << start << " clicks or " << double(start) / CLOCKS_PER_SEC << " seconds" << endl;

	start = clock();
	cout << "Recursive implementation of the 40th Fibonacci number:  " << FibonacciR(40) << endl;;
	start = clock() - start;
	cout << "It took " << start << " clicks or " << double(start) / CLOCKS_PER_SEC << " seconds" << endl;



	// Comparison for the 12th factorial number
	start = clock();
	cout << "Non-tail recursive implementation of the 12th factorial number: " << rfactorial(12) << endl;;
	start = clock() - start;
	cout << "It took " << start << " clicks or " << double(start) / CLOCKS_PER_SEC << " seconds" << endl;

	cout << "Tail recursive implementation of the 12th factorial number: " << factorial(12) << endl;;
	start = clock() - start;
	cout << "It took " << start << " clicks or " << double(start) / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;
}