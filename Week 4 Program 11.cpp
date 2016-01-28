/********************************************************************
	Ancestral Trees

	Assume the following arrays are globally defined

	const string people[] = {"Al", "Beth", "Bob", "Carol", "Chuck", "Candy", "Cain", "Debbie", "Doug",
	"Diane", "Dwayne", "Delores", "Dwight"
	};
	const string mother[] = {"Beth", "Carol", "Charity", "Debbie", "Diane", "", "Delores"
	};
	const string father[] = {"Bob", "Charley", "Cain", "Douglas", "Dwayne", "", "Dwight"
	};
	const int mom[] = {1, 3, 5, 7, 9, -1, 11, -1, -1, -1, -1, -1, -1};
	const int pop[] = {2, 4, 6, 8, 10, -1, 12, -1, -1, -1, -1, -1, -1};

	The  people array  establishes  a correspondence between  a name  and  its position  in the array:
	Al is assigned the index 0, Beth is assigned the index 1, and so on. The mother and father arrays
	specify parental information. Al, who  has index  0, has Beth (mother[0]) for his mother  and Bob
	(father[0]) for his father. Similarly, the mother  and father of Beth are  Carol  and  Charley
	respectively.  The  mother  and  father  of Candy  (index  5) are  not known,  so they are
	indicated  by empty strings.

	The  mom and  pop arrays  give the  same  information in integer  rather  than  string  format.
	Values of -1 denote unknown information. For example,  the mother  of the person at index
	4 has index mom[4]= 9, and the father has index pop[4]= 10.

	The ancestral  lineage of a person is a list that begins with that person,  and includes all of his
	or her ancestors.  For  example,  the  ancestral  lineage of Al (index  0) is given by the people
	array,  while the ancestral  lineage of Cain (index 6) is Cain, Delores, Dwight.

	Write a function  void ancestors(int index) that  prints  a list of names that  comprises the
	ancestral  lineage of the person with the given index.
	the ancestral  lineage of the person with the given index.
*********************************************************************/

#include <iostream>
#include <string>
using namespace std;

const string people[] = { "Al", "Beth", "Bob", "Carol", "Chuck", "Candy", "Cain", "Debbie", "Doug",
							"Diane", "Dwayne", "Delores", "Dwight"};
const string mother[] = { "Beth", "Carol", "Charity", "Debbie", "Diane", "", "Delores"};
const string father[] = { "Bob", "Charley", "Cain", "Douglas", "Dwayne", "", "Dwight"};
const int mom[] = { 1, 3, 5, 7, 9, -1, 11, -1, -1, -1, -1, -1, -1 };
const int pop[] = { 2, 4, 6, 8, 10, -1, 12, -1, -1, -1, -1, -1, -1 };

void ancestors(int index)
{
	if (index != -1)
	{
		cout << people[index] << " <- " << people[mom[index]] << " + " << people[pop[index]] << endl;
		ancestors(mom[index]);
		ancestors(pop[index]);
	}
}

int main()
{
	ancestors(0);
	return 0;
}