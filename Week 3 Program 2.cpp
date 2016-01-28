/********************************************************************
	Day of the Year

	Assuming that  a year has 365 days, write a class named  DayOfYear that  takes an integer 
	representing  a day of the year and translates it to a string consisting of the month  followed by 
	day of the month.  For example,
	Day 2 would be January 2
	Day 32 would be February 1
	Day 365 would be December  31.
	The constructor for the class should  take  as parameter an integer  representing  the day of the 
	year, and the class should  have a member  function  print() that  prints  the day in the month-day 
	format.  The class should  have an integer member variable to represent  the day and  should  have 
	static member  variables  of type string to assist in the translation from the integer format  to 
	the month–day format.
	Test  your  class  by  inputting various  integers  representing   days  and  printing   out  their
	representation in the month–day format.


	Day of the Year Modification

	Modify   the  DayOfYear class,  written   in  an  earlier  Programming  Challenge,   to  add  a
	constructor that  takes two parameters: a string representing  a month  and an integer  in the
	range 0 through 31 representing  the day of the month.  The constructor should then initialize the
	integer member of the class to represent the day specified by the month and day of month parameters.
	The  constructor  should   terminate  the  program  with  an  appropriate  error message if the
	number  entered for a day is outside the range of days for the month  given.
	Add the following overloaded operators:
	++ prefix and postfix increment operators. These operators should modify the DayOfYear object so that
	it represents  the next day. If the day is already  the end of the year, the new value of the
	object will represent  the first day of the year.
	--  prefix and postfix decrement operators. These operators should modify the DayOfYear
	object so that  it represents  the previous  day. If the day is already  the first day of the
	year, the new value of the object will represent  the last day of the year.
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;

class DayOfYear
{
	private:
		int day;
		static string months[];
		static int monthInt[];
		static int days[];

	public:
		DayOfYear(int);
		DayOfYear(string, int);
		void print();
};


// Static Member Definition
string DayOfYear::months[] = { "January", "February", "March", "April", "May", "June", "July", "August", 
								"September","October", "November", "December" };
int DayOfYear::monthInt[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
int DayOfYear::days[] = {	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
							11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
							21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };


DayOfYear::DayOfYear(int date)
{
	if (date < 0 || date > 365)
	{
		cout << "Enter valid input" << endl;
	}
	else
	{
		day = date;
	}
}
DayOfYear::DayOfYear(string monthName, int date);
{

	day = date;
}

void DayOfYear::print()
{
	if (day >= 1 && day <= 31)
	{
		cout << "Day " << day << " would be " << months[0] << " " << day << endl; // Jan
	}
	else if (day >= 32 && day <= 60)
	{
		cout << "Day " << day << " would be " << months[1] << " " << day - 31 << endl; // Feb
	}
	else if (day >= 61 && day <= 82)
	{
		cout << "Day " << day << " would be " << months[2] << " " << day - 60 << endl; // Mar
	}
	else if (day >= 83 && day <= 113)
	{
		cout << "Day " << day << " would be " << months[3] << " " << day - 82 << endl; // Apr
	}
	else if (day >= 114 && day <= 145)
	{
		cout << "Day " << day << " would be " << months[4] << " " << day - 113 << endl; // May
	}
	else if (day >= 146 && day <= 176)
	{
		cout << "Day " << day << " would be " << months[5] << " " << day - 145 << endl; // Jun
	}
	else if (day >= 177 && day <= 208)
	{
		cout << "Day " << day << " would be " << months[6] << " " << day - 176 << endl; // Jul
	}
	else if (day >= 209 && day <= 240)
	{
		cout << "Day " << day << " would be " << months[7] << " " << day - 208 << endl; // Aug
	}
	else if (day >= 241 && day <= 271)
	{
		cout << "Day " << day << " would be " << months[8] << " " << day - 240 << endl; // Sept
	}
	else if (day >= 271 && day <= 302)
	{
		cout << "Day " << day << " would be " << months[9] << " " << day - 270 << endl; // Oct
	}
	else if (day >= 303 && day <= 333)
	{
		cout << "Day " << day << " would be " << months[10] << " " << day - 302 << endl; // Nov
	}
	else if (day >= 334 && day <= 365)
	{
		cout << "Day " << day << " would be " << months[11] << " " << (day == 365? day - 334 : day - 333) << endl; // Dec
	}
}





int main()
{
	int number;

	do
	{
		cout << "Enter a date (-1 to exit) ";
		cin >> number;

		DayOfYear test(number);

		if (number >= 0 && number <= 365)
		{
			test.print();
		}

		cout << endl;
	} while (number != -1);


	return 0;
}
