#include <iostream>
#include <string>
#include <ctime>
#include "Creature.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Reptile.h"
#include "Goblin.h"
#include "Shadow.h"
using namespace std;

int main()
{
	srand(time(0));
	int choice;
	do
	{
		Creature* player1, *player2;
		player1 = NULL;
		player2 = NULL;

		cout << "Welcome to the battle arena" << endl;
		cout << "Please select your character type" << endl;
		cout << "1. Barbarian" << endl;
		cout << "2. Reptile" << endl;
		cout << "3. BlueMen" << endl;
		cout << "4. Goblin" << endl;
		cout << "5. Shadow" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			player1 = new Barbarian;
			break;
		case 2:
			player1 = new Reptile;
			break;
		case 3:
			player1 = new BlueMen;
			break;
		case 4:
			player1 = new Goblin;
			break;
		case 5:
			player1 = new Shadow;
			break;
		}

		int randomselect = rand() % 5 + 1;

		switch (randomselect)
		{
		case 1:
			player2 = new Barbarian;
			break;
		case 2:
			player2 = new Reptile;
			break;
		case 3:
			player2 = new BlueMen;
			break;
		case 4:
			player2 = new Goblin;
			break;
		case 5:
			player2 = new Shadow;
			break;
		}

		cout << endl << "The fight will now begin here are our fighters" << endl;
		player1->printInfo();
		cout << endl;
		player2->printInfo();

		int iterate = 0;
		while (player1->getHealth() > 0 && player2->getHealth() > 0)
		{
			cout << endl;
			if (iterate % 2 == 0)
			{
				player1->fight(player2, player1);
			}
			else
			{
				player2->fight(player1, player2);
			}
			iterate++;
		}

		if (player1->getHealth() <= 0)
		{
			cout << endl << "This fighter died" << endl;
			player1->printInfo();
		}
		else
		{
			cout << endl << "This fighter died" << endl;
			player2->printInfo();
		}

		cout << endl << "Play again (1/2)" << endl;
		cin >> choice;
	} while (choice == 1);
	
	return 0;
}