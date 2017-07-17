#include <iostream>
#include <string>
#include <ctime>
#include "Creature.h"
#include "Goblin.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "ReptilePeople.h"
#include "TheShadow.h"
#include "Queue.h"
#include "Tournament.h"

using namespace std;

int main()
{
	srand(time(0));
	int size;
	string name;
	Tournament combatGame;

	cout << "Welcome to the tournament of power" << endl;
	cout << "How many fighters will each team have?" << endl;
	cin >> size;
	cin.ignore();

	combatGame.setTeamSize(size);

	
	cout << "Please enter a name for team 1" << endl;
	getline(cin, name);
	combatGame.setTeam1Name(name);
	cout << "Please enter a name for team 2" << endl;
	getline(cin, name);
	combatGame.setTeam2Name(name);

	// Adding fighters to both teams
	combatGame.addCreature();

	// Showcasing all the fighter before the fighting begins
	combatGame.displayCreatures();

	// Tournament Simulation
	combatGame.simulation();

	return 0;
}