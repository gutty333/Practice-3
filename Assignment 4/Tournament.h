#include <iostream>
#include "Creature.h"
#include "Queue.h"

#ifndef TOURNAMENT_H
#define TOURNAMENT_H

class Tournament
{
private:
	int teamSize;
	int team1Score;
	int team2Score;
	string team1Name;
	string team2Name;

	Queue team1;
	Queue team2;
	Queue deadCreatures;


public:
	Tournament();
	void setTeamSize(int);
	void setTeam1Name(string);
	void setTeam2Name(string);
	void updateTeam1Score();
	void updateTeam2Score();

	int getTeamSize();
	string getTeam1Name();
	string getTeam2Name();
	int getTeam1Score();
	int getTeam2Score();

	void addCreature();
	void displayCreatures();
	void simulation();
};

#endif