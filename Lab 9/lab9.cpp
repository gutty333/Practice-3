#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

vector <int> arrivals; // different arrival rates
int total = 0; // track of total customers for that day

// function to add people to the line
void addPeople(queue<int> & line, int size)
{
	cout << "\t" << size << " people are arriving at the store" << endl;
	for (int x = 0; x < size; x++)
	{
		line.push(1);
	}
}
void addPeople(vector < queue<int>>& lines, int size)
{
	cout << "\t" << size << " people are arriving at the store" << endl;
	for (int x = 0; x < size; x)
	{
		for (int server = 0; server < lines.size() && x < size; server++, x++)
		{
			lines[server].push(1);
		}
	}
}


// Simulation method for the single line store
/*
This will simulate a single work day
The simulation will continue until the server/s are empty in other words the line is empty
For the start people will arrive
The number of arrivals will gradually increase than decrease
At the same time, the server/s will accommodate the customers
Again this will continue until the server/s is empty.

Just note that the value 1 represents a customer
*/
int simulation(queue <int> line, int size)
{
	cout << endl << "Simulation for a store that has only one line to serve all customers" << endl;
	cout << "The line will have " << size << " server/s" << endl << endl;

	int count = 0;
	int totalPeople = size; // track total of customers currently in line
	int arrivalChoice = 0; // Will help change the number of people added during each iteration

	// starting with n arrivals where n = totalServers
	cout << "\t" << size << " people are arriving at the store" << endl;
	for (int x = 0; x < size; x++)
	{
		line.push(1);
	}

	// Area where arrivals are served and new arrivals are added
	// This will continue until empty
	while (!line.empty())
	{
		// Condition for when there are less or equal people to servers
		// Will empty the line since all the people will be served in this iteration
		if (line.size() <= size)
		{
			cout << "We have served all the people at the store" << endl;
			queue <int> emptyLine;
			line = emptyLine;

			totalPeople = 0;
		}
		else
		{
			// If there are more people
			// Than serve the customers based on the number of server/s available
			cout << "We will serve " << size << " people at the store" << endl;
			
			for (int x = 0; x < size; x++)
			{
				line.pop();
			}

			totalPeople -= size;
			cout << totalPeople << " people are still waiting to be served" << endl;
		}

		// Section to add new arrivals
		if (arrivalChoice < arrivals.size())
		{
			addPeople(line, arrivals[arrivalChoice]);
			totalPeople += arrivals[arrivalChoice];
		}
		
		cout << endl;
		arrivalChoice++;
		count++;
	}

	cout << "The store had a total of " << total << " customers today" << endl;
	cout << "The customers were served in a total of " << count << " cycle/s" << endl;
	return count;
}


// Will check the multiple line store and check if all lines are empty
bool multiLineStore(vector <queue<int>> storeLines)
{
	for (int x = 0; x < storeLines.size(); x++)
	{
		if (!storeLines[x].empty())
		{
			return false;
		}
	}
	return true;
}

// Simulation method for the multiple lines store
/*
This will also simulate a work day at a store
Difference is that when new people arrive they will be placed in separate lines
When a cycle is completed a customer will be removed from a line that is not empty 
Also some new arrivals will be added
This will continue until all lines are empty
*/
int simulation(vector <queue<int>> storeLines, int size)
{
	cout << endl <<"Simulation for a store that has multiple lines to serve all customers" << endl;
	cout << "There will be a total of " << size << " line/s at this store" << endl << endl;
	
	int count = 0;
	int totalPeople = size; // track total of customers currently in line
	int arrivalChoice = 0; // Will help change the number of people added during each iteration

	// Loop to fill the lines with starting customers which will be same as server size
	for (int x = 0; x < size; x)
	{
		for (int server = 0; server < size && x < size; server++,x++)
		{
			storeLines[server].push(1);
		}
	}
	
	while (!multiLineStore(storeLines))
	{
		// Loop to serve customer 
		// It will remove the first customer of each line 
		for (int x = 0; x < size; x++)
		{
			if (storeLines[x].empty())
			{
				continue;
			}
			else
			{
				cout << "Removing the next person in line from server " << x + 1 << endl;
				storeLines[x].pop();
				totalPeople -= 1;
			}
		}

		if (totalPeople <= 0)
		{
			cout << "We have served all the people at the store" << endl;
		}
		else
		{
			cout << totalPeople << " people are still waiting to be served" << endl;
		}
		

		// Section to add new arrivals
		if (arrivalChoice < arrivals.size())
		{
			addPeople(storeLines, arrivals[arrivalChoice]);
			totalPeople += arrivals[arrivalChoice];
		}
		
		cout << endl;
		arrivalChoice++;
		count++;
	}
	
	cout << "The store had a total of " << total << " customers today" << endl;
	cout << "The customers were served in a total of " << count << " cycle/s" << endl;
	return count;
}

int main()
{
	srand(time(0));
	int result, result2;

	cout << "How many servers are there?" << endl;
	int serverCount;
	cin >> serverCount;
	total += serverCount;

	// Will store random arrival values
	for (int x = 0; x < 5; x++)
	{
		int randomNum = rand() % (serverCount + 1);
		if (x == 0)
		{
			arrivals.push_back(2 * serverCount + randomNum);
		}
		else if (x == 1)
		{
			arrivals.push_back(3 * serverCount + randomNum);
		}
		else if (x == 2)
		{
			arrivals.push_back(serverCount / 2 + randomNum + 2);
		}
		else if (x == 3)
		{
			arrivals.push_back(serverCount - 3 - randomNum + 3);
		}
		else if (x == 4)
		{
			arrivals.push_back(serverCount + randomNum);
		}
		total += arrivals.back();
	}

	// Simulation for the single line store
	queue <int> singleLine;
	result = simulation(singleLine, serverCount);

	cout << endl;

	// Simulation for the multiple line store
	vector < queue<int> > multiLine(serverCount);
	result2 = simulation(multiLine, serverCount);

	cout << endl << endl << "Results after the simulation" << endl;
	cout << "Store with single queue took " << result << " cycles to serve all " << total << " customers" << endl;
	cout << "Store with multiple queues took " << result2 << " cycles to serves all " << total << " customers" << endl;

	return 0;
}