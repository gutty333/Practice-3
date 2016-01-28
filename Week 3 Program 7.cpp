/********************************************************************
	Rational  Arithmetic I

	A rational number  is a quotient of two integers.  For example,  12/5,  12/–4,  –3/4, and 4/6 are 
	all rational numbers.  A rational number  is said to be in reduced form if its denominator is 
	positive and its numerator and denominator have no common  divisor other  than  1. For example,  
	the reduced  forms  of the rational numbers  given above  are 12/5,  –3/1, –3/4, and 2/3.

	Write  a class called  Rational with  a constructor Rational(int, int) that  takes  two integers,  
	a numerator and a denominator, and stores those two values in reduced  form in corresponding 
	private  members.  The  class should  have a private  member  function  void reduce() that is used 
	to accomplish  the transformation to reduced form.  The class should have an  overloaded insertion  
	operator << that  will be used  for  output of objects  of the class.



	Rational  Arithmetic II

	Modify the class Rational of Programming Challenge 8 to add overloaded operators  +, -, *, and / to
	be used for addition, subtraction, multiplication, and division. Test the class by reading and
	processing from the keyboard (or from a file) a series of rational expressions  such as
	2 / 3 + 2 / 8
	2 / 3 * – 2 / 8
	2 / 3 – 2/ 8
	2 / 3 / 2 / 8
	To facilitate  parsing  of the input,  you may assume that  numbers  and arithmetic operators
	are separated by whitespace.
*********************************************************************/
#include <iostream>
using namespace std;


class Rational
{
	private:
		int numerator;
		int denominator;
		void reduce();

	public:
		Rational(int, int);
};