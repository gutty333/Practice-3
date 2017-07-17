#include "Tournament.h"
#include "Goblin.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "ReptilePeople.h"
#include "TheShadow.h"
#include <vector>
#include <algorithm>

// Constructor
Tournament::Tournament()
{
	teamSize = team1Score = team2Score = 0;
	team1Name = team2Name = "";
}

// Setter methods
void Tournament::setTeamSize(int s)
{
	teamSize = s;
}
void Tournament::setTeam1Name(string name)
{
	team1Name = name;
}
void Tournament::setTeam2Name(string name)
{
	team2Name = name;
}
void Tournament::updateTeam1Score()
{
	team1Score++;
}
void Tournament::updateTeam2Score()
{
	team2Score++;
}

// Getter Methods
int Tournament::getTeamSize()
{
	return teamSize;
}
int Tournament::getTeam1Score()
{
	return team1Score;
}
int Tournament::getTeam2Score()
{
	return team2Score;
}
string Tournament::getTeam1Name()
{
	return team1Name;
}
string Tournament::getTeam2Name()
{
	return team2Name;
}


// Display method
// Will showcase all the creatures that are alive from both team members
void Tournament::displayCreatures()
{
	cout << endl << "Showcasing the creatures for " << team1Name;
	team1.display();

	cout << endl << "Showcasing the creatures for " << team2Name;
	team2.display();
}


// Add Creature method
// This will populate both teams based on the teamSize
// It will prompt users to select a creature type than enter their name
void Tournament::addCreature()
{	
	Creature* selectedCreature = NULL;
	int choice;
	string name;

	int turn = 0;
	do
	{
		// Condition to determine the turn for which team will be selecting their characters
		if (turn == 0)
		{
			cout << endl <<"Please select the creatures for: " << team1Name << endl;
		}
		else if (turn == 1)
		{
			cout << endl << "Please select the creatures for: " << team2Name << endl;
		}

		// Creature selection
		for (int x = 0; x < teamSize; x++)
		{
			cout << endl << "Please select a creature type" << endl;
			cout << "1. Barbarian" << endl;
			cout << "2. Reptile People" << endl;
			cout << "3. Blue Men" << endl;
			cout << "4. Goblin" << endl;
			cout << "5. The Shadow" << endl;
			cin >> choice;
			cin.ignore();

			if (choice == 1)
			{
				selectedCreature = new Barbarian;
			}
			else if (choice == 2)
			{
				selectedCreature = new ReptilePeople;
			}
			else if (choice == 3)
			{
				selectedCreature = new BlueMen;
			}
			else if (choice == 4)
			{
				selectedCreature = new Goblin;
			}
			else if (choice == 5)
			{
				selectedCreature = new TheShadow;
			}

			// Giving the name to the creature
			cout << "Please provide a name for your " << selectedCreature->getType() << " creature" << endl;
			getline(cin, name);
			selectedCreature->setName(name);
			
			
			// Adding the selected creature into the correct team
			// Also adding the team name to the creature's stats
			if (turn == 0)
			{
				cout << "\tAdding " << name << " to your list" << endl;
				selectedCreature->setTeamName(team1Name);
				team1.add(selectedCreature);
			}
			else if (turn == 1)
			{
				cout << "\tAdding " << name << " to your list" << endl;
				selectedCreature->setTeamName(team2Name);
				team2.add(selectedCreature);
			}
		}

		turn++;
	} while (turn != 2);
}


