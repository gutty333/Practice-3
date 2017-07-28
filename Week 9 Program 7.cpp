/********************************************************************
Two-Dimensional Data

Suppose that data representing a list of people and places they would like to visit is stored
in a file as follows:

3
0 Paul
1 Peter
2 David
0 3 Chicago Boston Memphis
1 1 Boston
2 0

The first number n in the file indicates how many people there are in the list. Here n is 3, so
there are 3 people. Each person in the list is assigned a number in the range 0.. n  1 that
is used to identify her. For each person, the file lists the numerical identifier of the person,
followed by the number of places the person wants to visit, followed by the names of
those places. For example, Boston is the only place that Peter cares to visit, while David
wants to visit no places.
Write a program that reads in this type of data from a file and stores it in appropriate STL
data structure. For example, you might use vectors, as well as vectors of vectors, to represent
this information. The program allows users to type in the name of a person whose list of
favorite destinations is to be printed out. The program prints an error message if the
person is not in the database.
*********************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{

}