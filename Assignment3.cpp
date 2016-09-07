/********************************************************************
	Program to create a fantasy combat game

	See Assigment3.pdf file for full description of the program
*********************************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include "Creature.h"
#include "Combat.h"
#include "Barbarian.h"
#include "Reptile.h"
#include "BlueMen.h"
#include "Goblin.h"
#include "Shadow.h"
using namespace std;


int main()
{
	srand(time(0));
	string line;
	line.assign(50, '-');
	int choice;
	char choice2;
	Creature* player = 0;
	Creature* enemy = 0;
	Combat battle;


	do
	{
		cout << "Fantasy Combat Game" << endl;
		cout << line << endl;
		cout << "Please select your character: " << endl;
		cout << "\t1.Barbarian" << endl;
		cout << "\t2.Reptile People" << endl;
		cout << "\t3.Blue Men" << endl;
		cout << "\t4.Goblin" << endl;
		cout << "\t5.Shadow" << endl;
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				player = new Barbarian;
				break;
			}	

			case 2:
			{
				player = new Reptile;
				break;
			}

			case 3:
			{
				player = new BlueMen;
				break;
			}

			case 4:
			{
				player = new Goblin;
				break;
			}

			case 5:
			{
				player = new Shadow;
				break;
			}

			default:
				cout << "Invalid Input" << endl;
		}

		cout << endl << "Which character type would you like to fight?" << endl;
		cout << "\t1.Barbarian" << endl;
		cout << "\t2.Reptile People" << endl;
		cout << "\t3.Blue Men" << endl;
		cout << "\t4.Goblin" << endl;
		cout << "\t5.Shadow" << endl;
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				enemy = new Barbarian;
				break;
			}

			case 2:
			{
				enemy = new Reptile;
				break;
			}

			case 3:
			{
				enemy = new BlueMen;
				break;
			}

			case 4:
			{
				enemy = new Goblin;
				break;
			}

			case 5:
			{
				enemy = new Shadow;
				break;
			}

			default:
				cout << "Invalid Input" << endl;
		}

		cout << endl;
		battle.fight(player, enemy);

		cout << endl << "Would you like to play again? (Y/N) ";
		cin >> choice2;
		cout << endl;

		delete player;
		player = 0;
		delete enemy;
		enemy = 0;
	} while (toupper(choice2) == 'Y');
	
	cout << "Thank you for playing!" << endl;

	return 0;
}