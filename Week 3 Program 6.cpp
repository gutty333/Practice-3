/********************************************************************
	Corporate Sales

	A  corporation  has   six  divisions,   each   responsible   for  sales  to   different   
	geographic locations.  Design a DivSales class that  keeps sales data  for a division, with the 
	following members:

	• An array with four elements for holding four quarters of sales figures for the division
	• A private  static variable  for holding  the total  corporate sales for all divisions for the
	entire year.
	• A member  function  that  takes  four  arguments, each  assumed  to  be the  sales for  a
	quarter. The value of the arguments  should  be copied  into  the array  that  holds  the sales
	data.  The total of the four arguments  should be added to the static variable that holds the total
	yearly corporate sales.
	• A function  that takes an integer argument within the range of 0 to 3. The argument is to be used
	as a subscript  into the division quarterly sales array.  The function  should return  the value of
	the array element with that subscript.

	Write  a program that  creates  an array  of six DivSales objects.  The program should  ask the
	user to enter the sales for four quarters for each division. After the data  is entered,  the
	program should  display a table showing  the division  sales for each quarter. The program
	should then display the total corporate sales for the year.
*********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;


class DivSales
{
	private:
		double sales[4];
		static double totalSales;

	public:
		DivSales();
		void balance(double, double, double, double);
		double quarterSale(int);
		double getTotal();
};

// Static Member Definition
double DivSales::totalSales = 0;

// Constructor
DivSales::DivSales()
{
	for (int x = 0; x < 4; x++)
	{
		sales[x] = 0;
	}
}
// Balance member function
void DivSales::balance(double first, double second, double third, double fourth)
{
	sales[0] = first;
	sales[1] = second;
	sales[2] = third;
	sales[3] = fourth;

	double total = 0;
	for (int x = 0; x < 4; x++)
	{
		total += sales[x];
	}

	totalSales += total;
}
// getter function
double DivSales::getTotal()
{
	return totalSales;
}
// Quarter sale function
double DivSales::quarterSale(int quarter)
{
	if (quarter < 0 || quarter > 3)
	{
		return 0;
	}
	else
	{
		return sales[quarter];
	}
}



int main()
{

	DivSales sales[6];
	DivSales total;
	double first, second, third, fourth;

	cout << fixed << setprecision(2);

	for (int x = 0; x < 6; x++)
	{
		cout << "Division " << x + 1 << endl;
		cout << "Enter the sales for the first quarter: ";
		cin >> first;
		cout << "Enter the sales for the second quarter: ";
		cin >> second;
		cout << "Enter the sales for the third quarter: ";
		cin >> third;
		cout << "Enter the sales for the fourth quarter: ";
		cin >> fourth;

		sales[x].balance(first, second, third, fourth);
		cout << endl;
	}

	cout << endl;

	for (int x = 0; x < 6; x++)
	{
		cout << "Division " << x + 1 << " quarter sales:" << endl;

		for (int y = 0; y < 4; y++)
		{
			cout << "Sales $" << sales[x].quarterSale(y) << endl;
		}

		cout << endl;
	}

	cout << "The total corporate sales for the year is $" << total.getTotal() << endl;

	return 0;
}