// Simulate method
/* 
Here the creatures from each team will fight each other
After each round the winner will be moved to the back of their team line up
The loser will go to another queue which will store all the dead creatures
When a creature wins a round he will receive a point, along side its team
It will also recover some health
This process will continue until either a team looses all their members/creatures or there are 3 creatures still alive
To determine the top 3 finishers if all the members from the other team died than the top 3 will come from the winning team
We analyze to see which creature had the most points and that determines their place
If there are 3 remaining creatures split among the teams than we also analyze which have the most point
*/
void Tournament::simulation()
{
	// data to signal when there are 3 creatures left in the case they are split between teams
	/*
	For example if team size is 4 creatures per team that results in 8 creatures total
	So if we have 5 dead creature in our dead list than that signals that only 3 creatures are left
	We than end the fight simulation and analyze the placing order of the creatures based on kills
	*/
	int deadCreatureLimit = (teamSize * 2) - 3;

	while (!team1.isEmpty() && !team2.isEmpty() && deadCreatures.getSize() != deadCreatureLimit )
	{
		// Showcasing the creatures fighting this round
		cout << endl << "The creatures fighting in this round are:" << endl;
		team1.front()->printStats();
		team2.front()->printStats();

		// Have the current creatures at the front fight each other
		while (team1.front()->getAlive() && team2.front()->getAlive())
		{
			// Method to have the front creatures fight
			team1.front()->combat(team2.front());

			if (team2.front()->getAlive())
			{
				team2.front()->combat(team1.front());
			}
		}


		// Determine the winner and update the scores
		if (team1.front()->getAlive())
		{
			cout << endl <<  "The winner is " << team1.front()->getName() << endl;
			cout << "The loser is " << team2.front()->getName() << endl;
			cout << "The team " << team1Name << " will be awarded a point" << endl;

			updateTeam1Score();  // update team score
			
			// Update the kill count for that creature
			// Provide some health recovery 
			team1.front()->updateKillCount();
			team1.front()->healthRecovery();

			// Change the order
			// That includes sending the winner to the back of the line
			// Also adding the loser to the dead creature list
			Creature* temp = team1.front();
			team1.remove();
			team1.add(temp);

			temp = team2.front();
			team2.remove();
			deadCreatures.add(temp);
		}
		else
		{
			cout << endl << "The winner is " << team2.front()->getName() << endl;
			cout << "The loser is " << team1.front()->getName() << endl;
			cout << "The team " << team2Name << " will be awarded a point" << endl;

			updateTeam2Score();  // update team score

			// Update the kill count for that creature
			// Provide some health recovery 
			team2.front()->updateKillCount();
			team2.front()->healthRecovery();

			// Change the order
			// That includes sending the winner to the back of the line
			// Also adding the loser to the dead creature list
			Creature* temp = team2.front();
			team2.remove();
			team2.add(temp);

			temp = team1.front();
			team1.remove();
			deadCreatures.add(temp);
		}
	}

	// Show the winning team
	if (team1Score > team2Score)
	{
		cout << endl << "The winner of the tournament is " << team1Name << endl;
	}
	else if (team1Score < team2Score)
	{
		cout << endl << "The winner of the tournament is " << team2Name << endl;
	}
	else
	{
		cout << endl << "The tournament ended in a tie" << endl;
	}

	cout << team1Name << " got " << team1Score << " points" << endl;
	cout << team2Name << " got " << team2Score << " points" << endl;

	// Passing the creatures that are alive to a new list
	// This will make it easier to compare and find the order of the finishers
	// Again placement is based on kill count
	vector <Creature*> finisherList;
	while (!team1.isEmpty())
	{
		finisherList.push_back(team1.front());

		team1.remove();
	}
	while (!team2.isEmpty())
	{
		finisherList.push_back(team2.front());

		team2.remove();
	}

	// Sorting the list to find the top 3 finishers
	// Using a bubblesort approach
	bool swap;
	do
	{
		swap = false;

		for (int y = 0; y < finisherList.size() - 1; y++)
		{
			if (finisherList[y]->getKillCount() < finisherList[y + 1]->getKillCount())
			{
				Creature* temp = finisherList[y];
				finisherList[y] = finisherList[y + 1];
				finisherList[y + 1] = temp;
				swap = true;
			}
		}
	} while (swap);


	// Will output the top 3 finishers
	cout << endl << endl << "The top 3 finishers are:" << endl;
	int x = 0;
	for (x; x < 3; x++)
	{
		cout << "Number " << x + 1 << " ";
		finisherList[x]->printStats();
	}

	// Will output any of the creatures that did not die but did not make the top 3
	if (x < finisherList.size())
	{
		cout << endl << "Showcasing creatures that are alive after the tournament" << endl;

	}
	
	// Will output all the creatures that lost their life
	cout << endl << "The creatures that lost their life in the tournament are:" << endl;
	deadCreatures.display();
}