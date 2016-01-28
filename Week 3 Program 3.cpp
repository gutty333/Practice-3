/********************************************************************
	Number  of Days Worked

	Design a class called NumDays. The class’s purpose  is to store  a value that  represents  a number 
	of work  hours  and convert  it to a number  of days. For example,  8 hours  would
	be converted  to 1 day, 12 hours  would  be converted  to 1.5 days, and 18 hours  would  be
	converted  to  2.25  days.  The  class should  have  a constructor that  accepts  a number  of
	hours,  as well as member functions  for storing and retrieving the hours and days. The class
	should also have the following overloaded operators:

	• The addition  operator  +.  The number  of hours  in the sum of two objects is the sum of the
	number  of hours  in the individual  objects.
	• The subtraction operator  -. The number  of hours  in the difference of two objects X
	and Y is the number  of hours  in X minus the number  of hours  in Y.
	• Prefix  and  postfix increment  operators  ++. The  number  of  hours  in  an  object  is
	incremented  by 1.
	• Prefix  and  postfix decrement  operators  --.  The  number   of  hours  in  an  object  is
	decremented by 1.
*********************************************************************/
#include <iostream>
using namespace std;


class NumDays
{
	private:
		int hour;
		double day;

	public:
		NumDays() { hour = 0; day = 0; }
		NumDays(int);
		void setHour(int);
		int getHour();
		void setDay(double);
		double getDay();
		void convert();

		friend NumDays operator+(NumDays, NumDays);
		friend NumDays operator-(NumDays, NumDays);
		NumDays operator++();
		NumDays operator--();
		NumDays operator++(int);
		NumDays operator--(int);
};


// Constructor
NumDays::NumDays(int hours)
{
	hour = hours;
}

// getter and setter member function
void NumDays::setHour(int hours)
{
	hour = hours;
}
void NumDays::setDay(double days)
{
	day = days;
}
int NumDays::getHour()
{
	return hour;
}
double NumDays::getDay()
{
	return day;
}


// Convert Member Function
void NumDays::convert()
{
	if (day == 0)
	{
		day = hour * .125;
	}
	else
	{
		hour = 8 * day;
	}
}





// Operator Overloading
NumDays operator+(NumDays a, NumDays b)
{
	return a.hour + b.hour;
}
NumDays operator-(NumDays a, NumDays b)
{
	return a.hour - b.hour;
}
NumDays NumDays::operator++()
{
	hour++;
	return *this;
}
NumDays NumDays::operator--()
{
	hour--;
	return *this;
}
NumDays NumDays::operator++(int)
{
	NumDays temp = *this;
	hour++;
	return temp;
}
NumDays NumDays::operator--(int)
{
	NumDays temp = *this;
	hour--;
	return temp;
}




int main()
{
	int hour;
	int choice;
	double days;

	do
	{
		cout << "Do you want to test with days or hours?" << endl;
		cout << "1. Hours" << endl;
		cout << "2. Days" << endl;
		cin >> choice;

		NumDays test;

		switch (choice)
		{
			case 1:
				cout << "Enter the number of work hours: (-1 to exit) ";
				cin >> hour;

				if (hour >= 0)
				{
					test.setHour(hour);
					cout << "Hours: " << test.getHour() << endl;
					test.convert();
					cout << "Day: " << test.getDay() << endl;
				}
			
				break;


			case 2:
				cout << "Enter the number of days:  (-1 to exit) ";
				cin >> days;

				if (days >= 0)
				{
					
					test.setDay(days);
					cout << "Day: " << test.getDay() << endl;
					test.convert();
					cout << "Hours: " << test.getHour() << endl;
				}

				break;


			default:
				cout << "Invalid input " << endl;
		}

		cout << endl << "Testing the operators" << endl;
		NumDays test2(8);
		NumDays test3;
		test3 = test + test2;
		cout << "Hour for test3: " << test3.getHour() << endl;

		cout << endl;
	} while (hour != -1);
	

	return 0;
}